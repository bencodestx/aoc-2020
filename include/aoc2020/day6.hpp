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

auto part2(std::istream &in) {
  std::string line;
  std::bitset<26> all_yes{};
  all_yes.set();
  size_t sum{};
  while (std::getline(in, line)) {
    if (std::empty(line)) {
      sum += all_yes.count();
      all_yes.set();
    } else {
      std::bitset<26> yes{};
      std::for_each(std::cbegin(line), std::cend(line), [&yes](const auto c) {
        yes.set(static_cast<size_t>(c - 'a'));
      });
      all_yes &= yes;
    }
  }
  return sum + all_yes.count();
}

} // namespace aoc2020::day6
