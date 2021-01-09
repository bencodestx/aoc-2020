#pragma once

#include <algorithm>
#include <array>
#include <istream>
#include <iterator>
#include <vector>

namespace aoc2020::day10 {

auto input(std::istream &in) {
  std::vector<size_t> ratings{};
  size_t rating{};
  while (in >> rating) {
    ratings.push_back(rating);
  }
  return ratings;
}

auto part1(std::istream &in) {
  auto ratings = input(in);
  std::sort(std::begin(ratings), std::end(ratings));
  ratings.push_back(ratings.back() + 3);

  std::array<size_t, 3> counts{};
  size_t last_rating{};
  std::for_each(std::begin(ratings), std::end(ratings), [&](const auto rating) {
    const auto diff = rating - last_rating;
    counts[diff - 1]++;
    last_rating = rating;
  });
  return counts[0] * counts[2];
}

auto part2(std::istream &) { return 0u; }

} // namespace aoc2020::day10
