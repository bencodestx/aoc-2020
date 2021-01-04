#include "aoc2020/day3.hpp"

#include <boost/ut.hpp>

#include <sstream>

// clang-format off
const aoc2020::day3::geography_t example_rows{
  "..##.......",
  "#...#...#..",
  ".#....#..#.",
  "..#.#...#.#",
  ".#...##..#.",
  "..#.##.....",
  ".#.#.#....#",
  ".#........#",
  "#.##...#...",
  "#...##....#",
  ".#..#...#.#"
};
// clang-format on

int main() {
  using namespace aoc2020::day3;
  using namespace boost::ut;

  "input"_test = [&] {
    std::stringstream in{"....\n####\n..##\n##..\n"};
    const auto g = input(in);
    expect(g == geography_t{"....", "####", "..##", "##.."});
  };

  "example"_test = [&] {
    const auto trees = part1(example_rows);
    expect(7_u == trees);
  };

  "right 1, down 1"_test = [&] {
    const auto trees = navigate(example_rows, 1, 1);
    expect(2_u == trees);
  };

  "right 3, down 1"_test = [&] {
    const auto trees = navigate(example_rows, 3, 1);
    expect(7_u == trees);
  };

  "right 5, down 1"_test = [&] {
    const auto trees = navigate(example_rows, 5, 1);
    expect(3_u == trees);
  };

  "right 7, down 1"_test = [&] {
    const auto trees = navigate(example_rows, 7, 1);
    expect(4_u == trees);
  };

  "right 1, down 2"_test = [&] {
    const auto trees = navigate(example_rows, 1, 2);
    expect(2_u == trees);
  };

  "example part2"_test = [&] {
    const auto result = part2(example_rows);
    expect(336_u == result);
  };
}
