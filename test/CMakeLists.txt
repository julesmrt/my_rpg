cmake_minimum_required(VERSION 3.12)

project(test_my_rpg C)

file(GLOB TEST_SRC_FILES *.c)
file(GLOB SRC_FILES ${CMAKE_SOURCE_DIR}/src/*.c ${CMAKE_SOURCE_DIR}/src/**/*.c)
list(REMOVE_ITEM SRC_FILES "${CMAKE_SOURCE_DIR}/src/main.c")

include_directories(
        ${CMAKE_SOURCE_DIR}/include/
	${CMAKE_SOURCE_DIR}/test/include/
        ${CMAKE_SOURCE_DIR}/lib/my/include/
)

add_executable(test_my_rpg ${SRC_FILES} ${TEST_SRC_FILES})


target_link_libraries(test_my_rpg
        my
        criterion
		csfml-graphics
		csfml-window
		csfml-system
		csfml-audio
)
