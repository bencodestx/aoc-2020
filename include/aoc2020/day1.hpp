#pragma once

#include <algorithm>
#include <istream>
#include <optional>
#include <vector>

namespace aoc2020::day1 {

static constexpr auto input = [](std::istream &in) {
  std::vector<int> values{};
  int value;
  while (in >> value) {
    values.push_back(value);
  }
  return values;
};

namespace detail {
template <typename Iter> struct solver final {
  template <size_t Depth>
  static std::optional<int> solve(Iter begin, Iter end, const int target) {
    for (auto it = begin; it != end; ++it) {
      const auto child_answer = solve<Depth - 1>(it + 1, end, target - *it);
      if (child_answer.has_value()) {
        return *child_answer * *it;
      }
    }
    return std::nullopt;
  }

  template <>
  static std::optional<int> solve<1>(Iter begin, Iter end, const int target) {
    if (const auto it = std::find(begin, end, target); end != it) {
      return *it;
    } else {
      return std::nullopt;
    }
  }
};

template <size_t Depth>
static constexpr auto solve = [](const auto &expenses) {
  using solver_t = detail::solver<decltype(std::end(expenses))>;

  const auto solution = solver_t::template solve<Depth>(
      std::begin(expenses), std::end(expenses), 2020);

  if (not solution.has_value()) {
    throw std::runtime_error("No solution found");
  }
  return *solution;
};
} // namespace detail

static constexpr auto part1 = [](const auto &expenses) {
  return detail::solve<2>(expenses);
};

static constexpr auto part2 = [](const auto &expenses) {
  return detail::solve<3>(expenses);
};
} // namespace aoc2020::day1
