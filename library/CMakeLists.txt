# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.
message("test_-->" + "${CMAKE_SOURCE_DIR}")
include_directories("${CMAKE_SOURCE_DIR}/src/main/cpp/include/")

#设置生成release版本so
set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -s")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -s")

#source
set(easy_aac_dir_name libfaac)

#MP4V2
include_directories("${CMAKE_SOURCE_DIR}/src/main/cpp/include/mp4v2/")
message("test_-->" + "${CMAKE_SOURCE_DIR}/src/main/cpp/include/mp4v2/")

#cpp目录下的c cpp h文件
include_directories("${CMAKE_SOURCE_DIR}/src/main/cpp/include/")
file(GLOB EASY_AAC_SRC_LIST_H "${CMAKE_SOURCE_DIR}/src/main/cpp/*.h")
file(GLOB EASY_AAC_SRC_LIST_C "${CMAKE_SOURCE_DIR}/src/main/cpp/*.c")
file(GLOB EASY_AAC_SRC_LIST_CPP "${CMAKE_SOURCE_DIR}/src/main/cpp/*.cpp")

#cpp/libffac目录下的h c cpp文件
file(GLOB EASY_AAC_F_SRC_LIST_H "${CMAKE_SOURCE_DIR}/src/main/cpp/${easy_aac_dir_name}/*.h")
file(GLOB EASY_AAC_F_SRC_LIST_C "${CMAKE_SOURCE_DIR}/src/main/cpp/${easy_aac_dir_name}/*.c")
file(GLOB EASY_AAC_F_SRC_LIST_CPP "${CMAKE_SOURCE_DIR}/src/main/cpp/${easy_aac_dir_name}/*.cpp")

#cpp/libffac/kiss_ft目录下的h c文件
file(GLOB EASY_AAC_F_KISS_SRC_LIST_H "${CMAKE_SOURCE_DIR}/src/main/cpp/${easy_aac_dir_name}/kiss_fft/*.h")
file(GLOB EASY_AAC_F_KISS_SRC_LIST_C "${CMAKE_SOURCE_DIR}/src/main/cpp/${easy_aac_dir_name}/kiss_fft/*.c")

add_library( # Sets the name of the library.
        easyaacencoder
        # Sets the library as a shared library.
        SHARED
#
#        # Provides a relative path to your source file(s).
        ${CMAKE_SOURCE_DIR}/src/main/cpp/MyNativeCpp.cpp

        #libaac
        ${EASY_AAC_SRC_LIST_H}
        ${EASY_AAC_SRC_LIST_C}
        ${EASY_AAC_SRC_LIST_CPP}

        ${EASY_AAC_F_SRC_LIST_H}
        ${EASY_AAC_F_SRC_LIST_C}
        ${EASY_AAC_F_SRC_LIST_CPP}

        ${EASY_AAC_F_KISS_SRC_LIST_H}
        ${EASY_AAC_F_KISS_SRC_LIST_C}
        )

add_library(
        mp4v2
        SHARED
        IMPORTED
)

set_target_properties(
        mp4v2
        PROPERTIES IMPORTED_LOCATION
        ${CMAKE_SOURCE_DIR}/src/main/jniLibs/${ANDROID_ABI}/libmp4v2.so
)
message("test_-->" + "${CMAKE_SOURCE_DIR}/src/main/jniLibs/${ANDROID_ABI}/libmp4v2.so")
#
## Searches for a specified prebuilt library and stores the path as a
## variable. Because CMake includes system libraries in the search path by
## default, you only need to specify the name of the public NDK library
## you want to add. CMake verifies that the library exists before
## completing its build.
#
find_library( # Sets the name of the path variable.
        log-lib

        # Specifies the name of the NDK library that
        # you want CMake to locate.
        log)
#
## Specifies libraries CMake should link to your target library. You
## can link multiple libraries, such as libraries you define in this
## build script, prebuilt third-party libraries, or system libraries.
#
target_link_libraries( # Specifies the target library.
        easyaacencoder
        # Links the target library to the log library
        mp4v2
        # included in the NDK.
        ${log-lib})