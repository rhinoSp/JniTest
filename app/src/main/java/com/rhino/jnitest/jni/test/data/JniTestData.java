package com.rhino.jnitest.jni.test.data;

/**
 * @since Created by LuoLin on 2018/1/11.
 **/
public class JniTestData implements Cloneable{

    public int mId;
    public String mName;
    public byte mAge;
    public long mJoinTimestamp;

    public static String[] jniMemberSequence() {
        return new String[] {
                "mId",
                "mName",
                "mAge",
                "mJoinTimestamp",
        };
    }

    @Override
    protected JniTestData clone() throws CloneNotSupportedException {
        return (JniTestData)super.clone();
    }
}
