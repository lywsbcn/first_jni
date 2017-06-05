# 在Android Studio运行第一个NDK程序

在Android Studio运行第一个NDK程序	

1 新建一个 java 文件 
 
2.添加本地化 方法  public native String getCString();
 
3.在activity中添加
JniJava j=new JniJava();
Toast.makeText(this, j.getCString(), Toast.LENGTH_SHORT).show();
弹出 获取的文字信息,说明调用成功!!

 
4. 运行一次Make Project,获取到中间文件
 

生成的文件在 app\build\intermediates\classes\debug
 
5.打开 terminal cd app\build\intermediates\classes\debug
 
6.执行命令  javah -jni com.jh.jni.JniJava,后生成 com_jh_jni-JniJava.h文件
 

7.在src \main 添加文件夹 jni
 

8.把上面生成的文件 com_jh_jni-JniJava.h 复制到 jni中

 
9.在jni 目录中添加一个 c 文件 名字随意 这里是 jnic.c 

 
10.jnic.c 文件中添加如下内容

#include "com_jh_jni_JniJava.h"

JNIEXPORT jstring JNICALL Java_com_jh_jni_JniJava_getCString
  (JNIEnv * env, jobject obj){
    return (*env)->NewStringUTF(env,"This just a test for Android Studio NDK JNI developer!");
  }



11.接下来 在 app\app.gradle 中设置库文件名(生成so文件名)

defaultConfig {
    ......
    ndk{
        moduleName "JniSo"         //生成的so名字
        abiFilters "armeabi", "armeabi-v7a", "x86"  //输出指定三种abi体系结构下的so库。目前可有可无。
    }
}


别忘了同步一下.

12.在gradle.properties中添加  android.useDeprecatedNdk=true
 
12.去 代码 JniJava.java 文件添加 静态初始化load代码,

static {
    System.loadLibrary("JniSo");
}
 
再运行一次Make Project 没有错误的话就可以生成so 文件了
 app\build\intermediates\ndk\debug\lib\
 

13 .在 src\main 中创建 jniLibs 文件夹
把上面lib中的3个文件夹都复制到jniLibs中
把 Android.mk 复制到 src\main\jni 文件中
 


运行.搞定

