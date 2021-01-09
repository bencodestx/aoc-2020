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

template <size_t Target> auto part2(std::istream &in) {
  std::vector<size_t> numbers{};
  size_t number{};
  while (in >> number) {
    numbers.push_back(number);
  }

  for (size_t iteration = 0; iteration < std::size(numbers); ++iteration) {
    size_t min{numbers[0]};
    size_t max{numbers[0]};
    size_t accumulator{numbers[0]};
    for (size_t i = 1; i < std::size(numbers); ++i) {
      accumulator += numbers[i];
      min = std::min(min, numbers[i]);
      max = std::max(max, numbers[i]);
      if (accumulator == Target) {
        return min + max;
      } else if (accumulator > Target) {
        break;
      }
    }
    std::rotate(std::begin(numbers), std::begin(numbers) + 1,
                std::end(numbers));
  }

  throw std::runtime_error("No solution found");
}

} // namespace aoc2020::day9
