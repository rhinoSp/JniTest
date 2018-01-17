#include <string.h>
#include "../inc/cl_tools.h"



void jniGetByte(JNIEnv *env, jobject jObj, jclass jCls, char *javaField, byte *cField) {
    *cField = JNI_GET_BYTE_FIELD_VALUE(jObj, JNI_GET_BYTE_FIELD_ID(jCls, javaField));
}
void jniGetChar(JNIEnv *env, jobject jObj, jclass jCls, char *javaField, char *cField) {
    *cField = JNI_GET_CHAR_FIELD_VALUE(jObj, JNI_GET_CHAR_FIELD_ID(jCls, javaField));
}
void jniGetShort(JNIEnv *env, jobject jObj, jclass jCls, char *javaField, short *cField) {
    *cField = JNI_GET_SHORT_FIELD_VALUE(jObj, JNI_GET_SHORT_FIELD_ID(jCls, javaField));
}
void jniGetInt(JNIEnv *env, jobject jObj, jclass jCls, char *javaField, int *cField) {
    *cField = JNI_GET_INT_FIELD_VALUE(jObj, JNI_GET_INT_FIELD_ID(jCls, javaField));
}
void jniGetLong(JNIEnv *env, jobject jObj, jclass jCls, char *javaField, long *cField) {
    *cField = JNI_GET_LONG_FIELD_VALUE(jObj, JNI_GET_LONG_FIELD_ID(jCls, javaField));
}
void jniGetFloat(JNIEnv *env, jobject jObj, jclass jCls, char *javaField, float *cField) {
    *cField = JNI_GET_FLOAT_FIELD_VALUE(jObj, JNI_GET_FLOAT_FIELD_ID(jCls, javaField));
}
void jniGetDouble(JNIEnv *env, jobject jObj, jclass jCls, char *javaField, double *cField) {
    *cField = JNI_GET_DOUBLE_FIELD_VALUE(jObj, JNI_GET_DOUBLE_FIELD_ID(jCls, javaField));
}
void jniGetString(JNIEnv *env, jobject jObj, jclass jCls, char *javaField, char *cField) {
    strcpy(cField, JNI_GET_STRING_UTF(JNI_GET_STRING_FIELD_VALUE(jObj,JNI_GET_STRING_FIELD_ID(jCls, javaField))));
}
void jniGetBoolean(JNIEnv *env, jobject jObj, jclass jCls, char *javaField, bool *cField) {
    *cField = JNI_GET_BOOLEAN_FIELD_VALUE(jObj, JNI_GET_BOOLEAN_FIELD_ID(jCls, javaField));
}


void jniSetByte(JNIEnv *env, jobject jObj, jclass jCls, char *javaField, jbyte cField) {
    JNI_SET_BYTE_FIELD_VALUE(jObj, JNI_GET_BYTE_FIELD_ID(jCls, javaField), cField);
}
void jniSetChar(JNIEnv *env, jobject jObj, jclass jCls, char *javaField, jchar cField) {
    JNI_SET_CHAR_FIELD_VALUE(jObj, JNI_GET_CHAR_FIELD_ID(jCls, javaField), cField);
}
void jniSetShort(JNIEnv *env, jobject jObj, jclass jCls, char *javaField, jshort cField) {
    JNI_SET_SHORT_FIELD_VALUE(jObj, JNI_GET_SHORT_FIELD_ID(jCls, javaField), cField);
}
void jniSetInt(JNIEnv *env, jobject jObj, jclass jCls, char *javaField, jint cField) {
    JNI_SET_INT_FIELD_VALUE(jObj, JNI_GET_INT_FIELD_ID(jCls, javaField), cField);
}
void jniSetLong(JNIEnv *env, jobject jObj, jclass jCls, char *javaField, jlong cField) {
    JNI_SET_LONG_FIELD_VALUE(jObj, JNI_GET_LONG_FIELD_ID(jCls, javaField), cField);
}
void jniSetFloat(JNIEnv *env, jobject jObj, jclass jCls, char *javaField, jfloat cField) {
    JNI_SET_FLOAT_FIELD_VALUE(jObj, JNI_GET_FLOAT_FIELD_ID(jCls, javaField), cField);
}
void jniSetDouble(JNIEnv *env, jobject jObj, jclass jCls, char *javaField, jdouble cField) {
    JNI_SET_DOUBLE_FIELD_VALUE(jObj, JNI_GET_DOUBLE_FIELD_ID(jCls, javaField), cField);
}
void jniSetString(JNIEnv *env, jobject jObj, jclass jCls, char *javaField, jstring cField) {
    JNI_SET_STRING_FIELD_VALUE(jObj, JNI_GET_STRING_FIELD_ID(jCls, javaField), cField);
}
void jniSetBoolean(JNIEnv *env, jobject jObj, jclass jCls, char *javaField, jboolean cField) {
    JNI_SET_BOOLEAN_FIELD_VALUE(jObj, JNI_GET_BOOLEAN_FIELD_ID(jCls, javaField), cField);
}


