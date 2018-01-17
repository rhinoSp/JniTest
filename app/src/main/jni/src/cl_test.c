#include <inc/cl_init.h>
#include "../inc/cl_tools.h"
#include "../inc/cl_log.h"
#include "../inc/cl_init.h"

// The class name with package path.
#define CLASS_JNI_TEST   com_rhino_jnitest_jni_test_JniTest
#define JNI_TEST_NAME(FUNC)   NAME2(CLASS_JNI_TEST, FUNC)

#define CLASS_TEST_OBJ_PARAM "com/rhino/jnitest/jni/test/data/JniTestParam"
typedef struct {
    bool bool_filed;
    byte b_filed;
    char c_filed;
    short s_filed;
    int i_filed;
    long l_filed;
    float f_filed;
    double d_filed;
    char *str_filed;
} test_param_t;


int JNI_TEST_NAME(jniTestSetBoolean)(JNIEnv *env, jobject obj, jboolean inputBoolean) {
    LOGD("input boolean: %d", inputBoolean);

    LOGD("get_app_param()->debug = %d", get_app_param()->debug);
    LOGD("get_app_param()->app_id = %d", get_app_param()->app_id);
    LOGD("get_app_param()->app_package_name = %s", get_app_param()->app_package_name);
    LOGD("get_app_param()->app_version = %s", get_app_param()->app_version);
    LOGD("get_app_param()->app_external_store_dir = %s", get_app_param()->app_external_store_dir);
    LOGD("get_app_param()->app_private_store_dir = %s", get_app_param()->app_private_store_dir);

    return 0;
}

int JNI_TEST_NAME(jniTestSetByte)(JNIEnv *env, jobject obj, jbyte inputByte) {
    LOGD("input byte: %d", inputByte);
    return 0;
}

int JNI_TEST_NAME(jniTestSetChar)(JNIEnv *env, jobject obj, jchar inputChar) {
    LOGD("input char: %d", inputChar);
    return 0;
}

int JNI_TEST_NAME(jniTestSetShort)(JNIEnv *env, jobject obj, jshort inputShort) {
    LOGD("input short: %d", inputShort);
    return 0;
}

int JNI_TEST_NAME(jniTestSetInt)(JNIEnv *env, jobject obj, jint inputInt) {
    LOGD("input int: %d", inputInt);
    return 0;
}

int JNI_TEST_NAME(jniTestSetLong)(JNIEnv *env, jobject obj, jlong inputLong) {
    LOGD("input long: %ld", inputLong);
    return 0;
}

int JNI_TEST_NAME(jniTestSetFloat)(JNIEnv *env, jobject obj, jfloat inputFloat) {
    LOGD("input float: %f", inputFloat);
    return 0;
}

int JNI_TEST_NAME(jniTestSetDouble)(JNIEnv *env, jobject obj, jdouble inputDouble) {
    LOGD("input double: %f", inputDouble);
    return 0;
}

int JNI_TEST_NAME(jniTestSetString)(JNIEnv *env, jobject obj, jstring inputStr) {

    // 从 inputStr 字符串取得指向字符串 UTF 编码的指针
    const char *str = JNI_GET_STRING_UTF(inputStr);
    LOGD("input string: %s", (const char *) str);

    // 通知虚拟机本地代码不再需要通过 str 访问 Java 字符串。
    JNI_RELEASE_STRING_UTF(inputStr, str);
    return 0;
}

