add_executable(day1_part1_test day1_part1_test.cpp)
target_link_libraries(day1_part1_test PUBLIC boost::ut)
add_unit_test(day1_part1_test)

add_day_part(1 1)