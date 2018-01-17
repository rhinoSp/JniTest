#include <jni.h>

#ifndef _CL_TOLLS_H_
#define _CL_TOLLS_H_

#define TRUE 1
#define FALSE 0

typedef unsigned char byte;
typedef unsigned char bool;


#define CLASS_OBJ_STRING "java/lang/String"
#define CLASS_OBJ_ARRAYLIST "java/util/ArrayList"

// The class name with package path.
#define CLASS_JNI_UTILES   com_rhino_jnitest_jni_utils_JniUtils

#define NAME3(CLASS3, FUNC3) Java_##CLASS3##_##FUNC3
#define NAME2(CLASS2, FUNC2) NAME3(CLASS2, FUNC2)
#define NAME(FUNC) NAME2(CLASS_JNI_UTILES, FUNC)

//define jni common interface
#define JNI_FIND_CLASS(name) (*env)->FindClass(env, name)
#define JNI_GET_OBJ_CLASS(obj) (*env)->GetObjectClass(env, obj)
#define JNI_ALLOC_OBJ(jclassz) (*env)->AllocObject(env, jclassz)
#define JNI_NEW_OBJ(jclassz, methodid, ...) (*env)->NewObject(env, jclassz, methodid, ##__VA_ARGS__)

//field id
#define JNI_GET_FIELD_ID(jclassz, name, type) (*env)->GetFieldID(env, jclassz, name, type)
#define JNI_GET_OBJ_FIELD_ID(jclassz, name) (*env)->GetFieldID(env, jclassz, name, "Ljava/lang/Object;")
#define JNI_GET_STRING_FIELD_ID(jclassz, name) (*env)->GetFieldID(env, jclassz, name, "Ljava/lang/String;")
#define JNI_GET_BYTE_FIELD_ID(jclassz, name) (*env)->GetFieldID(env, jclassz, name, "B")
#define JNI_GET_CHAR_FIELD_ID(jclassz, name) (*env)->GetFieldID(env, jclassz, name, "C")
#define JNI_GET_SHORT_FIELD_ID(jclassz, name) (*env)->GetFieldID(env, jclassz, name, "S")
#define JNI_GET_INT_FIELD_ID(jclassz, name) (*env)->GetFieldID(env, jclassz, name, "I")
#define JNI_GET_LONG_FIELD_ID(jclassz, name) (*env)->GetFieldID(env, jclassz, name, "J")
#define JNI_GET_FLOAT_FIELD_ID(jclassz, name) (*env)->GetFieldID(env, jclassz, name, "F")
#define JNI_GET_DOUBLE_FIELD_ID(jclassz, name) (*env)->GetFieldID(env, jclassz, name, "D")
#define JNI_GET_BOOLEAN_FIELD_ID(jclassz, name) (*env)->GetFieldID(env, jclassz, name, "Z")

//field value
#define JNI_GET_OBJ_FIELD_VALUE(obj, fieldid) (*env)->GetObjectField(env, obj, fieldid)
#define JNI_GET_STRING_FIELD_VALUE(obj, fieldid) (*env)->GetObjectField(env, obj, fieldid)
#define JNI_GET_BYTE_FIELD_VALUE(obj, fieldid) (*env)->GetByteField(env, obj, fieldid)
#define JNI_GET_CHAR_FIELD_VALUE(obj, fieldid) (*env)->GetCharField(env, obj, fieldid)
#define JNI_GET_SHORT_FIELD_VALUE(obj, fieldid) (*env)->GetShortField(env, obj, fieldid)
#define JNI_GET_INT_FIELD_VALUE(obj, fieldid) (*env)->GetIntField(env, obj, fieldid)
#define JNI_GET_LONG_FIELD_VALUE(obj, fieldid) (*env)->GetLongField(env, obj, fieldid)
#define JNI_GET_FLOAT_FIELD_VALUE(obj, fieldid) (*env)->GetFloatField(env, obj, fieldid)
#define JNI_GET_DOUBLE_FIELD_VALUE(obj, fieldid) (*env)->GetDoubleField(env, obj, fieldid)
#define JNI_GET_BOOLEAN_FIELD_VALUE(obj, fieldid) (*env)->GetBooleanField(env, obj, fieldid)