int JNI_TEST_NAME(jniTestSetObj)(JNIEnv *env, jobject obj, jobject inputObj) {

    test_param_t *test_param = malloc(sizeof(test_param_t));

    jclass jcls = JNI_FIND_CLASS(CLASS_TEST_OBJ_PARAM);

    jniGetBoolean(env, inputObj, jcls, "bool_filed", &test_param->bool_filed);
    jniGetByte(env, inputObj, jcls, "b_filed", &test_param->b_filed);
    jniGetChar(env, inputObj, jcls, "c_filed", &test_param->c_filed);
    jniGetShort(env, inputObj, jcls, "s_filed", &test_param->s_filed);
    jniGetInt(env, inputObj, jcls, "i_filed", &test_param->i_filed);
    jniGetLong(env, inputObj, jcls, "l_filed", &test_param->l_filed);
    jniGetFloat(env, inputObj, jcls, "f_filed", &test_param->f_filed);
    jniGetDouble(env, inputObj, jcls, "d_filed", &test_param->d_filed);

    test_param->str_filed = malloc(100);
    jniGetString(env, inputObj, jcls, "str_filed", test_param->str_filed);

    LOGD("test_param->bool_filed = %d", test_param->bool_filed);
    LOGD("test_param->b_filed = %d", test_param->b_filed);
    LOGD("test_param->c_filed = %d", test_param->c_filed);
    LOGD("test_param->s_filed = %d", test_param->s_filed);
    LOGD("test_param->i_filed = %d", test_param->i_filed);
    LOGD("test_param->l_filed = %ld", test_param->l_filed);
    LOGD("test_param->f_filed = %f", test_param->f_filed);
    LOGD("test_param->d_filed = %f", test_param->d_filed);
    LOGD("test_param->d_filed = %s", test_param->str_filed);
    return 0;

}

int JNI_TEST_NAME(jniTestSetBooleanArray)(JNIEnv *env, jobject obj, jbooleanArray inputBoolean) {
    jboolean *pba = JNI_GET_BOOLEAN_ARRAY_ELEMENTS(inputBoolean);
    jsize len = JNI_GET_ARRAY_LENGTH(inputBoolean);
    int i = 0;
    for (i = 0; i < len; i++) {
        LOGD("boolean = %s\n", (pba[i] ? "true" : "false"));
    }
    JNI_RELEASE_BOOLEAN_ARRAY_ELEMENTS(inputBoolean, pba);
    return 0;
}

int JNI_TEST_NAME(jniTestSetByteArray)(JNIEnv *env, jobject obj, jbyteArray inputByte) {
    jbyte *pba = JNI_GET_BYTE_ARRAY_ELEMENTS(inputByte);
    jsize len = JNI_GET_ARRAY_LENGTH(inputByte);
    int i = 0;
    for (i = 0; i < len; i++) {
        LOGD("inputByte = %d\n", pba[i]);
    }
    JNI_RELEASE_BYTE_ARRAY_ELEMENTS(inputByte, pba);
    return 0;
}

int JNI_TEST_NAME(jniTestSetCharArray)(JNIEnv *env, jobject obj, jcharArray inputChar) {
    jchar *pba = JNI_GET_CHAR_ARRAY_ELEMENTS(inputChar);
    jsize len = JNI_GET_ARRAY_LENGTH(inputChar);
    int i = 0;
    for (i = 0; i < len; i++) {
        LOGD("inputChar = %d\n", pba[i]);
    }
    JNI_RELEASE_CHAR_ARRAY_ELEMENTS(inputChar, pba);
    return 0;
}

int JNI_TEST_NAME(jniTestSetShortArray)(JNIEnv *env, jobject obj, jshortArray inputShort) {
    jshort *pba = JNI_GET_SHORT_ARRAY_ELEMENTS(inputShort);
    jsize len = JNI_GET_ARRAY_LENGTH(inputShort);
    int i = 0;
    for (i = 0; i < len; i++) {
        LOGD("inputShort = %d\n", pba[i]);
    }
    JNI_RELEASE_SHORT_ARRAY_ELEMENTS(inputShort, pba);
    return 0;
}

int JNI_TEST_NAME(jniTestSetIntArray)(JNIEnv *env, jobject obj, jintArray inputInt) {
    jint *pba = JNI_GET_INT_ARRAY_ELEMENTS(inputInt);
    jsize len = JNI_GET_ARRAY_LENGTH(inputInt);
    int i = 0;
    for (i = 0; i < len; i++) {
        LOGD("inputInt = %d\n", pba[i]);
    }
    JNI_RELEASE_INT_ARRAY_ELEMENTS(inputInt, pba);
    return 0;
}

