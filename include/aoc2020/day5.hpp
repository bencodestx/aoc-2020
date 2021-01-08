#pragma once

#include <istream>
#include <string>
#include <string_view>
#include <tuple>

namespace aoc2020::day5 {
using range_t = std::pair<size_t, size_t>;
using location_t = std::pair<size_t, size_t>;

range_t take(const char direction, const range_t x) {
  if (direction == 'F' or direction == 'L') {
    return {x.first, x.second - (x.second - x.first + 1) / 2};
  } else {
    return {x.first + (x.second - x.first + 1) / 2, x.second};
  }
}

location_t locate(const std::string_view pass) {
  range_t row{0, 127};
  for (size_t i = 0; i < 7; ++i) {
    row = take(pass[i], row);
  }

  range_t col{0, 7};
  for (size_t i = 7; i < 10; ++i) {
    col = take(pass[i], col);
  }

  return {row.first, col.first};
};

size_t seatid(const location_t location) {
  return location.first * 8u + location.second;
}

size_t part1(std::istream &in) {
  size_t highest{0u};
  std::string pass;
  while (in >> pass) {
    highest = std::max(highest, seatid(locate(pass)));
  }
  return highest;
}

} // namespace aoc2020::day5
