# min versio
cmake_minimum_required(VERSION 3.12)

if(NOT DEFINED CMAKE_TOOLCHAIN_FILE AND DEFINED ENV{CMAKE_TOOLCHAIN_FILE})
   set(CMAKE_TOOLCHAIN_FILE $ENV{CMAKE_TOOLCHAIN_FILE})
endif()

# name of our project best to be different from exe name
project(fmt_build)

#find package searches for things
find_package(fmt CONFIG REQUIRED)

#se the C++ version
set(CMAKE_CXX_STANDARD 17)

#add our source files
add_executable(fmt hello.cpp)
target_link_libraries(fmt PRIVATE  fmt::fmt-header-only)