int JNI_TEST_NAME(jniTestSetLongArray)(JNIEnv *env, jobject obj, jlongArray inputLong) {
    jlong *pba = JNI_GET_LONG_ARRAY_ELEMENTS(inputLong);
    jsize len = JNI_GET_ARRAY_LENGTH(inputLong);
    int i = 0;
    for (i = 0; i < len; i++) {
        LOGD("inputLong = %ld\n", pba[i]);
    }
    JNI_RELEASE_LONG_ARRAY_ELEMENTS(inputLong, pba);
    return 0;
}

int JNI_TEST_NAME(jniTestSetFloatArray)(JNIEnv *env, jobject obj, jfloatArray inputFloat) {
    jfloat *pba = JNI_GET_FLOAT_ARRAY_ELEMENTS(inputFloat);
    jsize len = JNI_GET_ARRAY_LENGTH(inputFloat);
    int i = 0;
    for (i = 0; i < len; i++) {
        LOGD("inputFloat = %f\n", pba[i]);
    }
    JNI_RELEASE_FLOAT_ARRAY_ELEMENTS(inputFloat, pba);
    return 0;
}

int JNI_TEST_NAME(jniTestSetDoubleArray)(JNIEnv *env, jobject obj, jdoubleArray inputDouble) {
    jdouble *pba = JNI_GET_DOUBLE_ARRAY_ELEMENTS(inputDouble);
    jsize len = JNI_GET_ARRAY_LENGTH(inputDouble);
    int i = 0;
    for (i = 0; i < len; i++) {
        LOGD("inputDouble = %f\n", pba[i]);
    }
    JNI_RELEASE_DOUBLE_ARRAY_ELEMENTS(inputDouble, pba);
    return 0;
}

int JNI_TEST_NAME(jniTestSetStringArray)(JNIEnv *env, jobject obj, jobjectArray inputString) {
    jsize len = JNI_GET_ARRAY_LENGTH(inputString);
    int i = 0;
    jstring pba;
    for (i = 0; i < len; i++) {
        pba = JNI_GET_OBJ_ARRAY_ELEMENT(inputString, i);
        const char *str = JNI_GET_STRING_UTF(pba);
        LOGD("inputString = %s\n", (const char *) str);
    }
    JNI_RELEASE_DOUBLE_ARRAY_ELEMENTS(inputString, pba);
    return 0;
}

int JNI_TEST_NAME(jniTestSetStringArrayList)(JNIEnv *env, jobject obj, jobject inputStringArrayList) {
    jclass cls_arraylist = JNI_GET_OBJ_CLASS(inputStringArrayList);
    jmethodID arraylist_get = JNI_GET_METHOD_ID(cls_arraylist, "get", "(I)Ljava/lang/Object;");
    jmethodID arraylist_size = JNI_GET_METHOD_ID(cls_arraylist, "size", "()I");
    jint len = JNI_CALL_INT_METHOD(inputStringArrayList, arraylist_size);
    int i;
    for(i = 0; i < len; i++){
        jobject obj_user = JNI_CALL_OBJ_METHOD(inputStringArrayList, arraylist_get, i);
        jstring s = JNI_GET_OBJ_CLASS(obj_user);
        const char *str = JNI_GET_STRING_UTF(obj_user);
        LOGD("inputStringList = %s\n", (const char *) str);
    }
}

int JNI_TEST_NAME(jniTestSetStringList)(JNIEnv *env, jobject obj, jobject inputStringList) {
    jclass cls_arraylist = JNI_GET_OBJ_CLASS(inputStringList);
    jmethodID arraylist_get = JNI_GET_METHOD_ID(cls_arraylist, "get", "(I)Ljava/lang/Object;");
    jmethodID arraylist_size = JNI_GET_METHOD_ID(cls_arraylist, "size", "()I");
    jint len = JNI_CALL_INT_METHOD(inputStringList, arraylist_size);
    int i;
    for(i = 0; i < len; i++){
        jobject obj_user = JNI_CALL_OBJ_METHOD(inputStringList, arraylist_get, i);
        jstring s = JNI_GET_OBJ_CLASS(obj_user);
        const char *str = JNI_GET_STRING_UTF(obj_user);
        LOGD("inputStringList = %s\n", (const char *) str);
    }
    return 0;
}

