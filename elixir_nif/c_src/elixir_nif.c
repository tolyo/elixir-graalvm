#include <erl_nif.h>
#include <stdio.h>
#include <stdlib.h>
#include <hello.h>

graal_isolatethread_t *isolate_thread = NULL;

static ERL_NIF_TERM hello(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
  int ret;
  graal_isolatethread_t *isolate_thread = NULL;

  graal_create_isolate(NULL, NULL, &isolate_thread);
  
  ret = java_add(isolate_thread);
  
  graal_tear_down_isolate(isolate_thread);
  
  return enif_make_int(env, ret);
}

static ERL_NIF_TERM greet(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
  
  if (isolate_thread == NULL) {
    graal_create_isolate(NULL, NULL, &isolate_thread);
  }
  
  const char* res = java_hello(isolate_thread);
  
  return enif_make_string(env, res, ERL_NIF_LATIN1);
}

static ErlNifFunc nif_funcs[] =
{
    {"hello", 0, hello},
    {"greet", 0, greet}
};

ERL_NIF_INIT(Elixir.ElixirNif,nif_funcs,NULL,NULL,NULL,NULL)