#define JNI_SET_STRING_FIELD_VALUE(obj, fieldid, fieldvalue) (*env)->SetObjectField(env, obj, fieldid, fieldvalue)
#define JNI_SET_BYTE_FIELD_VALUE(obj, fieldid, fieldvalue) (*env)->SetByteField(env, obj, fieldid, fieldvalue)
#define JNI_SET_CHAR_FIELD_VALUE(obj, fieldid, fieldvalue) (*env)->SetCharField(env, obj, fieldid, fieldvalue)
#define JNI_SET_SHORT_FIELD_VALUE(obj, fieldid, fieldvalue) (*env)->SetShortField(env, obj, fieldid, fieldvalue)
#define JNI_SET_INT_FIELD_VALUE(obj, fieldid, fieldvalue) (*env)->SetIntField(env, obj, fieldid, fieldvalue)
#define JNI_SET_LONG_FIELD_VALUE(obj, fieldid, fieldvalue) (*env)->SetLongField(env, obj, fieldid, fieldvalue)
#define JNI_SET_FLOAT_FIELD_VALUE(obj, fieldid, fieldvalue) (*env)->SetFloatField(env, obj, fieldid, fieldvalue)
#define JNI_SET_DOUBLE_FIELD_VALUE(obj, fieldid, fieldvalue) (*env)->SetDoubleField(env, obj, fieldid, fieldvalue)
#define JNI_SET_BOOLEAN_FIELD_VALUE(obj, fieldid, fieldvalue) (*env)->SetBooleanField(env, obj, fieldid, fieldvalue)

//method id
#define JNI_GET_METHOD_ID(jclassz, name, signature) (*env)->GetMethodID(env, jclassz, name, signature)
#define JNI_GET_STATIC_METHOD_ID(jclassz, name, signature) (*env)->GetStaticMethodID(env, jclassz, name, signature)
#define JNI_GET_CONSTRUCT_METHOD_ID(jclassz, signature) (*env)->GetMethodID(env, jclassz, "<init>", signature)

//call method
#define JNI_CALL_OBJ_METHOD(obj, methodid, ...) (*env)->CallObjectMethod(env, obj, methodid, ##__VA_ARGS__)
#define JNI_CALL_STRING_METHOD(obj, methodid, ...) (*env)->CallObjectMethod(env, obj, methodid, ##__VA_ARGS__)
#define JNI_CALL_BYTE_METHOD(obj, methodid, ...) (*env)->CallByteMethod(env, obj, methodid, ##__VA_ARGS__)
#define JNI_CALL_CHAR_METHOD(obj, methodid, ...) (*env)->CallCharMethod(env, obj, methodid, ##__VA_ARGS__)
#define JNI_CALL_SHORT_METHOD(obj, methodid, ...) (*env)->CallShortMethod(env, obj, methodid, ##__VA_ARGS__)
#define JNI_CALL_INT_METHOD(obj, methodid, ...) (*env)->CallIntMethod(env, obj, methodid, ##__VA_ARGS__)
#define JNI_CALL_FLOAT_METHOD(obj, methodid, ...) (*env)->CallFloatMethod(env, obj, methodid, ##__VA_ARGS__)
#define JNI_CALL_DOUBLE_METHOD(obj, methodid, ...) (*env)->CallDoubleMethod(env, obj, methodid, ##__VA_ARGS__)
#define JNI_CALL_BOOLEAN_METHOD(obj, methodid, ...) (*env)->CallBooleanMethod(env, obj, methodid, ##__VA_ARGS__)

#define JNI_CALL_STATIC_VOID_METHOD(obj, methodid, ...) (*env)->CallStaticVoidMethod(env, obj, methodid, ##__VA_ARGS__)

