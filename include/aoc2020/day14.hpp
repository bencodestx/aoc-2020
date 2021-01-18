#pragma once

#include <bitset>
#include <cstdint>
#include <iostream>
#include <istream>
#include <string>
#include <unordered_map>

namespace aoc2020::day14 {

struct vm_t {
  std::bitset<64> values{};
  std::bitset<64> bitmask{};
  std::unordered_map<uint64_t, std::bitset<64>> memory{};
};

void mask(vm_t &vm, const std::string_view arg) {
  size_t index = 0;
  for (auto it = std::rbegin(arg); std::rend(arg) != it; it++) {
    switch (*it) {
    case 'X':
      vm.bitmask[index] = true;
      vm.values[index] = false;
      break;
    case '0':
      vm.bitmask[index] = false;
      vm.values[index] = false;
      break;
    case '1':
      vm.bitmask[index] = false;
      vm.values[index] = true;
      break;
    default:
      throw std::runtime_error(std::string{"Invalid bitmask: "} + *it);
    }
    ++index;
  }
}

void mem(vm_t &vm, const std::string op, const std::string arg) {
  const uint64_t addr = std::stoul(op.substr(4, std::size(op) - 1));
  const std::bitset<64> value = std::stoul(arg);

  vm.memory[addr] = vm.values | (value & vm.bitmask);
}

auto part1(std::istream &in) {
  std::string op;
  std::string equals;
  std::string arg;
  vm_t vm{};

  std::cerr << sizeof(unsigned long) << std::endl;

  while (in >> op >> equals >> arg) {
    if (equals != "=") {
      throw std::runtime_error(std::string{"Expecting '=': "} + equals);
    }
    if (op == "mask") {
      mask(vm, arg);
    } else if (0u == op.find("mem[")) {
      mem(vm, op, arg);
    } else {
      throw std::runtime_error(std::string{"Unknown op: "} + op);
    }
  }

  uint64_t sum{0};
  for (const auto &[k, v] : vm.memory) {
    sum += v.to_ulong();
  }
  return sum;
}

auto part2(std::istream &) { return 0u; }

} // namespace aoc2020::day14
