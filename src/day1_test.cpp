#include "aoc2020/day1.hpp"

#include <boost/ut.hpp>

#include <array>
#include <sstream>

int main() {
  using namespace boost::ut;
  using namespace aoc2020::day1;

  constexpr auto example_expense_report{
      R"(1721
979
366
299
675
1456)"};

  "input"_test = [&] {
    std::stringstream in(example_expense_report);
    expect(std::vector<size_t>{1721u, 979u, 366u, 299u, 675u, 1456u} ==
           input(in));
  };

  "1010, 1010 == 1020100"_test = [&] {
    expect(1020100_u == part1(std::array{1010u, 1010u}));
  };

  "1010, 9999, 1010 == 1020100"_test = [&] {
    expect(1020100_u == part1(std::array{1010u, 9999u, 1010u}));
  };

  "1721, 9999, 299 == 514579"_test = [&] {
    expect(514579_u == part1(std::array{1721u, 9999u, 299u}));
  };

  "9999, 1721, 299 == 514579"_test = [&] {
    expect(514579_u == part1(std::array{9999u, 1721u, 299u}));
  };

  "no solution"_test = [&] {
    expect(throws([] { part1(std::array{1u, 2u, 3u, 4u, 5u}); }));
  };

  "sample"_test = [&] {
    std::stringstream in(example_expense_report);
    expect(514579_u == part1(input(in)));
  };

  "sample_part2"_test = [&] {
    std::stringstream in(example_expense_report);
    expect(241861950_u == part2(input(in)));
  };
}
