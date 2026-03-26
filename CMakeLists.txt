cmake_minimum_required(VERSION 3.10)
project(oot3d_randomizer_lib)

set(CMAKE_CXX_STANDARD 17)

include_directories(src)

file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS
    source/AP/*.cpp
    source/AP/*.c
)

add_executable(tester
    ${SRC_FILES}
)