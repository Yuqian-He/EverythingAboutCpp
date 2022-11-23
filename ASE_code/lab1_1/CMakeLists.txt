# We will always try to use a version > 3.1 if avaliable
cmake_minimum_required(VERSION 3.2)

if(NOT DEFINED CMAKE_TOOLCHAIN_FILE AND DEFINED ENV{CMAKE_TOOLCHAIN_FILE})
   set(CMAKE_TOOLCHAIN_FILE $ENV{CMAKE_TOOLCHAIN_FILE})
endif()

# name of the project It is best to use something different from the exe name
project(fmt_build) 

# Here we set the C++ standard to use
set(CMAKE_CXX_STANDARD 17)

# Now we are going to search for our fmt library this will be a .cmake file
# in this case with a name like  fmtConfig.cmake or fmt-config.cmake
find_package(fmt CONFIG REQUIRED)

# Now we add our target executable and the file it is built from.
add_executable(fmt fmt.cpp)

# Finally we need to link our libraries. In this case we specify we want to use 
# The header only version of fmt which will set the flags on the compile line.

target_link_libraries(fmt PRIVATE  fmt::fmt-header-only)