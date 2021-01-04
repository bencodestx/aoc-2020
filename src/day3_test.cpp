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
}
