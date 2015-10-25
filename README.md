# Example Cmake and Swig setup for C++ Library used in Android

#### SWIG
Generate:
* swig -c++ -java -package com.willkamp.swig -outdir swig Example.i

#### Cmake for Android
 building for x86
* mkdir -p build/x86; cd build/x86
* cmake -DBOOST_ROOT=/Users/will/code/native/boost_1_59_0 -DLIBRARY=1 -DCMAKE_TOOLCHAIN_FILE=../../android-cmake/android.toolchain.cmake -DANDROID_NDK=/opt/android-ndk-r10d -DCMAKE_BUILD_TYPE=Release -DANDROID_ABI="x86" ../../ && cmake --build .
 building for armeabi
* mkdir -p build/armeabi; cd build/armeabi
* cmake -DBOOST_ROOT=/Users/will/code/native/boost_1_59_0 -DLIBRARY=1 -DCMAKE_TOOLCHAIN_FILE=../../android-cmake/android.toolchain.cmake -DANDROID_NDK=/opt/android-ndk-r10d -DCMAKE_BUILD_TYPE=Release -DANDROID_ABI="armeabi" ../../ && cmake --build .


