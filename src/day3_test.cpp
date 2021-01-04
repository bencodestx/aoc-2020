#include <boost/ut.hpp>

#include <iterator>
#include <string>
#include <tuple>
#include <vector>

namespace aoc2020::day3 {
using geography_t = std::vector<std::string>;

using position_t = std::pair<size_t, size_t>;
size_t &row(position_t &p) { return p.second; }
size_t &col(position_t &p) { return p.first; }
size_t row(const position_t &p) { return p.second; }
size_t col(const position_t &p) { return p.first; }

bool is_tree(const position_t p, const geography_t &g) {
  return g[row(p)][col(p)] == '#';
}

bool is_done(const position_t p, const geography_t &g) {
  return row(p) == std::size(g);
}

position_t toboggan_move(position_t p, const geography_t &g) {
  col(p) += 3;
  col(p) %= std::size(g[row(p)]);
  ++row(p);
  return p;
}

static constexpr auto part1 = [](const geography_t &g) {
  position_t p{};
  size_t count{};
  while (not is_done(p, g)) {
    if (is_tree(p, g)) {
      ++count;
    }
    p = toboggan_move(p, g);
  }
  return count;
};

} // namespace aoc2020::day3

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

  "example"_test = [&] {
    const auto trees = part1(example_rows);
    expect(7_u == trees);
  };
}
