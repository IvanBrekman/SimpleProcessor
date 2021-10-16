cmake_minimum_required(VERSION 3.20)
project(SimpleProcessor)

set(CMAKE_CXX_STANDARD 14)

add_executable(SimpleProcessor main.cpp
        run_cpu.cpp
        arch/helper.cpp arch/commands.cpp
        libs/file_funcs.cpp libs/stack.cpp libs/baselib.cpp)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fpermissive -g")
