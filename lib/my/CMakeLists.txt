cmake_minimum_required(VERSION 3.12)

project(my C)

file(GLOB LIB_SRC_FILES src/*.c src/**/*.c)

include_directories(include)

add_subdirectory(test)