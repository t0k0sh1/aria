cmake_minimum_required(VERSION 3.10)
project(aria)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(SOURCES
    src/main.c
    src/vm.c
    src/stack.c
    src/opcode.c
    src/lexer.c
    src/parse.c
    src/generate.c
    src/writer.c
)

include_directories(include)

add_executable(aria ${SOURCES})