package com.jh.jni;

/**
 * Created by admin on 2017/5/31.
 */

public class JniTest {
    public native String open();

    static {
        System.loadLibrary("jni_test");
    }
}
