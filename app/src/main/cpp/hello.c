#include <jni.h>

jstring
Java_com_hhbgk_hellocmake_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject this) {
    const char *const hello = "Hello cmake!";
    return (*env)->NewStringUTF(env, hello);
}
