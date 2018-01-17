package com.rhino.jnitest.jni.utils;

import android.util.Log;

import com.rhino.jnitest.jni.utils.data.AppParam;
import com.rhino.jnitest.jni.utils.data.ClassCopyField;
import com.rhino.jnitest.jni.utils.data.ClassCopyInfo;

import java.lang.reflect.Field;
import java.lang.reflect.Method;
import java.lang.reflect.Modifier;
import java.util.ArrayList;

/**
 * <p>Some commonly used interface about jni.</p>
 *
 * @since Created by LuoLin on 2018/1/11.
 */
public class JniUtils {

    private static String TAG = "JniUtils";

    private static final String JAVA_OBJECT_NAME = "java.lang.Object";

    /**
     * Get the ClassCopyInfo.
     *
     * @param cls Class<?> must has the method "public static String[] jniMemberSequence()".
     * @return ClassCopyInfo
     */
    public static ClassCopyInfo getCopyInfo(Class<?> cls) {
        ClassCopyInfo copyInfo = new ClassCopyInfo();
        copyInfo.mName = toJniClassName(cls.getName());
        copyInfo.mFields = new ArrayList<>();
        Class<?> superClass = cls;
        ArrayList<Field> classField = new ArrayList<>();
        while (superClass != null && !superClass.getName().equals(JAVA_OBJECT_NAME)) {
            Field[] fields = superClass.getDeclaredFields();
            if (fields != null && fields.length > 0) {
                for (Field f : fields) {
                    if (!Modifier.isStatic(f.getModifiers())
                            && !Modifier.isPrivate(f.getModifiers())) {
                        // not static and not private
                        classField.add(f);
                    }
                }
            }
            superClass = superClass.getSuperclass();
        }
        ArrayList<Field> sortedClassField = new ArrayList<>();
        try {
            Method jniMemberSequenceMethod = cls.getDeclaredMethod("jniMemberSequence");
            String[] jniMemberSequence = (String[]) jniMemberSequenceMethod.invoke(null);
            for (String memberName : jniMemberSequence) {
                for (Field field : classField) {
                    if (field.getName().equals(memberName)) {
                        sortedClassField.add(field);
                    }
                }
            }
        } catch (Exception e) {
            throw new RuntimeException("Please check the method:" +
                    " \"public static String[] jniMemberSequence();\" in class " + copyInfo.mName);
        }
        for (Field f : sortedClassField) {
            ClassCopyField copyField = new ClassCopyField();
            copyField.mIsPrimitive = f.getType().isPrimitive();
            copyField.mType = toJniClassName(f.getType().getName());
            copyField.mName = f.getName();
            copyInfo.mFields.add(copyField);
        }
        return copyInfo;
    }

    public static String toJniClassName(String className) {
        return className.replace('.', '/');
    }

    public static String toJniClassName(Class<?> clazz) {
        return toJniClassName(clazz.getName());
    }

    public static void loadLibrary(String libname) {
        System.loadLibrary(libname);
    }

    public static void pushEvent(int event, int error) {
        Log.d(TAG, "pushEvent: event = " + event + ", error = " + error);
    }

    public static native String init(AppParam param);

    public static native int jniRegisterCopyClass(ArrayList<ClassCopyInfo> classCopyInfo);

}
