#include "aoc2020/day15.hpp"

#include <sstream>

#include <boost/ut.hpp>

int main() {
  using namespace aoc2020::day15;
  using namespace boost::ut;

  "part1"_test = [&] {
    std::stringstream in{};
    expect(0_u == part1(in));
  };

  "part2"_test = [&] {
    std::stringstream in{};
    expect(0_u == part2(in));
  };
}
