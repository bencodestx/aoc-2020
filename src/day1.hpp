#pragma once

#include <algorithm>
#include <istream>
#include <optional>
#include <vector>

static constexpr auto day1_input = [](std::istream &in) {
  std::vector<int> values{};
  int value;
  while (in >> value) {
    values.push_back(value);
  }
  return values;
};

template <typename Iter> struct day1_solver final {
  template <size_t Depth>
  std::optional<int> solve(Iter begin, Iter end, const int target) {
    for (auto it = begin; it != end; ++it) {
      const auto child_answer = solve<Depth - 1>(it + 1, end, target - *it);
      if (child_answer.has_value()) {
        return *child_answer * *it;
      }
    }
    return std::nullopt;
  }

  template <>
  std::optional<int> solve<1>(Iter begin, Iter end, const int target) {
    if (const auto it = std::find(begin, end, target); end != it) {
      return *it;
    } else {
      return std::nullopt;
    }
  }
};

template <size_t Depth>
static constexpr auto day1 = [](const auto &expenses) {
  day1_solver<decltype(std::end(expenses))> solver{};
  const auto solution = solver.template solve<Depth>(std::begin(expenses),
                                                     std::end(expenses), 2020);
  if (not solution.has_value()) {
    throw std::runtime_error("No solution found");
  }
  return *solution;
};

static constexpr auto day1_part1 = [](const auto &expenses) {
  return day1<2>(expenses);
};

static constexpr auto day1_part2 = [](const auto &expenses) {
  return day1<3>(expenses);
};
