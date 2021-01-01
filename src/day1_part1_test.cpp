#include "day1.hpp"

#include <boost/ut.hpp>

#include <array>
#include <sstream>

int main() {
  using namespace boost::ut;

  constexpr auto example_expense_report{
      R"(1721
979
366
299
675
1456)"};

  "input"_test = [&] {
    std::stringstream in(example_expense_report);
    expect(std::vector{1721, 979, 366, 299, 675, 1456} == day1_input(in));
  };

  "1010, 1010 == 1020100"_test = [&] {
    expect(1020100_i == day1_part1(std::array{1010, 1010}));
  };

  "1010, 9999, 1010 == 1020100"_test = [&] {
    expect(1020100_i == day1_part1(std::array{1010, 9999, 1010}));
  };

  "1721, 9999, 299 == 514579"_test = [&] {
    expect(514579_i == day1_part1(std::array{1721, 9999, 299}));
  };

  "9999, 1721, 299 == 514579"_test = [&] {
    expect(514579_i == day1_part1(std::array{9999, 1721, 299}));
  };

  "no solution"_test = [&] {
    expect(throws([] { day1_part1(std::array{1, 2, 3, 4, 5}); }));
  };

  "sample"_test = [&] {
    std::stringstream in(example_expense_report);
    expect(514579_i == day1_part1(day1_input(in)));
  };
}
