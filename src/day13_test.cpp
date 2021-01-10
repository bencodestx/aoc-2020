#include "aoc2020/day13.hpp"

#include <boost/ut.hpp>

#include <sstream>
#include <string>

const std::string example{
    R"(939
7,13,x,x,59,x,31,19)"};

int main() {
  using namespace aoc2020::day13;
  using namespace boost::ut;

  "part1"_test = [&] {
    std::stringstream in{example};
    expect(295_u == part1(in));
  };

  "part2"_test = [&] {
    std::stringstream in{example};
    expect(0_u == part2(in));
  };
}
