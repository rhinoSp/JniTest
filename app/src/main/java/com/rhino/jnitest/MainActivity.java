package com.rhino.jnitest;

import android.os.Environment;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;

import com.rhino.jnitest.jni.test.data.JniTestData;
import com.rhino.jnitest.jni.utils.JniUtils;
import com.rhino.jnitest.jni.utils.data.AppParam;
import com.rhino.jnitest.jni.utils.data.ClassCopyInfo;
import com.rhino.jnitest.jni.test.JniTest;
import com.rhino.jnitest.jni.test.data.JniTestParam;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class MainActivity extends AppCompatActivity {
    
    private static final String TAG = "MainActivity";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);


        JniUtils.loadLibrary("clib_jni");


        ArrayList<ClassCopyInfo> classCopyInfoArray = new ArrayList<>();
        ClassCopyInfo info =  JniUtils.getCopyInfo(JniTestData.class);
        Log.d(TAG, info.toString());
        classCopyInfoArray.add(info);
        info =  JniUtils.getCopyInfo(JniTestData.class);
        classCopyInfoArray.add(info);
        JniUtils.jniRegisterCopyClass(classCopyInfoArray);

        AppParam appParam = new AppParam();
        appParam.mDebug = true;
        appParam.mAppId = 9527;
        appParam.mAppPackageName = getPackageName();
        appParam.mAppVersion = "1.0";
        appParam.mAppExternalStoreDir = Environment.getExternalStorageDirectory().getPath();
        appParam.mAppPrivateStoreDir = getFilesDir().getPath();
        JniUtils.init(appParam);

        JniTest.jniTestSetBoolean(true);
        JniTest.jniTestSetByte((byte)1);
        JniTest.jniTestSetChar((char)22);
        JniTest.jniTestSetShort((short)33);
        JniTest.jniTestSetInt(44);
        JniTest.jniTestSetLong(55);
        JniTest.jniTestSetFloat(66.66f);
        JniTest.jniTestSetDouble(77.777);
        JniTest.jniTestSetString("Hello world");

        JniTestParam jniTestParam = new JniTestParam();
        jniTestParam.bool_filed = false;
        jniTestParam.b_filed = -12;
        jniTestParam.c_filed = 223;
        jniTestParam.s_filed = 123;
        jniTestParam.i_filed = 1234;
        jniTestParam.l_filed = -2321;
        jniTestParam.f_filed = 1233.765f;
        jniTestParam.d_filed = 123234.3432;
        jniTestParam.str_filed = "Hello world";
        JniTest.jniTestSetObj(jniTestParam);

        JniTest.jniTestSetBooleanArray(new boolean[]{false, true, false, false});
        JniTest.jniTestSetByteArray(new byte[]{(byte)-1, (byte)2, (byte)125, (byte)111, (byte)12});
        JniTest.jniTestSetCharArray(new char[]{1, 2, 125, 111, 12});
        JniTest.jniTestSetShortArray(new short[]{1, 2, 125, 111, 12});
        JniTest.jniTestSetIntArray(new int[]{1, 2, 125, 111, 12});
        JniTest.jniTestSetLongArray(new long[]{1, 2, 125, 111, 12});
        JniTest.jniTestSetFloatArray(new float[]{1.5152f, 0.522f, 125, 1.111f, 12});
        JniTest.jniTestSetDoubleArray(new double[]{1, 2, 125, 111, 12});
        JniTest.jniTestSetStringArray(new String[]{"xsas", "gdfgdfdg", "sfsf22"});

        ArrayList<String> a = new ArrayList<>();
        a.add("13153251");
        a.add("asfdas23423vdx");
        JniTest.jniTestSetStringArrayList(a);

        List<String> l = new ArrayList<>();
        l.add("sssssss");
        l.add("zzzzzzzzzzzzzz");
        JniTest.jniTestSetStringList(l);

        List<JniTestParam> lp = new ArrayList<>();
        JniTestParam param = new JniTestParam();
        param.bool_filed = false;
        param.b_filed = -12;
        param.c_filed = 223;
        param.s_filed = 123;
        param.i_filed = 1234;
        param.l_filed = -2321;
        param.f_filed = 1233.765f;
        param.d_filed = 123234.3432;
        param.str_filed = "Hello worldaaa";
        lp.add(param);

        param = new JniTestParam();
        param.bool_filed = false;
        param.b_filed = -12;
        param.c_filed = 223;
        param.s_filed = 123;
        param.i_filed = 1234;
        param.l_filed = -2321;
        param.f_filed = 1233.765f;
        param.d_filed = 123234.3432;
        param.str_filed = "Hello worldxxx";
        lp.add(param);
        JniTest.jniTestSetObjList(lp);


        Log.d(TAG, "jniTestGetBoolean " + JniTest.jniTestGetBoolean());
        Log.d(TAG, "jniTestGetByte " + JniTest.jniTestGetByte());
        Log.d(TAG, "jniTestGetChar " + JniTest.jniTestGetChar());
        Log.d(TAG, "jniTestGetShort " + JniTest.jniTestGetShort());
        Log.d(TAG, "jniTestGetInt " + JniTest.jniTestGetInt());
        Log.d(TAG, "jniTestGetLong " + JniTest.jniTestGetLong());
        Log.d(TAG, "jniTestGetFloat " + JniTest.jniTestGetFloat());
        Log.d(TAG, "jniTestGetDouble " + JniTest.jniTestGetDouble());
        Log.d(TAG, "jniTestGetString " + JniTest.jniTestGetString());
        Log.d(TAG, "jniTestGetObj " + JniTest.jniTestGetObj().toString());

        Log.d(TAG, "jniTestGetBooleanArray " + Arrays.toString(JniTest.jniTestGetBooleanArray()));
        Log.d(TAG, "jniTestGetByteArray " + Arrays.toString(JniTest.jniTestGetByteArray()));
        Log.d(TAG, "jniTestGetCharArray " + Arrays.toString(JniTest.jniTestGetCharArray()));
        Log.d(TAG, "jniTestGetShortArray " + Arrays.toString(JniTest.jniTestGetShortArray()));
        Log.d(TAG, "jniTestGetIntArray " + Arrays.toString(JniTest.jniTestGetIntArray()));
        Log.d(TAG, "jniTestGetLongArray " + Arrays.toString(JniTest.jniTestGetLongArray()));
        Log.d(TAG, "jniTestGetFloatArray " + Arrays.toString(JniTest.jniTestGetFloatArray()));
        Log.d(TAG, "jniTestGetDoubleArray " + Arrays.toString(JniTest.jniTestGetDoubleArray()));
        Log.d(TAG, "jniTestGetStringArray " + Arrays.toString(JniTest.jniTestGetStringArray()));
        Log.d(TAG, "jniTestGetObjArray " + Arrays.toString(JniTest.jniTestGetObjArray()));

    }
}
