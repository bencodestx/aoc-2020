#include "aoc2020/day12.hpp"

#include <boost/ut.hpp>

#include <sstream>
#include <string>

const std::string example{
    R"(F10
N3
F7
R90
F11)"};

int main() {
  using namespace aoc2020::day12;
  using namespace boost::ut;

  "part1"_test = [&] {
    std::stringstream in{example};
    const auto result = part1(in);
    expect(25_i == result);
  };

  "part2"_test = [&] {
    std::stringstream in{example};
    const auto result = part2(in);
    expect(0_i == result);
  };
}
