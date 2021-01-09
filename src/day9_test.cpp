#include "aoc2020/day9.hpp"

#include <boost/ut.hpp>

#include <sstream>

const std::string example_text{
    R"(35
20
15
25
47
40
62
55
65
95
102
117
150
182
127
219
299
277
309
576)"};

int main() {
  using namespace aoc2020::day9;
  using namespace boost::ut;

  "part1"_test = [&] {
    std::stringstream in{example_text};
    expect(0_u == part1(in));
  };

  "part2"_test = [&] {
    std::stringstream in{example_text};
    expect(0_u == part2(in));
  };
}
