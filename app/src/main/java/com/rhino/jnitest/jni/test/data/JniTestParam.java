package com.rhino.jnitest.jni.test.data;

/**
 * Created by LuoLin on 2018/1/13.
 **/
public class JniTestParam {

    public boolean bool_filed;
    public byte b_filed;
    public char c_filed;
    public short s_filed;
    public int i_filed;
    public long l_filed;
    public float f_filed;
    public double d_filed;
    public String str_filed;

    @Override
    public String toString() {
        return "JniTestParam{" +
                "bool_filed=" + bool_filed +
                ", b_filed=" + b_filed +
                ", c_filed=" + c_filed +
                ", s_filed=" + s_filed +
                ", i_filed=" + i_filed +
                ", l_filed=" + l_filed +
                ", f_filed=" + f_filed +
                ", d_filed=" + d_filed +
                ", str_filed='" + str_filed + '\'' +
                '}';
    }
}
