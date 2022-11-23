# make min wersion 3.12
cmake_minimum_required(VERSION 3.12)

# this is to make vcpkg work.
if(NOT DEFINED CMAKE_TOOLCHAIN_FILE AND DEFINED ENV{CMAKE_TOOLCHAIN_FILE})
   set(CMAKE_TOOLCHAIN_FILE $ENV{CMAKE_TOOLCHAIN_FILE})
endif()

# add our project
project(RGBA_build CXX)

# set some project values
set(CMAKE_CXX_STANDARD 17)

# add the executable name for this program 
add_executable(RGBA)
include_directories(include)

# add source files for my project
target_sources(RGBA PRIVATE ${CMAKE_SOURCE_DIR}/src/main.cpp)

## Add testing stuff
find_package(GTest CONFIG REQUIRED)
include(GoogleTest)
enable_testing()
add_executable(RGBATests)
target_sources(RGBATests PRIVATE tests/RGBATests.cpp)
include_directories(include)
target_link_libraries(RGBATests PRIVATE GTest::gtest GTest::gtest_main)
gtest_discover_tests(RGBATests)