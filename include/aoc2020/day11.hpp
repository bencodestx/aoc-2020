#pragma once

#include <istream>
#include <vector>
namespace aoc2020::day11 {

auto input(std::istream &in) {
  std::vector<std::string> result{};
  std::string line{};
  while (std::getline(in, line)) {
    result.push_back(line);
  }
  return result;
}

auto part1(std::istream &) { return "stub"; }

auto part2(std::istream &) { return "stub"; }

} // namespace aoc2020::day11
