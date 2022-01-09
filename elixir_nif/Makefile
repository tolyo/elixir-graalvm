ERLANG_PATH = $(shell erl -eval 'io:format("~s", [lists:concat([code:root_dir(), "/erts-", erlang:system_info(version), "/include"])])' -s init stop -noshell)

all:
	gcc -Wall -fPIC -shared -o priv/elixir_nif.so -I "$(ERLANG_PATH)" -I "c_src" c_src/elixir_nif.c c_src/hello.so

clean:
	rm  -r "priv/elixir_nif.so"
