#ifndef __C_SRC_HELLO_H
#define __C_SRC_HELLO_H

#include <graal_isolate_dynamic.h>


#if defined(__cplusplus)
extern "C" {
#endif

typedef int (*java_add_fn_t)(graal_isolatethread_t*);

typedef char* (*java_hello_fn_t)(graal_isolatethread_t*);

typedef void (*vmLocatorSymbol_fn_t)(graal_isolatethread_t* thread);

#if defined(__cplusplus)
}
#endif
#endif