//call nonvirtual method
#define JNI_CALL_OBJ_NONVIRTUAL_METHOD(obj, jclassz, methodid, ...) (*env)->CallNonvirtualObjectMethod(env, obj, jclassz, methodid, ##__VA_ARGS__)
#define JNI_CALL_STRING_NONVIRTUAL_METHOD(obj, jclassz, methodid, ...) (*env)->CallNonvirtualObjectMethod(env, obj, jclassz, methodid, ##__VA_ARGS__)
#define JNI_CALL_BYTE_NONVIRTUAL_METHOD(obj, jclassz, methodid, ...) (*env)->CallNonvirtualByteMethod(env, obj, jclassz, methodid, ##__VA_ARGS__)
#define JNI_CALL_CHAR_NONVIRTUAL_METHOD(obj, jclassz, methodid, ...) (*env)->CallNonvirtualCharMethod(env, obj, jclassz, methodid, ##__VA_ARGS__)
#define JNI_CALL_SHORT_NONVIRTUAL_METHOD(obj, jclassz, methodid, ...) (*env)->CallNonvirtualShortMethod(env, obj, jclassz, methodid, ##__VA_ARGS__)
#define JNI_CALL_INT_NONVIRTUAL_METHOD(obj, jclassz, methodid, ...) (*env)->CallNonvirtualIntMethod(env, obj, jclassz, methodid, ##__VA_ARGS__)
#define JNI_CALL_LONG_NONVIRTUAL_METHOD(obj, jclassz, methodid, ...) (*env)->CallNonvirtualLongMethod(env, obj, jclassz, methodid, ##__VA_ARGS__)
#define JNI_CALL_FLOAT_NONVIRTUAL_METHOD(obj, jclassz, methodid, ...) (*env)->CallNonvirtualFloatMethod(env, obj, jclassz, methodid, ##__VA_ARGS__)
#define JNI_CALL_DOUBLE_NONVIRTUAL_METHOD(obj, jclassz, methodid, ...) (*env)->CallNonvirtualDoubleMethod(env, obj, jclassz, methodid, ##__VA_ARGS__)
#define JNI_CALL_BOOLEAN_NONVIRTUAL_METHOD(obj, jclassz, methodid, ...) (*env)->CallNonvirtualBooleanMethod(env, obj, jclassz, methodid, ##__VA_ARGS__)
#define JNI_CALL_VOID_NONVIRTUAL_METHOD(obj, jclassz, methodid, ...) (*env)->CallNonvirtualVoidMethod(env, obj, jclassz, methodid, ##__VA_ARGS__)

#define JNI_NEW_STRING(str, size) (*env)->NewString(env, (const jchar*)str, size)
#define JNI_NEW_STRING_UTF(str) (*env)->NewStringUTF(env, str)

#define JNI_GET_STRING(jstr) (*env)->GetStringChars(env, jstr, NULL)
#define JNI_GET_STRING_UTF(jstr) (*env)->GetStringUTFChars(env, jstr, NULL)
#define JNI_GET_STRING_LENGTH(jstr) (*env)->GetStringLength(env, jstr)
#define JNI_GET_STRING_UTF_LENGTH(jstr) (*env)->GetStringUTFLength(env, jstr)

#define JNI_RELEASE_STRING(jstr, str) (*env)->ReleaseStringChars(env, jstr, str)
#define JNI_RELEASE_STRING_UTF(jstr, str) (*env)->ReleaseStringUTFChars(env, jstr, str)

//array
//new array
#define JNI_NEW_OBJ_ARRAY(len, jclassz) (*env)->NewObjectArray(env, len, jclassz, NULL)
#define JNI_NEW_BYTE_ARRAY(len) (*env)->NewByteArray(env, len)
#define JNI_NEW_CHAR_ARRAY(len) (*env)->NewCharArray(env, len)
#define JNI_NEW_SHORT_ARRAY(len) (*env)->NewShortArray(env, len)
#define JNI_NEW_INT_ARRAY(len) (*env)->NewIntArray(env, len)
#define JNI_NEW_LONG_ARRAY(len) (*env)->NewLongArray(env, len)
#define JNI_NEW_FLOAT_ARRAY(len) (*env)->NewFloatArray(env, len)
#define JNI_NEW_DOUBLE_ARRAY(len) (*env)->NewDoubleArray(env, len)
#define JNI_NEW_BOOLEAN_ARRAY(len) (*env)->NewBooleanArray(env, len)

#define JNI_GET_ARRAY_LENGTH(arr) (*env)->GetArrayLength(env, arr)


