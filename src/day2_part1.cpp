#include "aoc2020/day2.hpp"

#include <iostream>

int main() {
  using namespace aoc2020::day2;

  std::cout << part1(input<sled_rental_policy_t>(std::cin)) << std::endl;

  return {};
}