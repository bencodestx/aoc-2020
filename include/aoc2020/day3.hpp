#pragma once

#include <istream>
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
  return row(p) >= std::size(g);
}

position_t toboggan_move(position_t p, const geography_t &g, const size_t right,
                         const size_t down) {
  col(p) += right;
  col(p) %= std::size(g[row(p)]);
  row(p) += down;
  return p;
}

static constexpr auto navigate = [](const geography_t &g, const size_t right,
                                    const size_t down) {
  position_t p{};
  size_t count{};
  while (not is_done(p, g)) {
    if (is_tree(p, g)) {
      ++count;
    }
    p = toboggan_move(p, g, right, down);
  }
  return count;
};

static constexpr auto part1 = [](const geography_t &g) {
  return navigate(g, 3, 1);
};

static constexpr auto part2 = [](const geography_t &g) {
  return navigate(g, 1, 1) * navigate(g, 3, 1) * navigate(g, 5, 1) *
         navigate(g, 7, 1) * navigate(g, 1, 2);
};

static constexpr auto input = [](std::istream &in) {
  geography_t g{};
  std::string row;
  while (in >> row) {
    if (not std::empty(row)) {
      g.push_back(row);
    }
  }
  return g;
};

} // namespace aoc2020::day3
