#ifndef __C_SRC_HELLO_H
#define __C_SRC_HELLO_H

#include <graal_isolate.h>


#if defined(__cplusplus)
extern "C" {
#endif

int java_add(graal_isolatethread_t*);

char* java_hello(graal_isolatethread_t*);

void vmLocatorSymbol(graal_isolatethread_t* thread);

#if defined(__cplusplus)
}
#endif
#endif
