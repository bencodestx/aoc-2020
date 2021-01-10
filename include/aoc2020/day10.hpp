#pragma once

#include <algorithm>
#include <array>
#include <istream>
#include <iterator>
#include <vector>

#include <iostream>

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

size_t count_paths_to(const size_t output, auto begin, const auto end,
                      std::unordered_map<size_t, size_t> &cache) {
  if (const auto it = cache.find(output); std::end(cache) != it) {
    return it->second;
  }
  if (begin == end) {
    return 1;
  }
  size_t paths{0};
  while ((begin != end) and ((output - *begin) <= 3)) {
    paths += count_paths_to(*begin, begin + 1, end, cache);
    ++begin;
  }
  cache[output] = paths;
  return paths;
}

auto part2(std::istream &in) {
  auto ratings = input(in);
  ratings.push_back(0);
  std::sort(std::begin(ratings), std::end(ratings));

  std::unordered_map<size_t, size_t> cache{};
  return count_paths_to(ratings.back() + 3, std::rbegin(ratings),
                        std::rend(ratings), cache);
}

} // namespace aoc2020::day10
