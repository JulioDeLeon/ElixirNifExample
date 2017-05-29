defmodule Mix.Tasks.Compile.CustomNifs do
  def run(_args) do
    {result, _errcode} = System.cmd("make", [], stderr_to_stdout: true)
    IO.binwrite(result)
  end
end

defmodule Niftest.Mixfile do
  use Mix.Project

  def project do
    [app: :niftest,
     compilers: [:custom_nifs] ++ Mix.compilers,
     version: "0.1.0",
     elixir: "~> 1.4",
     build_embedded: Mix.env == :prod,
     start_permanent: Mix.env == :prod,
     deps: deps()]
  end

  # Configuration for the OTP application
  #
  # Type "mix help compile.app" for more information
  def application do
    # Specify extra applications you'll use from Erlang/Elixir
    [extra_applications: [:logger]]
  end

  # Dependencies can be Hex packages:
  #
  #   {:my_dep, "~> 0.3.0"}
  #
  # Or git/path repositories:
  #
  #   {:my_dep, git: "https://github.com/elixir-lang/my_dep.git", tag: "0.1.0"}
  #
  # Type "mix help deps" for more examples and options
  defp deps do
    []
  end
end
