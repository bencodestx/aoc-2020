add_executable(day1_test day1_test.cpp)
target_link_libraries(day1_test PUBLIC boost::ut)
add_unit_test(day1_test)

add_day_part(1 1)