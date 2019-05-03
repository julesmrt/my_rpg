cmake_minimum_required(VERSION 3.12)

project(my_rpg C)

set(LIB_DIR lib/my)
set(SRC_DIR src)

file(GLOB SRC_FILES ${SRC_DIR}/*.c ${SRC_DIR}/**/*.c)
file(GLOB LIB_SRC_FILES ${LIB_DIR}/src/**/*.c ${LIB_DIR}/src/*.c)

include_directories(
    lib/my/include
    include/
)

add_executable(my_rpg ${SRC_FILES})

add_library(my STATIC ${LIB_SRC_FILES})

target_link_libraries(my_rpg
        my
        csfml-graphics
        csfml-window
        csfml-system
        csfml-audio
)

add_subdirectory(test)
