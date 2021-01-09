#include "aoc2020/day10.hpp"

#include <boost/ut.hpp>

#include <sstream>

const std::string short_example{
    R"(16
10
15
5
1
11
7
19
6
12
4)"};

const std::string longer_example{
    R"(28
33
18
42
31
14
46
20
48
47
24
23
49
45
19
38
39
11
1
32
25
35
8
17
7
9
4
2
34
10
3)"};

int main() {
  using namespace aoc2020::day10;
  using namespace boost::ut;

  "input"_test = [&] {
    std::stringstream in{short_example};
    expect(std::vector<size_t>{16, 10, 15, 5, 1, 11, 7, 19, 6, 12, 4} ==
           input(in));
  };

  "part1 short example"_test = [&] {
    std::stringstream in{short_example};
    expect(35_u == part1(in));
  };

  "part1 longer example"_test = [&] {
    std::stringstream in{longer_example};
    expect(220_u == part1(in));
  };

  "part2 short example"_test = [&] {
    std::stringstream in{short_example};
    expect(0_u == part2(in));
  };
}
