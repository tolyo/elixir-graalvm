package test;

import org.graalvm.nativeimage.IsolateThread;
import org.graalvm.nativeimage.c.function.CEntryPoint;

public class SharedFooBar {
    @CEntryPoint
    public static int add(IsolateThread isolate) {
      return 42;
    }
  }