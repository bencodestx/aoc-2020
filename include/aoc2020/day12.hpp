#pragma once

#include <cmath>
#include <istream>
#include <string>

namespace aoc2020::day12 {

struct ship_t final {
  ssize_t x{};
  ssize_t y{};
  ssize_t direction{};

  void apply(const std::string operation) {
    const auto opcode = operation[0];
    const auto arg = std::stoi(operation.substr(1));
    switch (opcode) {
    case 'N':
      y -= arg;
      break;
    case 'S':
      y += arg;
      break;
    case 'E':
      x += arg;
      break;
    case 'W':
      x -= arg;
      break;
    case 'R':
      direction += arg;
      direction %= 360;
      break;
    case 'L':
      direction += 360;
      direction -= arg;
      direction %= 360;
      break;
    case 'F':
      switch (direction) {
      case 0:
        x += arg;
        break;
      case 90:
        y += arg;
        break;
      case 180:
        x -= arg;
        break;
      case 270:
        y -= arg;
        break;
      default:
        throw std::runtime_error("Invalid direction");
      }
      break;
    default:
      throw std::runtime_error("Unknown operation");
    }
  }

  ssize_t manhattan_distance() const { return std::abs(x) + std::abs(y); }
};

auto part1(std::istream &in) {
  ship_t ship{};
  std::string operation{};
  while (in >> operation) {
    ship.apply(operation);
  }
  return ship.manhattan_distance();
}

auto part2(std::istream &) { return 0; }

} // namespace aoc2020::day12
