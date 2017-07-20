defmodule Niftest do
  @on_load :load_nifs
  def load_nifs do
    :erlang.load_nif("./c_lib/niftest_nif", 0)
  end

  def fast_compare(_a, _b) do
    raise "NIF fast_compare/2 not implemented"
  end

  def binary_example(_bin, _length) do
    raise "NIF binary_example/2 not implemented"
  end
end
