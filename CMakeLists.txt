cmake_minimum_required(VERSION 3.27)
project(ProgrammingProject C)

set(CMAKE_C_STANDARD 99)
set(SOURCE_FILES main.c)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK REQUIRED IMPORTED_TARGET gtk4)

include_directories(${GTK_INCLUDE_DIRS})
link_directories(${GTK_LIBRARY_DIRS})

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} PRIVATE ${GTK_LIBRARIES})
