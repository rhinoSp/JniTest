#include "../inc/cl_tools.h"
#ifndef _CL_INIT_H_
#define _CL_INIT_H_

#define CLASS_OBJ_JNI_UTILS "com/rhino/jnitest/jni/utils/JniUtils"

#define CLASS_OBJ_APP_PARAM "com/rhino/jnitest/jni/utils/data/AppParam"
typedef struct {
    bool debug;
    int app_id;
    char app_package_name[20];
    char app_version[10];
    char app_external_store_dir[20];
    char app_private_store_dir[20];
} app_param_t;

app_param_t *app_param;
app_param_t *get_app_param();


#define CLASS_OBJ_COPY_FIELD "com/rhino/jnitest/jni/utils/data/ClassCopyField"
typedef struct {
    bool is_primitive;
    char *type;
    char *name;
} cls_copy_field_t;

#define CLASS_OBJ_COPY_INFO "com/rhino/jnitest/jni/utils/data/ClassCopyInfo"
typedef struct {
    char *name;
    cls_copy_field_t **field;
} cls_copy_info_t;


void pushEvent(JNIEnv *env, jobject obj, jint event, jint error);


#endif //_CL_INIT_H_
