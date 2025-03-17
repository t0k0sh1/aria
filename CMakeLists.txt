cmake_minimum_required(VERSION 3.10)
project(aria)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_C_FLAGS_RELEASE "-O3 -march=native -DNDEBUG")
set(CMAKE_C_FLAGS_DEBUG "-O0 -g")

set(SOURCES
    src/main.c
    src/vm.c
    src/stack.c
    src/opcode.c
    src/lexer.c
    src/parser.c
    src/generate.c
    src/writer.c
    src/reader.c
    src/util.c
    src/compiler.c
    src/runner.c
)

include_directories(include)

add_executable(aria ${SOURCES})
