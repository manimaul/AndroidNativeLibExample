# Example C++ Library setup for specific use in Android
* This is an example using [Cmake](https://cmake.org/) to create a native c++ Android library that can be built WITHOUT the use of [Android.mk](http://developer.android.com/ndk/guides/android_mk.html) files.
* In addition it uses [SWIG](http://www.swig.org/) because I did not want to write the JNI bridge code.
* Also note that this is a great setup for developing native libraries (for Android) using the [CLion](https://www.jetbrains.com/clion/) IDE.

## Requiremends
* [Cmake](https://cmake.org/)
* [Android NDK](http://developer.android.com/ndk/index.html)
* [SWIG](http://www.swig.org/)
* [LibCurl](http://curl.haxx.se/)

## Build executable for host OS
mkdir -p build/os; cd build/os
cmake ../../ && cmake --build .

## Build shared library for Android

Requires a [pre-built static libcurl]( https://github.com/manimaul/curl-android-ios/tree/master/prebuilt-with-ssl/android)

x86

``mkdir -p build/x86; cd build/x86``
``cmake -DCURL_ROOT=/Users/will/code/native/curl-android-ios/prebuilt-with-ssl/android -DLIBRARY=YES -DCMAKE_TOOLCHAIN_FILE=../../android-cmake/android.toolchain.cmake -DANDROID_NDK=/opt/android-ndk-r10d -DANDROID_ABI=x86 -DCMAKE_BUILD_TYPE=Release  ../../ && cmake --build . ``

any Android NDK ABI can be used (armeabi, armeabi-v7a, arm64-v8a, x86_64, mips, mips64)

``-DANDROID_ABI=armeabi``

## SWIG
* When making changes to the interface - Generate Java/JNI with SWIG

``swig -c++ -java -package com.willkamp.swig -outdir swig Example.i``
``swig -c++ -java -package com.willkamp.swig -outdir swig NetCxx.i``

