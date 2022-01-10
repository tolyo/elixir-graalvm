defmodule ElixirNif do
  @on_load :load_nif

  def load_nif do
    nif = Application.app_dir(:elixir_nif, "priv/elixir_nif")
    :ok = :erlang.load_nif(String.to_charlist(nif), 0)
  end

  def hello do
    raise "Fail"
  end

  def greet do
    raise "Fail"
  end
end
