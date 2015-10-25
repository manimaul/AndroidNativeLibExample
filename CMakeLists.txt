### SWIG
# swig -c++ -java -package com.willkamp.swig -outdir swig Example.i
# swig -c++ -python -outdir swig Example.i

#### Build for Android
# x86
# mkdir -p build/x86; cd build/x86
# cmake -DBOOST_ROOT=/Users/will/code/native/boost_1_59_0 -DLIBRARY=1 -DCMAKE_TOOLCHAIN_FILE=../../android-cmake/android.toolchain.cmake -DANDROID_NDK=/opt/android-ndk-r10d -DCMAKE_BUILD_TYPE=Release -DANDROID_ABI="x86" ../../ && cmake --build .
# armeabi
# mkdir -p build/armeabi; cd build/armeabi
# cmake -DBOOST_ROOT=/Users/will/code/native/boost_1_59_0 -DLIBRARY=1 -DCMAKE_TOOLCHAIN_FILE=../../android-cmake/android.toolchain.cmake -DANDROID_NDK=/opt/android-ndk-r10d -DCMAKE_BUILD_TYPE=Release -DANDROID_ABI="armeabi" ../../ && cmake --build .


cmake_minimum_required(VERSION 3.3)
set(PNAME AndroidNativeLibExample)
project(${PNAME})

set(Boost_USE_STATIC_LIBS        ON)
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME    OFF)
set(Boost_COMPILER              -gcc)

if (ANDROID)
    add_definitions(-DANDROID)
    message(STATUS "Hello from Android build!")
    find_host_package(boost COMPONENTS format system)
else()
    find_package(JNI REQUIRED)
    include_directories(${JNI_INCLUDE_DIRS})
    find_package(boost COMPONENTS format system)
endif()

####SWIG (commented out - manually invoking swig for android-cmake)
#find_package(SWIG REQUIRED)
#include(${SWIG_USE_FILE})
##find_package(Java REQUIRED COMPONENTS Runtime Development)
#set(CMAKE_SWIG_FLAGS "-package;com.willkamp.swig")
#set_source_files_properties(Example.i PROPERTIES CPLUSPLUS ON)
#set_source_files_properties(Example.i PROPERTIES SWIG_FLAGS "-includeall")
#swig_add_module(ExampleModule java Example.i Example.cpp)
#include_directories(${CMAKE_CURRENT_SOURCE_DIR})
####END SWIG

include_directories(${Boost_INCLUDE_DIRS})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(SOURCE_FILES main.cpp Example.cpp Example.h Example_wrap.cxx)

if (LIBRARY)
    add_library(${PNAME} SHARED ${SOURCE_FILES})
else()
    add_executable(${PNAME} ${SOURCE_FILES})
endif()

target_link_libraries(${PNAME} ${Boost_LIBRARIES})