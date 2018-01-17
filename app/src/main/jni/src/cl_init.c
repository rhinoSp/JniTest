#include <jni.h>
#include <inc/cl_init.h>
#include "../inc/cl_init.h"
#include "../inc/cl_tools.h"
#include "../inc/cl_log.h"

extern app_param_t *app_param;

/**
 * Init app param.
 */
int NAME(init)(JNIEnv *env, jobject obj, jobject jobj) {

    app_param = malloc(sizeof(app_param_t));
    jclass jcls = JNI_FIND_CLASS(CLASS_OBJ_APP_PARAM);

    jniGetBoolean(env, jobj, jcls, "mDebug", &app_param->debug);
    jniGetInt(env, jobj, jcls, "mAppId", &app_param->app_id);
    jniGetString(env, jobj, jcls, "mAppPackageName", app_param->app_package_name);
    jniGetString(env, jobj, jcls, "mAppVersion", app_param->app_version);
    jniGetString(env, jobj, jcls, "mAppExternalStoreDir", app_param->app_external_store_dir);
    jniGetString(env, jobj, jcls, "mAppPrivateStoreDir", app_param->app_private_store_dir);

    LOGD("app_param->debug = %d", app_param->debug);
    LOGD("app_param->app_id = %d", app_param->app_id);
    LOGD("app_param->app_package_name = %s", app_param->app_package_name);
    LOGD("app_param->app_version = %s", app_param->app_version);
    LOGD("app_param->app_external_store_dir = %s", app_param->app_external_store_dir);
    LOGD("app_param->app_private_store_dir = %s", app_param->app_private_store_dir);

    return 0;
}

/**
 * Get the app param.
 */
app_param_t *get_app_param() {
    return app_param;
}

/**
 * Register teh copy class List.
 */
int NAME(jniRegisterCopyClass)(JNIEnv *env, jobject obj, jobject copyClsObj) {
    jclass cls_arraylist = JNI_GET_OBJ_CLASS(copyClsObj);
    jmethodID arraylist_get = JNI_GET_METHOD_ID(cls_arraylist, "get", "(I)Ljava/lang/Object;");
    jmethodID arraylist_size = JNI_GET_METHOD_ID(cls_arraylist, "size", "()I");
    jint len = JNI_CALL_INT_METHOD(copyClsObj, arraylist_size);
    int i, j;

    cls_copy_info_t **infos = malloc(len * sizeof(cls_copy_info_t));
    jclass info_cls = JNI_FIND_CLASS(CLASS_OBJ_COPY_INFO);
    for (i = 0; i < len; i++) {
        jobject info_obj = JNI_CALL_OBJ_METHOD(copyClsObj, arraylist_get, i);
        cls_copy_info_t *info = malloc(sizeof(cls_copy_info_t));

        info->name = malloc(100);
        jniGetString(env, info_obj, info_cls, "mName", info->name);
        LOGD("info->name = %s", info->name);

        jfieldID field_id = JNI_GET_FIELD_ID(info_cls, "mFields", "Ljava/util/ArrayList;");
        jobject fields_obj = JNI_GET_OBJ_FIELD_VALUE(info_obj, field_id);
        jclass filed_cls = JNI_FIND_CLASS(CLASS_OBJ_COPY_FIELD);
        jint field_len = JNI_CALL_INT_METHOD(fields_obj, arraylist_size);
        info->field = malloc(field_len * sizeof(cls_copy_field_t));

        for (j = 0; j < field_len; j++) {
            jobject filed_obj = JNI_CALL_OBJ_METHOD(fields_obj, arraylist_get, j);
            cls_copy_field_t *filed = malloc(sizeof(cls_copy_field_t));
            jniGetBoolean(env, filed_obj, filed_cls, "mIsPrimitive", &filed->is_primitive);
            LOGD("filed->is_primitive = %d", filed->is_primitive);

            filed->type = malloc(100);
            jniGetString(env, filed_obj, filed_cls, "mType", filed->type);
            LOGD("filed->type = %s", filed->type);

            filed->name = malloc(100);
            jniGetString(env, filed_obj, filed_cls, "mName", filed->name);
            LOGD("filed->name = %s", filed->name);

            info->field[j] = filed;
        }
        infos[i] = info;
    }

    pushEvent(env, obj, 1, 0);
    return 0;
}

/**
 * Push event to java.
 */
void pushEvent(JNIEnv *env, jobject obj, jint event, jint error) {
    jclass cls = JNI_FIND_CLASS(CLASS_OBJ_JNI_UTILS);
    jmethodID id = JNI_GET_STATIC_METHOD_ID(cls, "pushEvent", "(II)V");
    JNI_CALL_STATIC_VOID_METHOD(obj, id, event, error);
}

/* 
 * This function will be call when the library first be load.
 * You can do some init in the library. return which version jni it support.
 */
jint JNI_OnLoad(JavaVM *vm, void *reserved) {
    LOGI("Java called loadLibrary.");
    void *venv;
    if ((*vm)->GetEnv(vm, (void **) &venv, JNI_VERSION_1_4) != JNI_OK) {
        LOGE("ERROR: GetEnv failed.");
        return -1;
    }
    return JNI_VERSION_1_4;
}