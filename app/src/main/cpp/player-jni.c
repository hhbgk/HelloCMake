//
// Created by huanghaibo on 2018/12/16.
//

#include <jni.h>
#include <pthread.h>
#include <unistd.h>
#include <malloc.h>
#include "player-jni.h"
#include "log.h"
#include "codec/player.h"

#define CLASS_PATH "com/hhbgk/hellocmake/impl/Player"

#define NELEM(x) ((int) (sizeof(x) / sizeof((x)[0])))

#define tag "player-jni"
static pthread_key_t key;
static int gHello;
static jboolean jni_init(JNIEnv *env, jobject thiz)
{
    logi(tag, "%s:%lx", __func__, pthread_self());
    return JNI_TRUE;
}

static jboolean jni_create(JNIEnv *env, jobject thiz, jint jport, jstring jip)
{
    logi(tag, "%s: port=%d", __func__, jport);
    if (jip)
    {
        const char *ip = (*env)->GetStringUTFChars(env, jip, NULL);
        if (ip)
        {
            loge(tag, "ip=%s", ip);
        }

        (*env)->ReleaseStringUTFChars(env, jip, ip);
    }
    player_t *player = calloc(1, sizeof(player_t));
    player->state = jport;
    player_create();
    logw(tag, "tid=%lx", player->tid);
//    pthread_join(player->tid, NULL);
//    pthread_key_delete(key);
//    if (player) free(player);
    loge(tag, "%s: end", __func__);
    return JNI_TRUE;
}
static jboolean jni_close(JNIEnv *env, jobject thiz)
{
    player_close();
    return JNI_TRUE;
}
static JNINativeMethod g_methods[] =
        {
                {"nativeInit", "()Z", (void *) jni_init},
                {"nativeCreate", "(ILjava/lang/String;)Z", (void*) jni_create},
                {"nativeClose", "()Z", (void*) jni_close},
        };
JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved)
{
    loge(tag, "%s", __func__);
    JNIEnv *env = NULL;
    if ((*vm)->GetEnv(vm, (void **) &env, JNI_VERSION_1_6) != JNI_OK)
    {
        loge(tag, "GetEnv failed!");
        return JNI_ERR;
    }
    jclass klass = (*env)->FindClass(env, CLASS_PATH);
    if (klass == NULL){
        return JNI_ERR;
    }
    (*env)->RegisterNatives(env, klass, g_methods, NELEM(g_methods));
    return JNI_VERSION_1_6;
}
JNIEXPORT void JNI_OnUnload(JavaVM* vm, void* reserved)
{
    loge(tag, "%s", __func__);
}