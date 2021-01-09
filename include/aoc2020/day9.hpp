#pragma once

#include "aoc2020/day1.hpp"

#include <istream>
#include <iterator>

namespace aoc2020::day9 {

template <size_t N> auto part1(std::istream &in) {
  std::array<size_t, N> previous{};
  for (auto &x : previous) {
    in >> x;
  }

  size_t current{};
  while (in >> current) {
    using solver_t = day1::detail::solver<decltype(std::cend(previous))>;
    if (not solver_t::template solve<2>(std::cbegin(previous),
                                        std::cend(previous), current)
                .has_value()) {
      return current;
    }
    std::rotate(std::begin(previous), std::begin(previous) + 1,
                std::end(previous));
    previous[N - 1] = current;
  }
  throw std::runtime_error("No solution found");
}

auto part2(std::istream &) { return 0u; }

} // namespace aoc2020::day9
