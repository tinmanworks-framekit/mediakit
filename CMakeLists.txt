cmake_minimum_required(VERSION 3.23)

project(mediakit VERSION 0.1.0 LANGUAGES C CXX)

option(MEDIAKIT_BUILD_TESTS "Build mediakit tests" ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(mediakit_core STATIC
    src/media_session.cpp
)
add_library(MediaKit::Core ALIAS mediakit_core)

target_include_directories(mediakit_core
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

target_compile_features(mediakit_core PUBLIC cxx_std_20)

if(MEDIAKIT_BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()
