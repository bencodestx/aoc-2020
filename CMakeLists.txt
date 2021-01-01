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

function(add_day_part DAY PART)
    add_executable(day${DAY}_part${PART} day${DAY}_part${PART}.cpp)
    add_custom_command(
        OUTPUT day${DAY}_part${PART}_integration.passed
        COMMAND ./day${DAY}_part${PART} <${CMAKE_SOURCE_DIR}/data/day${DAY}.txt >day${DAY}_part${PART}.out
        COMMAND diff -w ${CMAKE_SOURCE_DIR}/data/day${DAY}_part${PART}_answer.txt day${DAY}_part${PART}.out
        COMMAND touch day${DAY}_part${PART}_integration.passed
        BYPRODUCTS day${DAY}_part${PART}.out
        DEPENDS day${DAY}_part${PART} ${CMAKE_SOURCE_DIR}/data/day1.txt ${CMAKE_SOURCE_DIR}/data/day${DAY}_part${PART}_answer.txt) 
    add_custom_target(
        day${DAY}_part${PART}_integration
        ALL
        DEPENDS day${DAY}_part${PART}_integration.passed)
endfunction()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -pedantic -std=c++2a")

add_subdirectory(vendor/boost-ext/ut)
add_subdirectory(src)