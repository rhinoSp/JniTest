1. 如果出现以下错误，需要指定NDK_PROJECT_PATH和NDK_APPLICATION_MK
$ ndk-build
Android NDK: Could not find application project directory !
Android NDK: Please define the NDK_PROJECT_PATH variable to point to it.
D:\MyWorkSoft\AndroidStudio\sdk\android-ndk-r14b\build\\..\build\core\build-local.mk:151: *** Android NDK: Aborting    .  Stop.


2. 如果执行报以下错误，可能是ndk下载错了，请确定安装的是32位还是64位 ？
$ ndk-build NDK_PROJECT_PATH=. NDK_APPLICATION_MK=Application.mk
[arm64-v8a] "Compile        ": "jniUtils <= jni_test.c"
process_begin: CreateProcess(NULL, D:/MySoftware/AndroidStudio/Sdk/android-ndk-r14b/build//../toolchains/llvm/prebuilt/windows-x86_64/bin/clang.exe -MMD -MP -MF ./obj/local/arm64-v8a/objs/jniUtils/jni_test.o.d -gcc-toolchain D:/MySoftwa
re/AndroidStudio/Sdk/android-ndk-r14b/build//../toolchains/aarch64-linux-android-4.9/prebuilt/windows-x86_64 -target aarch64-none-linux-android -ffunction-sections -funwind-tables -fstack-protector-strong -fpic -Wno-invalid-command-line
-argument -Wno-unused-command-line-argument -no-canonical-prefixes -g -O2 -DNDEBUG -I. -DANDROID -Wa,--noexecstack -Wformat -Werror=format-security --sysroot D:/MySoftware/AndroidStudio/Sdk/android-ndk-r14b/build//../platforms/android-2
1/arch-arm64 -c ./jni_test.c -o ./obj/local/arm64-v8a/objs/jniUtils/jni_test.o, ...) failed.
make (e=2):
make: *** [obj/local/arm64-v8a/objs/jniUtils/jni_test.o] Error 2


3. 最后，终于执行成功了
$ ndk-build NDK_PROJECT_PATH=. NDK_APPLICATION_MK=Application.mk
[arm64-v8a] Compile        : clib_jni <= jni_test.c
[arm64-v8a] SharedLibrary  : libclib_jni.so
[arm64-v8a] Install        : libclib_jni.so => libs/arm64-v8a/libclib_jni.so
[x86_64] Compile        : clib_jni <= jni_test.c
[x86_64] SharedLibrary  : libclib_jni.so
[x86_64] Install        : libclib_jni.so => libs/x86_64/libclib_jni.so
[mips64] Compile        : clib_jni <= jni_test.c
[mips64] SharedLibrary  : libclib_jni.so
[mips64] Install        : libclib_jni.so => libs/mips64/libclib_jni.so
[armeabi-v7a] Compile thumb  : clib_jni <= jni_test.c
[armeabi-v7a] SharedLibrary  : libclib_jni.so
[armeabi-v7a] Install        : libclib_jni.so => libs/armeabi-v7a/libclib_jni.so
[armeabi] Compile thumb  : clib_jni <= jni_test.c
[armeabi] SharedLibrary  : libclib_jni.so
[armeabi] Install        : libclib_jni.so => libs/armeabi/libclib_jni.so
[x86] Compile        : clib_jni <= jni_test.c
[x86] SharedLibrary  : libclib_jni.so
[x86] Install        : libclib_jni.so => libs/x86/libclib_jni.so
[mips] Compile        : clib_jni <= jni_test.c
[mips] SharedLibrary  : libclib_jni.so
[mips] Install        : libclib_jni.so => libs/mips/libclib_jni.so