int JNI_TEST_NAME(jniTestSetObjList)(JNIEnv *env, jobject obj, jobject inputObjList) {
    jclass cls_arraylist = JNI_GET_OBJ_CLASS(inputObjList);
    jmethodID arraylist_get = JNI_GET_METHOD_ID(cls_arraylist, "get", "(I)Ljava/lang/Object;");
    jmethodID arraylist_size = JNI_GET_METHOD_ID(cls_arraylist, "size", "()I");
    jint len = JNI_CALL_INT_METHOD(inputObjList, arraylist_size);
    int i;
    for(i = 0; i < len; i++){
        jobject inputObj = JNI_CALL_OBJ_METHOD(inputObjList, arraylist_get, i);

        test_param_t *test_param = malloc(sizeof(test_param_t));

        jclass jcls = JNI_FIND_CLASS(CLASS_TEST_OBJ_PARAM);

        jniGetBoolean(env, inputObj, jcls, "bool_filed", &test_param->bool_filed);
        jniGetByte(env, inputObj, jcls, "b_filed", &test_param->b_filed);
        jniGetChar(env, inputObj, jcls, "c_filed", &test_param->c_filed);
        jniGetShort(env, inputObj, jcls, "s_filed", &test_param->s_filed);
        jniGetInt(env, inputObj, jcls, "i_filed", &test_param->i_filed);
        jniGetLong(env, inputObj, jcls, "l_filed", &test_param->l_filed);
        jniGetFloat(env, inputObj, jcls, "f_filed", &test_param->f_filed);
        jniGetDouble(env, inputObj, jcls, "d_filed", &test_param->d_filed);

        test_param->str_filed = malloc(100);
        jniGetString(env, inputObj, jcls, "str_filed", test_param->str_filed);

        LOGD("test_param->bool_filed = %d", test_param->bool_filed);
        LOGD("test_param->b_filed = %d", test_param->b_filed);
        LOGD("test_param->c_filed = %d", test_param->c_filed);
        LOGD("test_param->s_filed = %d", test_param->s_filed);
        LOGD("test_param->i_filed = %d", test_param->i_filed);
        LOGD("test_param->l_filed = %ld", test_param->l_filed);
        LOGD("test_param->f_filed = %f", test_param->f_filed);
        LOGD("test_param->d_filed = %f", test_param->d_filed);
        LOGD("test_param->d_filed = %s", test_param->str_filed);
    }
    return 0;
}



jboolean JNI_TEST_NAME(jniTestGetBoolean)(JNIEnv *env, jobject obj) {
    return TRUE;
}

jbyte JNI_TEST_NAME(jniTestGetByte)(JNIEnv *env, jobject obj) {
    return 11;
}

jchar JNI_TEST_NAME(jniTestGetChar)(JNIEnv *env, jobject obj) {
    return 23;
}

jshort JNI_TEST_NAME(jniTestGetShort)(JNIEnv *env, jobject obj) {
    return 12141;
}

jint JNI_TEST_NAME(jniTestGetInt)(JNIEnv *env, jobject obj) {
    return 2142;
}

jlong JNI_TEST_NAME(jniTestGetLong)(JNIEnv *env, jobject obj) {
    return 1112124;
}

jfloat JNI_TEST_NAME(jniTestGetFloat)(JNIEnv *env, jobject obj) {
    return 11.88;
}

jdouble JNI_TEST_NAME(jniTestGetDouble)(JNIEnv *env, jobject obj) {
    return 161565.516155;
}

jstring JNI_TEST_NAME(jniTestGetString)(JNIEnv *env, jobject obj) {
    return JNI_NEW_STRING_UTF("Hello world");
}

