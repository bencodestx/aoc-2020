#include "aoc2020/day14.hpp"

#include <boost/ut.hpp>

#include <sstream>

const std::string example_v1{
    R"(mask = XXXXXXXXXXXXXXXXXXXXXXXXXXXXX1XXXX0X
mem[8] = 11
mem[7] = 101
mem[8] = 0)"};

const std::string example_v2{
    R"(mask = 000000000000000000000000000000X1001X
mem[42] = 100
mask = 00000000000000000000000000000000X0XX
mem[26] = 1)"};

int main() {
  using namespace aoc2020::day14;
  using namespace boost::ut;

  "part1"_test = [&] {
    std::stringstream in{example_v1};
    expect(165_u == part1(in));
  };

  "part2"_test = [&] {
    std::stringstream in{example_v2};
    expect(208_u == part2(in));
  };
}
