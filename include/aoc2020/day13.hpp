#pragma once

#include <algorithm>
#include <istream>
#include <string>
#include <vector>

namespace aoc2020::day13 {

auto part1(std::istream &in) {
  size_t earliest_departure{};
  std::vector<size_t> bus_numbers{};
  in >> earliest_departure;
  std::string bus{};
  while (std::getline(in, bus, ',')) {
    if (bus != "x") {
      bus_numbers.push_back(std::stoul(bus));
    }
  }
  std::vector<size_t> departure_times{bus_numbers};
  while (true) {
    const auto min_element = std::min_element(std::begin(departure_times),
                                              std::end(departure_times));
    const auto index = static_cast<size_t>(
        std::distance(std::begin(departure_times), min_element));
    if (*min_element >= earliest_departure) {
      return (*min_element - earliest_departure) * bus_numbers[index];
    }
    *min_element += bus_numbers[index];
  }
}

auto part2(std::istream &) { return 0u; }

} // namespace aoc2020::day13
