#include "erl_nif.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static ERL_NIF_TERM
fast_compare(ErlNifEnv *env, int argc, const ERL_NIF_TERM argv[]) {
  //read the Int passed from erlang/elixir to Int in C
  int a, b;
  enif_get_int(env, argv[0], &a);
  enif_get_int(env, argv[1], &b);

  //convert C's Int to erlang/elixir's Int and send back
  int result = a == b ? 0 : (a > b ? 1 : -1);
  return enif_make_int(env, result);
}

static ERL_NIF_TERM
binary_example(ErlNifEnv *env, int argc, const ERL_NIF_TERM argv[]) {
  //load the passed binary
  int binary_size;
  ErlNifBinary temp_bin;
  if( !enif_get_int(env, argv[1], &binary_size)
      || !enif_inspect_binary(env, argv[0], &temp_bin)) {
    return enif_make_badarg(env);
  }

  //TODO: create and ip and port for the passed binary
  for(int x = 0; x < binary_size; x++) {
    printf("%d:%c\n", x, temp_bin.data[x]);
  }

  //return tuple {ip, port}
  ERL_NIF_TERM retIP = enif_make_string(env, "temp", ERL_NIF_LATIN1);
  ERL_NIF_TERM retPort = enif_make_uint(env, 0);
  return enif_make_tuple(env, 2, retIP, retPort);
}


static ErlNifFunc nif_funcs[] = {
  {"fast_compare", 2, fast_compare},
  {"binary_example", 2, binary_example}
};

ERL_NIF_INIT(Elixir.Niftest, nif_funcs, NULL, NULL, NULL, NULL);
