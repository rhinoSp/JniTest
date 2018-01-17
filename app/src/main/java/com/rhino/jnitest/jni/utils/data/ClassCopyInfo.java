package com.rhino.jnitest.jni.utils.data;

import java.util.ArrayList;

/**
 * @since Created by LuoLin on 2018/1/11.
 */
public class ClassCopyInfo {

    public String mName;
    public ArrayList<ClassCopyField> mFields;

    @Override
    public String toString() {
        return new StringBuilder()
                .append("{ name: ").append(mName)
                .append(", fields: ").append(mFields.toString())
                .append(" }")
                .toString();
    }
}
