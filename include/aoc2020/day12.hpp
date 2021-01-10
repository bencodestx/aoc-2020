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

struct waypoint_t final {
  ssize_t x{10};
  ssize_t y{-1};

  void rotate(ssize_t degrees) {
    switch (degrees % 360) {
    case 0:
      break;
    case 90: {
      const auto new_x = -y;
      const auto new_y = x;
      x = new_x;
      y = new_y;
      break;
    }
    case 180:
      x = -x;
      y = -y;
      break;
    case 270:
      const auto new_x = y;
      const auto new_y = -x;
      x = new_x;
      y = new_y;
      break;
    }
  }

  void apply(const std::string operation, ship_t &ship) {
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
      rotate(arg);
      break;
    case 'L':
      rotate(360 - arg);
      break;
    case 'F':
      ship.x += x * arg;
      ship.y += y * arg;
      break;
    default:
      throw std::runtime_error("Unknown operation");
    }
  }
};

auto part2(std::istream &in) {
  ship_t ship{};
  waypoint_t waypoint{};
  std::string operation{};
  while (in >> operation) {
    waypoint.apply(operation, ship);
  }
  return ship.manhattan_distance();
}

} // namespace aoc2020::day12
