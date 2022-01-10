package test;

import org.graalvm.nativeimage.IsolateThread;
import org.graalvm.nativeimage.c.function.CEntryPoint;
import org.graalvm.nativeimage.c.type.CCharPointer;
import org.graalvm.nativeimage.c.type.CTypeConversion;

public class SharedFooBar {

    static String test = "Hello worlds";

    @CEntryPoint(name="java_add")
    public static int add(IsolateThread isolate) {
      return 42;
    }

    @CEntryPoint(name="java_hello")
    public static CCharPointer hello(IsolateThread isolate) {
      try(CTypeConversion.CCharPointerHolder pointerHolder = 
        CTypeConversion.toCString(SharedFooBar.test)) {
            return pointerHolder.get();  
        }
    }
  }