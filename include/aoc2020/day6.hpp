#pragma once

#include <algorithm>
#include <bitset>
#include <istream>
#include <iterator>
#include <string>
namespace aoc2020::day6 {

auto part1(std::istream &in) {
  std::string line;
  std::bitset<26> yes{};
  size_t sum{};
  while (std::getline(in, line)) {
    if (std::empty(line)) {
      sum += yes.count();
      yes.reset();
    } else {
      std::for_each(std::cbegin(line), std::cend(line), [&yes](const auto c) {
        yes.set(static_cast<size_t>(c - 'a'));
      });
    }
  }
  return sum + yes.count();
}

auto part2(std::istream &) { return "stub"; }

} // namespace aoc2020::day6
