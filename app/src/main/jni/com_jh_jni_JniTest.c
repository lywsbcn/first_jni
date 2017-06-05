//
// Created by admin on 2017/5/31.
//

#include "com_jh_jni_JniTest.h"

JNIEXPORT jstring JNICALL Java_com_jh_jni_JniTest_open
  (JNIEnv *env, jobject obj){
    return (*env)->NewStringUTF(env,"for test");
  }