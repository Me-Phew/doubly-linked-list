cmake_minimum_required(VERSION 3.10)

project(DoublyLinkedList)

include_directories(src/app src/doubly_linked_list)

set(SOURCES src/app/app.cpp src/doubly_linked_list/doubly_linked_list.cpp src/main.cpp)

add_executable(DoublyLinkedList ${SOURCES})

# Compile with all warnings, treat warnings as errors
if (MSVC)
    add_compile_options(/W4 /WX)
else()
    add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()
