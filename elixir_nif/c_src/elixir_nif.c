#include <erl_nif.h>
#include <stdio.h>
#include <stdlib.h>
#include <hello.h>

static ERL_NIF_TERM hello(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
  int ret;
  graal_isolatethread_t *isolate_thread = NULL;

  graal_create_isolate(NULL, NULL, &isolate_thread);
  
  ret = SharedFooBar__add__7150f550e431bb268c9dbc2717da6903b89463bc(isolate_thread);
  printf("result: %d\n", ret);

  graal_tear_down_isolate(isolate_thread);
  
  return enif_make_int(env, ret);
}

static ErlNifFunc nif_funcs[] =
{
    {"hello", 0, hello}
};

ERL_NIF_INIT(Elixir.ElixirNif,nif_funcs,NULL,NULL,NULL,NULL)