#include "aoc2020/day11.hpp"

#include <boost/ut.hpp>

#include <ostream>
#include <sstream>
#include <string>
#include <vector>

const std::vector<std::string> examples_part1{
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

std::ostream &operator<<(std::ostream &os,
                         const aoc2020::day11 ::layout_t &layout) {
  for (auto &row : layout) {
    os << row << '\n';
  }
  return os;
}

int main() {
  using namespace aoc2020::day11;
  using namespace boost::ut;

  "input"_test = [&] {
    std::stringstream in{examples_part1[0]};
    const auto result = input(in);
    expect(std::vector<std::string>{"L.LL.LL.LL", "LLLLLLL.LL", "L.L.L..L..",
                                    "LLLL.LL.LL", "L.LL.LL.LL", "L.LLLLL.LL",
                                    "..L.L.....", "LLLLLLLLLL", "L.LLLLLL.L",
                                    "L.LLLLL.LL"} == result);
  };

  "model part1"_test = [&] {
    for (size_t i = 1; i < std::size(examples_part1); ++i) {
      std::stringstream pre_in{examples_part1[i - 1]};
      const auto pre = input(pre_in);
      std::stringstream post_in{examples_part1[i]};
      const auto post = input(post_in);
      std::stringstream expected{};
      expected << post;

      const auto result =
          model<4>(dimensions(pre), pre, count_occupied_adjacent);
      std::stringstream actual{};
      actual << result;

      expect(actual.str() == expected.str());
    }
  };

  "part1"_test = [&] {
    std::stringstream in{examples_part1[0]};
    const auto result = part1(in);
    expect(37_u == result);
  };
}
