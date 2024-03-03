cmake_minimum_required(VERSION 3.17)

project(zore80 
    VERSION 1.0
    DESCRIPTION "Zore80 - Z80 emulator"
    LANGUAGES C)

file(GLOB SOURCES "src/*.c")

add_executable(MyExecutable ${SOURCES})