jobject JNI_TEST_NAME(jniTestGetObj)(JNIEnv *env, jobject obj) {
    test_param_t *test_param = malloc(sizeof(test_param_t));
    test_param->bool_filed = FALSE;
    test_param->b_filed = 11;
    test_param->c_filed = 22;
    test_param->s_filed = 33;
    test_param->i_filed = 44;
    test_param->l_filed = 55;
    test_param->f_filed = 66.66;
    test_param->d_filed = 77.77;
    test_param->str_filed = "hello world";

    jclass jCls = JNI_FIND_CLASS(CLASS_TEST_OBJ_PARAM);
    jmethodID jMethodID = JNI_GET_METHOD_ID(jCls, "<init>", "()V");
    jobject jObj = JNI_NEW_OBJ(jCls, jMethodID);

    jniSetBoolean(env, jObj, jCls, "bool_filed", test_param->bool_filed);
    jniSetByte(env, jObj, jCls, "b_filed", test_param->b_filed);
    jniSetChar(env, jObj, jCls, "c_filed", test_param->c_filed);
    jniSetShort(env, jObj, jCls, "s_filed", test_param->s_filed);
    jniSetInt(env, jObj, jCls, "i_filed", test_param->i_filed);
    jniSetLong(env, jObj, jCls, "l_filed", test_param->l_filed);
    jniSetFloat(env, jObj, jCls, "f_filed", test_param->f_filed);
    jniSetDouble(env, jObj, jCls, "d_filed", test_param->d_filed);
    jniSetString(env, jObj, jCls, "str_filed", JNI_NEW_STRING_UTF(test_param->str_filed));

    return jObj;
}

jbooleanArray JNI_TEST_NAME(jniTestGetBooleanArray)(JNIEnv *env, jobject obj) {
    jboolean testBoolArr[] = {0, 1, 1, 0, 1, 1};
    jbooleanArray jbArr = JNI_NEW_BOOLEAN_ARRAY(6);
    JNI_SET_BOOLEAN_ARRAY_REGION(jbArr, 0, 6, testBoolArr);
    return jbArr;
}

jbyteArray JNI_TEST_NAME(jniTestGetByteArray)(JNIEnv *env, jobject obj) {
    jbyte testByteArr[] = {0, 1, 5, 8, 10, 22};
    jbyteArray jbArr = JNI_NEW_BYTE_ARRAY(6);
    JNI_SET_BYTE_ARRAY_REGION(jbArr, 0, 6, testByteArr);
    return jbArr;
}

jcharArray JNI_TEST_NAME(jniTestGetCharArray)(JNIEnv *env, jobject obj) {
    jchar testCharArr[] = {0, 1, 5, 8, 10, 22};
    jcharArray jcArr = JNI_NEW_CHAR_ARRAY(6);
    JNI_SET_CHAR_ARRAY_REGION(jcArr, 0, 6, testCharArr);
    return jcArr;
}

jshortArray JNI_TEST_NAME(jniTestGetShortArray)(JNIEnv *env, jobject obj) {
    short testShortArr[] = {0, 1, 5, 8, 10, 22};
    jshortArray jsArr = JNI_NEW_SHORT_ARRAY(6);
    JNI_SET_SHORT_ARRAY_REGION(jsArr, 0, 6, testShortArr);
    return jsArr;
}

jintArray JNI_TEST_NAME(jniTestGetIntArray)(JNIEnv *env, jobject obj) {
    jint testIntArr[] = {0, 1, 5, 8, 10, 22};
    jintArray jiArr = JNI_NEW_INT_ARRAY(6);
    JNI_SET_INT_ARRAY_REGION(jiArr, 0, 6, testIntArr);
    return jiArr;
}

jlongArray JNI_TEST_NAME(jniTestGetLongArray)(JNIEnv *env, jobject obj) {
    jlong testLongArr[] = {0, 1, 5, 8, 10, 22};
    jlongArray jlArr = JNI_NEW_LONG_ARRAY(6);
    JNI_SET_LONG_ARRAY_REGION(jlArr, 0, 6, testLongArr);
    return jlArr;
}

