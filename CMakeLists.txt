cmake_minimum_required(VERSION 3.16)
project(week_4_homework_KGhim7 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(week_4_homework_KGhim7
        driver.cpp
        Student.cpp
        Course.cpp
)

target_include_directories(week_4_homework_KGhim7 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

if (MSVC)
    target_compile_options(week_4_homework_KGhim7 PRIVATE /W4)
else()
    target_compile_options(week_4_homework_KGhim7 PRIVATE -Wall -Wextra -Wpedantic)
endif()
