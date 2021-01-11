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

auto goal(const auto &desired_offsets, const auto &departure_times) {
  for (size_t i = 0; i < std::size(desired_offsets); ++i) {
    if (departure_times[i] - departure_times[0] != desired_offsets[i]) {
      return false;
    }
  }
  return true;
}

auto solve(const auto ainit, const auto ainc, const auto binc,
           const auto delta) {
  size_t a{ainit};
  size_t b{0};
  while (a + delta != b) {
    if (a + delta < b) {
      a += std::max(1ul, (b - delta - a) / ainc) * ainc;
    }
    if (a + delta > b) {
      b += std::max(1ul, (a + delta - b) / binc) * binc;
    }
  }
  return a;
}

auto part2(std::istream &in) {
  std::vector<size_t> bus_numbers{};
  std::vector<size_t> desired_offsets{};
  std::string bus{};
  size_t desired_offset{0};
  std::getline(in, bus);
  while (std::getline(in, bus, ',')) {
    if (bus != "x") {
      bus_numbers.push_back(std::stoul(bus));
      desired_offsets.push_back(desired_offset);
    }
    ++desired_offset;
  }
  size_t first_occurrence = 0;
  size_t period = bus_numbers[0];
  for (size_t i = 1; i < std::size(bus_numbers); ++i) {
    first_occurrence =
        solve(first_occurrence, period, bus_numbers[i], desired_offsets[i]);
    const auto second_occruence = solve(first_occurrence + period, period,
                                        bus_numbers[i], desired_offsets[i]);
    period = second_occruence - first_occurrence;
  }
  return first_occurrence;
}

} // namespace aoc2020::day13
