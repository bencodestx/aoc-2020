#pragma once

#include <algorithm>
#include <istream>
#include <vector>

static constexpr auto day1_input = [](std::istream &in) {
  std::vector<int> values{};
  int value;
  while (in >> value) {
    values.push_back(value);
  }
  return values;
};

static constexpr auto day1_part1 = [](const auto &expenses) {
  for (auto it = std::begin(expenses); it != std::end(expenses); ++it) {
    const auto second = std::find_if(it + 1, std::end(expenses),
                                     [first = *it](const auto candidate) {
                                       return first + candidate == 2020;
                                     });
    if (second != std::end(expenses)) {
      return *it * *second;
    }
  }
  throw std::runtime_error("No solution found");
};
