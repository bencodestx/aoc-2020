#include "aoc2020/day5.hpp"

#include <boost/ut.hpp>

int main() {
  using namespace aoc2020::day5;
  using namespace boost::ut;

  "F of 0-127 is 0-63"_test = [&] {
    const auto result = take('F', {0, 127});
    expect(result.first == 0_u);
    expect(result.second == 63_u);
  };

  "B of 0-63 is 32-63"_test = [&] {
    const auto result = take('B', {0, 63});
    expect(result.first == 32_u);
    expect(result.second == 63_u);
  };

  "F of 32-63 is 32-47"_test = [&] {
    const auto result = take('F', {32, 63});
    expect(result.first == 32_u);
    expect(result.second == 47_u);
  };

  "B of 32-47 is 40-47"_test = [&] {
    const auto result = take('B', {32, 47});
    expect(result.first == 40_u);
    expect(result.second == 47_u);
  };

  "B of 40-47 is 44-47"_test = [&] {
    const auto result = take('B', {40, 47});
    expect(result.first == 44_u);
    expect(result.second == 47_u);
  };

  "F of 44-47 is 44-45"_test = [&] {
    const auto result = take('F', {44, 47});
    expect(result.first == 44_u);
    expect(result.second == 45_u);
  };

  "F of 44-45 is 44-44"_test = [&] {
    const auto result = take('F', {44, 45});
    expect(result.first == 44_u);
    expect(result.second == 44_u);
  };

  "R of 0-7 is 4-7"_test = [&] {
    const auto result = take('R', {0, 7});
    expect(result.first == 4_u);
    expect(result.second == 7_u);
  };

  "L of 4-7 is 4-5"_test = [&] {
    const auto result = take('L', {4, 7});
    expect(result.first == 4_u);
    expect(result.second == 5_u);
  };

  "R of 4-5 is 5-5"_test = [&] {
    const auto result = take('R', {4, 5});
    expect(result.first == 5_u);
    expect(result.second == 5_u);
  };

  "FBFBBFFRLR is row 44, column 5"_test = [&] {
    const auto result = locate("FBFBBFFRLR");
    expect(result.first == 44_u);
    expect(result.second == 5_u);
  };

  "row 44, column 5 has seat id 357"_test = [&] {
    expect(357_u == seatid({44, 5}));
  };
}
