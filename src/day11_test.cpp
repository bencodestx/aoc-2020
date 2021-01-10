#include "aoc2020/day11.hpp"

#include <boost/ut.hpp>

#include <sstream>
#include <string>
#include <vector>

const std::vector<std::string> examples{
    R"(L.LL.LL.LL
LLLLLLL.LL
L.L.L..L..
LLLL.LL.LL
L.LL.LL.LL
L.LLLLL.LL
..L.L.....
LLLLLLLLLL
L.LLLLLL.L
L.LLLLL.LL)",
    R"(#.##.##.##
#######.##
#.#.#..#..
####.##.##
#.##.##.##
#.#####.##
..#.#.....
##########
#.######.#
#.#####.##)",
    R"(#.LL.L#.##
#LLLLLL.L#
L.L.L..L..
#LLL.LL.L#
#.LL.LL.LL
#.LLLL#.##
..L.L.....
#LLLLLLLL#
#.LLLLLL.L
#.#LLLL.##)",
    R"(#.##.L#.##
#L###LL.L#
L.#.#..#..
#L##.##.L#
#.##.LL.LL
#.###L#.##
..#.#.....
#L######L#
#.LL###L.L
#.#L###.##)",
    R"(#.#L.L#.##
#LLL#LL.L#
L.L.L..#..
#LLL.##.L#
#.LL.LL.LL
#.LL#L#.##
..L.L.....
#L#LLLL#L#
#.LLLLLL.L
#.#L#L#.##)",
    R"(#.#L.L#.##
#LLL#LL.L#
L.#.L..#..
#L##.##.L#
#.#L.LL.LL
#.#L#L#.##
..L.L.....
#L#L##L#L#
#.LLLLLL.L
#.#L#L#.##)"};

int main() {
  using namespace aoc2020::day11;
  using namespace boost::ut;

  "input"_test = [&] {
    std::stringstream in{examples[0]};
    const auto result = input(in);
    expect(std::vector<std::string>{"L.LL.LL.LL", "LLLLLLL.LL", "L.L.L..L..",
                                    "LLLL.LL.LL", "L.LL.LL.LL", "L.LLLLL.LL",
                                    "..L.L.....", "LLLLLLLLLL", "L.LLLLLL.L",
                                    "L.LLLLL.LL"} == result);
  };
}
