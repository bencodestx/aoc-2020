#include "aoc2020/day14.hpp"

#include <boost/ut.hpp>

#include <sstream>

const std::string example{
    R"(mask = XXXXXXXXXXXXXXXXXXXXXXXXXXXXX1XXXX0X
mem[8] = 11
mem[7] = 101
mem[8] = 0)"};

int main() {
  using namespace aoc2020::day14;
  using namespace boost::ut;

  "part1"_test = [&] {
    std::stringstream in{example};
    expect(165_u == part1(in));
  };

  "part2"_test = [&] {
    std::stringstream in{example};
    expect(0_u == part2(in));
  };
}
