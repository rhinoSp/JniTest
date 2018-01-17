package com.rhino.jnitest.jni.utils.data;


/**
 * @since Created by LuoLin on 2018/1/11.
 */
public class ClassCopyField {

    public boolean mIsPrimitive;
    public String mType;
    public String mName;

    @Override
    public String toString() {
        return new StringBuilder()
                .append("{ mIsPrimitive: ").append(mIsPrimitive)
                .append(", mType: ").append(mType)
                .append(", mName: ").append(mName)
                .append(" }")
                .toString();
    }
}
