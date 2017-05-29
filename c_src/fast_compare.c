#include "erl_nif.h"


//Erlang function definition
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

//Define which functions are exported to the BEAM VM
static ErlNifFunc nif_funcs[] = {
  {"fast_compare", 2, fast_compare}
};

//Export it to our app
//ERL_NIF_INIT(__MODULE__, ErlNifFunc* arr, void* load_func, void* upgrade_func, void* unload_func, void* reload_func)
ERL_NIF_INIT(Elixir.Niftest, nif_funcs, NULL, NULL, NULL, NULL);
