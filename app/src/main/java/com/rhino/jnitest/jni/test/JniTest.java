package com.rhino.jnitest.jni.test;

import com.rhino.jnitest.jni.test.data.JniTestParam;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by LuoLin on 2018/1/13.
 **/
public class JniTest {

    public static native int jniTestSetBoolean(boolean v);
    public static native int jniTestSetByte(byte v);
    public static native int jniTestSetChar(char v);
    public static native int jniTestSetShort(short v);
    public static native int jniTestSetInt(int v);
    public static native int jniTestSetLong(long v);
    public static native int jniTestSetFloat(float v);
    public static native int jniTestSetDouble(double v);
    public static native int jniTestSetString(String v);
    public static native int jniTestSetObj(JniTestParam v);

    public static native int jniTestSetBooleanArray(boolean[] v);
    public static native int jniTestSetByteArray(byte[] v);
    public static native int jniTestSetCharArray(char[] v);
    public static native int jniTestSetShortArray(short[] v);
    public static native int jniTestSetIntArray(int[] v);
    public static native int jniTestSetLongArray(long[] v);
    public static native int jniTestSetFloatArray(float[] v);
    public static native int jniTestSetDoubleArray(double[] v);
    public static native int jniTestSetStringArray(String[] v);
    public static native int jniTestSetStringArrayList(ArrayList<String> v);
    public static native int jniTestSetStringList(List<String> v);
    public static native int jniTestSetObjList(List<JniTestParam> v);


    public static native boolean jniTestGetBoolean();
    public static native byte jniTestGetByte();
    public static native byte jniTestGetChar();
    public static native short jniTestGetShort();
    public static native int jniTestGetInt();
    public static native long jniTestGetLong();
    public static native float jniTestGetFloat();
    public static native double jniTestGetDouble();
    public static native String jniTestGetString();
    public static native JniTestParam jniTestGetObj();


    public static native boolean[] jniTestGetBooleanArray();
    public static native byte[] jniTestGetByteArray();
    public static native char[] jniTestGetCharArray();
    public static native short[] jniTestGetShortArray();
    public static native byte[] jniTestGetIntArray();
    public static native long[] jniTestGetLongArray();
    public static native float[] jniTestGetFloatArray();
    public static native double[] jniTestGetDoubleArray();
    public static native String[] jniTestGetStringArray();
    public static native JniTestParam[] jniTestGetObjArray();

}