//get elements
#define JNI_GET_OBJ_ARRAY_ELEMENT(arr, idx) (*env)->GetObjectArrayElement(env, arr, idx)
#define JNI_GET_BYTE_ARRAY_ELEMENTS(arr) (*env)->GetByteArrayElements(env, arr, NULL)
#define JNI_GET_CHAR_ARRAY_ELEMENTS(arr) (*env)->GetCharArrayElements(env, arr, NULL)
#define JNI_GET_SHORT_ARRAY_ELEMENTS(arr) (*env)->GetShortArrayElements(env, arr, NULL)
#define JNI_GET_INT_ARRAY_ELEMENTS(arr) (*env)->GetIntArrayElements(env, arr, NULL)
#define JNI_GET_LONG_ARRAY_ELEMENTS(arr) (*env)->GetLongArrayElements(env, arr, NULL)
#define JNI_GET_FLOAT_ARRAY_ELEMENTS(arr) (*env)->GetFloatArrayElements(env, arr, NULL)
#define JNI_GET_DOUBLE_ARRAY_ELEMENTS(arr) (*env)->GetDoubleArrayElements(env, arr, NULL)
#define JNI_GET_BOOLEAN_ARRAY_ELEMENTS(arr) (*env)->GetBooleanArrayElements(env, arr, NULL)

//set elements
#define JNI_SET_OBJ_ARRAY_ELEMENT(objarr, idx, obj) (*env)->SetObjectArrayElement(env, objarr, idx, obj)

//release elements
#define JNI_RELEASE_BYTE_ARRAY_ELEMENTS(arr, ptr) (*env)->ReleaseByteArrayElements(env, arr, ptr, 0)
#define JNI_RELEASE_CHAR_ARRAY_ELEMENTS(arr, ptr) (*env)->ReleaseCharArrayElements(env, arr, ptr, 0)
#define JNI_RELEASE_SHORT_ARRAY_ELEMENTS(arr, ptr) (*env)->ReleaseShortArrayElements(env, arr, ptr, 0)
#define JNI_RELEASE_INT_ARRAY_ELEMENTS(arr, ptr) (*env)->ReleaseIntArrayElements(env, arr, ptr, 0)
#define JNI_RELEASE_LONG_ARRAY_ELEMENTS(arr, ptr) (*env)->ReleaseLongArrayElements(env, arr, ptr, 0)
#define JNI_RELEASE_FLOAT_ARRAY_ELEMENTS(arr, ptr) (*env)->ReleaseFloatArrayElements(env, arr, ptr, 0)
#define JNI_RELEASE_DOUBLE_ARRAY_ELEMENTS(arr, ptr) (*env)->ReleaseDoubleArrayElements(env, arr, ptr, 0)
#define JNI_RELEASE_BOOLEAN_ARRAY_ELEMENTS(arr, ptr) (*env)->ReleaseBooleanArrayElements(env, arr, ptr, 0)

//get array region
#define JNI_GET_BYTE_ARRAY_REGION(arr, start, len, ptr) (*env)->GetByteArrayRegion(env, arr, start, len, ptr)
#define JNI_GET_CHAR_ARRAY_REGION(arr, start, len, ptr) (*env)->GetCharArrayRegion(env, arr, start, len, ptr)
#define JNI_GET_SHORT_ARRAY_REGION(arr, start, len, ptr) (*env)->GetShortArrayRegion(env, arr, start, len, ptr)
#define JNI_GET_INT_ARRAY_REGION(arr, start, len, ptr) (*env)->GetIntArrayRegion(env, arr, start, len, ptr)
#define JNI_GET_LONG_ARRAY_REGION(arr, start, len, ptr) (*env)->GetLongArrayRegion(env, arr, start, len, ptr)
#define JNI_GET_FLOAT_ARRAY_REGION(arr, start, len, ptr) (*env)->GetFloatArrayRegion(env, arr, start, len, ptr)
#define JNI_GET_DOUBLE_ARRAY_REGION(arr, start, len, ptr) (*env)->GetDoubleArrayRegion(env, arr, start, len, ptr)
#define JNI_GET_BOOLEAN_ARRAY_REGION(arr, start, len, ptr) (*env)->GetBooleanArrayRegion(env, arr, start, len, ptr)

