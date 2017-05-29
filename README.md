# Niftest

**TODO: Add description**

## Installation

If [available in Hex](https://hex.pm/docs/publish), the package can be installed
by adding `niftest` to your list of dependencies in `mix.exs`:

```elixir
def deps do
  [{:niftest, "~> 0.1.0"}]
end
```

Documentation can be generated with [ExDoc](https://github.com/elixir-lang/ex_doc)
and published on [HexDocs](https://hexdocs.pm). Once published, the docs can
be found at [https://hexdocs.pm/niftest](https://hexdocs.pm/niftest).


This project contains an example of a NIF for elixir.
http://andrealeopardi.com/posts/using-c-from-elixir-with-nifs/

To compile the c code to a .so file:
$ cc -fPIC -I$(ERL_INCLUDE_PATH) \
-dynamiclib -undefined dynamic_lookup \ 
-o fast_compare.so fast_compare.c
