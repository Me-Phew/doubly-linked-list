cmake_minimum_required(VERSION 3.10)

project(DoublyLinkedList)

include_directories(io)
include_directories(contacts)

set(SOURCES src/main.cpp)

add_executable(DoublyLinkedList ${SOURCES})

# Compile with all warnings, treat warnings as errors
if (MSVC)
    add_compile_options(/W4 /WX)
else()
    add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()
