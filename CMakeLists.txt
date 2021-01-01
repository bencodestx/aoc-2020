cmake_minimum_required(VERSION 3.0)
project(aoc-2020 LANGUAGES CXX)

enable_testing()

function(add_unit_test TARGET)
    add_test(${TARGET} ${TARGET})
    add_custom_command(
        OUTPUT ${TARGET}.passed
        COMMAND ${TARGET}
        COMMAND touch ${TARGET}.passed
        DEPENDS ${TARGET})
    add_custom_target(test_${TARGET} ALL DEPENDS ${TARGET}.passed)
endfunction()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -pedantic -std=c++2a")

add_subdirectory(vendor/boost-ext/ut)
add_subdirectory(src)