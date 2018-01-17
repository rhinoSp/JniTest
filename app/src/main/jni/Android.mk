#每个Android.mk文件必须以定义LOCAL_PATH为开始。它用于在开发tree中查找源文件。
#宏my-dir 则由Build System提供。返回包含Android.mk的目录路径。
LOCAL_PATH:= $(call my-dir)


#CLEAR_VARS 变量由Build System提供。并指向一个指定的GNU Makefile，由它负责清理很多LOCAL_xxx.
#例如：LOCAL_MODULE, LOCAL_SRC_FILES, LOCAL_STATIC_LIBRARIES等等。但不清理LOCAL_PATH.
#这个清理动作是必须的，因为所有的编译控制文件由同一个GNU Make解析和执行，其变量是全局的。所以清理后才能避免相互影响。
include $(CLEAR_VARS)


#指定.so的输出目录，注意路径的最后一定要是$(TARGET_ARCH_ABI)
NDK_APP_DST_DIR := ../jniLibs/$(TARGET_ARCH_ABI)


#LOCAL_MODULE模块必须定义，以表示Android.mk中的每一个模块。名字必须唯一且不包含空格。
#Build System会自动添加适当的前缀和后缀。例如，foo，要产生动态库，则生成libfoo.so. 
#但请注意：如果模块名被定为：libfoo.则生成libfoo.so. 不再加前缀。
LOCAL_MODULE := clib_jni


#LOCAL_SRC_FILES变量必须包含将要打包如模块的C/C++ 源码。
#不必列出头文件，build System 会自动帮我们找出依赖文件。
#缺省的C++源码的扩展名为.cpp. 也可以修改，通过LOCAL_CPP_EXTENSION。
#LOCAL_SRC_FILES := cl_init.c
MY_SRC_PATH := $(LOCAL_PATH)/src
MY_FILES := $(wildcard $(MY_SRC_PATH)/*.c)
MY_FILES := $(MY_FILES:$(LOCAL_PATH)/%=%)
LOCAL_SRC_FILES += $(MY_FILES)


#一个可选的path列表。相对于NDK ROOT 目录。编译时，将会把这些目录附上。  
#LOCAL_C_INCLUDES := sources/foo  LOCAL_C_INCLUDES := $(LOCAL_PATH)/../foo
LOCAL_C_INCLUDES := $(JNI_H_INCLUDE)


#编译为动态库libclib_jni.so
LOCAL_SHARED_LIBRARIES := libclib_jni


#变量设置为false那么将不做prelink操作 
LOCAL_PRELINK_MODULE := false


#user: 指该模块只在user版本下才编译
#eng: 指该模块只在eng版本下才编译
#tests: 指该模块只在tests版本下才编译
#optional:指该模块在所有版本下都编译
LOCAL_MODULE_TAGS := optional


#LOCAL_LDLIBS可以用它来添加系统库。 如 -lz:   
#LOCAL_LDLIBS := -lz
LOCAL_LDLIBS += -L$(SYSROOT)/usr/lib -llog


#BUILD_SHARED_LIBRARY：是Build System提供的一个变量，指向一个GNU Makefile Script。
#它负责收集自从上次调用 include $(CLEAR_VARS)  后的所有LOCAL_XXX信息。并决定编译为什么。
include $(BUILD_SHARED_LIBRARY)
