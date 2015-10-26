# Example Cmake and Swig setup for C++ Library used in Android

#### SWIG
* Generate Java/JNI with SWIG

swig -c++ -java -package com.willkamp.swig -outdir swig Example.i
swig -c++ -java -package com.willkamp.swig -outdir swig NetCxx.i

#### Cmake for Android
Build for Android

* x86
cmake -DCURL_ROOT=/Users/will/code/native/curl-android-ios/prebuilt-with-ssl/android -DLIBRARY=YES \
-DCMAKE_TOOLCHAIN_FILE=../../android-cmake/android.toolchain.cmake -DANDROID_NDK=/opt/android-ndk-r10d \
-DANDROID_ABI=x86 -DCMAKE_BUILD_TYPE=Release  ../../ && cmake --build .


* arm
cmake -DCURL_ROOT=/Users/will/code/native/curl-android-ios/prebuilt-with-ssl/android -DLIBRARY=YES \
-DCMAKE_TOOLCHAIN_FILE=../../android-cmake/android.toolchain.cmake -DANDROID_NDK=/opt/android-ndk-r10d \
-DANDROID_ABI=armeabi -DCMAKE_BUILD_TYPE=Release  ../../ && cmake --build .

Pre-built or build yourself curl: https://github.com/manimaul/curl-android-ios/tree/master/prebuilt-with-ssl/android