//set array region
#define JNI_SET_BYTE_ARRAY_REGION(arr, start, len, ptr) (*env)->SetByteArrayRegion(env, arr, start, len, ptr)
#define JNI_SET_CHAR_ARRAY_REGION(arr, start, len, ptr) (*env)->SetCharArrayRegion(env, arr, start, len, ptr)
#define JNI_SET_SHORT_ARRAY_REGION(arr, start, len, ptr) (*env)->SetShortArrayRegion(env, arr, start, len, ptr)
#define JNI_SET_INT_ARRAY_REGION(arr, start, len, ptr) (*env)->SetIntArrayRegion(env, arr, start, len, ptr)
#define JNI_SET_LONG_ARRAY_REGION(arr, start, len, ptr) (*env)->SetLongArrayRegion(env, arr, start, len, ptr)
#define JNI_SET_FLOAT_ARRAY_REGION(arr, start, len, ptr) (*env)->SetFloatArrayRegion(env, arr, start, len, ptr)
#define JNI_SET_DOUBLE_ARRAY_REGION(arr, start, len, ptr) (*env)->SetDoubleArrayRegion(env, arr, start, len, ptr)
#define JNI_SET_BOOLEAN_ARRAY_REGION(arr, start, len, ptr) (*env)->SetBooleanArrayRegion(env, arr, start, len, ptr)

#define JNI_NEW_LOCAL_REF(obj) (*env)->NewLocalRef(env, obj)
#define JNI_NEW_GLOBAL_REF(obj) (*env)->NewGlobalRef(env, obj)
#define JNI_NEW_WEAK_GLOBAL_REF(obj) (*env)->NewWeakGlobalRef(env, obj)

#define JNI_DELETE_LOCAL_REF(obj) (*env)->DeleteLocalRef(env, obj)
#define JNI_DELETE_GLOBAL_REF(obj) (*env)->DeleteGlobalRef(env, obj)
#define JNI_DELETE_WEAK_GLOBAL_REF(obj) (*env)->DeleteWeakGlobalRef(env, obj)

void jniGetByte(JNIEnv *env, jobject jObj, jclass jCls, char *javaField, byte *cField);
void jniGetChar(JNIEnv *env, jobject jObj, jclass jCls, char *javaField, char *cField);
void jniGetShort(JNIEnv *env, jobject jObj, jclass jCls, char *javaField, short *cField);
void jniGetInt(JNIEnv *env, jobject jObj, jclass jCls, char *javaField, int *cField);
void jniGetLong(JNIEnv *env, jobject jObj, jclass jCls, char *javaField, long *cField);
void jniGetFloat(JNIEnv *env, jobject jObj, jclass jCls, char *javaField, float *cField);
void jniGetDouble(JNIEnv *env, jobject jObj, jclass jCls, char *javaField, double *cField);
void jniGetString(JNIEnv *env, jobject jObj, jclass jCls, char *javaField, char *cField);
void jniGetBoolean(JNIEnv *env, jobject jObj, jclass jCls, char *javaField, bool *cField);

void jniSetByte(JNIEnv *env, jobject jObj, jclass jCls, char *javaField, jbyte cField);
void jniSetChar(JNIEnv *env, jobject jObj, jclass jCls, char *javaField, jchar cField);
void jniSetShort(JNIEnv *env, jobject jObj, jclass jCls, char *javaField, jshort cField);
void jniSetInt(JNIEnv *env, jobject jObj, jclass jCls, char *javaField, jint cField);
void jniSetLong(JNIEnv *env, jobject jObj, jclass jCls, char *javaField, jlong cField);
void jniSetFloat(JNIEnv *env, jobject jObj, jclass jCls, char *javaField, jfloat cField);
void jniSetDouble(JNIEnv *env, jobject jObj, jclass jCls, char *javaField, jdouble cField);
void jniSetString(JNIEnv *env, jobject jObj, jclass jCls, char *javaField, jstring cField);
void jniSetBoolean(JNIEnv *env, jobject jObj, jclass jCls, char *javaField, jboolean cField);

#endif //_CL_TOLLS_H_