jfloatArray JNI_TEST_NAME(jniTestGetFloatArray)(JNIEnv *env, jobject obj) {
    jfloat testFloatArr[] = {0.5, 1.7, 5, 8, 1.60, 21.2};
    jfloatArray jfArr = JNI_NEW_FLOAT_ARRAY(6);
    JNI_SET_FLOAT_ARRAY_REGION(jfArr, 0, 6, testFloatArr);
    return jfArr;
}

jdoubleArray JNI_TEST_NAME(jniTestGetDoubleArray)(JNIEnv *env, jobject obj) {
    jdouble testDoubleArr[] = {0.9966, 1, 151.565, 8, 1.660, 22};
    jdoubleArray jbArr = JNI_NEW_DOUBLE_ARRAY(6);
    JNI_SET_DOUBLE_ARRAY_REGION(jbArr, 0, 6, testDoubleArr);
    return jbArr;
}

jobjectArray JNI_TEST_NAME(jniTestGetStringArray)(JNIEnv *env, jobject obj) {
    jobjectArray jsArr = JNI_NEW_OBJ_ARRAY(6, JNI_FIND_CLASS(CLASS_OBJ_STRING));
    char *testStringArr[] = {"Hello,", "world!", "xx", "ss", "1312asfdsfd", "xs"};
    int i = 0;
    jstring jstr;
    for (; i < 6; i++) {
        jstr = JNI_NEW_STRING_UTF(testStringArr[i]);
        JNI_SET_OBJ_ARRAY_ELEMENT(jsArr, i, jstr);
    }
    return jsArr;
}

jobjectArray JNI_TEST_NAME(jniTestGetObjArray)(JNIEnv *env, jobject obj) {
    jclass jCls = JNI_FIND_CLASS(CLASS_TEST_OBJ_PARAM);
    jobjectArray joArr = JNI_NEW_OBJ_ARRAY(2, jCls);
    jmethodID jMethodID = JNI_GET_METHOD_ID(jCls, "<init>", "()V");

    jobject jObj = JNI_NEW_OBJ(jCls, jMethodID);
    jniSetBoolean(env, jObj, jCls, "bool_filed", 0);
    jniSetByte(env, jObj, jCls, "b_filed", 1);
    jniSetChar(env, jObj, jCls, "c_filed", 2);
    jniSetShort(env, jObj, jCls, "s_filed", 3);
    jniSetInt(env, jObj, jCls, "i_filed", 4);
    jniSetLong(env, jObj, jCls, "l_filed", 5);
    jniSetFloat(env, jObj, jCls, "f_filed", 6.11);
    jniSetDouble(env, jObj, jCls, "d_filed", 7.11111);
    jniSetString(env, jObj, jCls, "str_filed", JNI_NEW_STRING_UTF("xxxasffsaa"));
    JNI_SET_OBJ_ARRAY_ELEMENT(joArr, 0, jObj);

    jObj = JNI_NEW_OBJ(jCls, jMethodID);
    jniSetBoolean(env, jObj, jCls, "bool_filed", 0);
    jniSetByte(env, jObj, jCls, "b_filed", 11);
    jniSetChar(env, jObj, jCls, "c_filed", 22);
    jniSetShort(env, jObj, jCls, "s_filed", 33);
    jniSetInt(env, jObj, jCls, "i_filed", 44);
    jniSetLong(env, jObj, jCls, "l_filed", 55);
    jniSetFloat(env, jObj, jCls, "f_filed", 66.11);
    jniSetDouble(env, jObj, jCls, "d_filed", 77.11111);
    jniSetString(env, jObj, jCls, "str_filed", JNI_NEW_STRING_UTF("afgdfgdsg"));
    JNI_SET_OBJ_ARRAY_ELEMENT(joArr, 1, jObj);

    return joArr;
}



