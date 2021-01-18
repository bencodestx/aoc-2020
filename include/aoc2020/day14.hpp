#pragma once

#include <bitset>
#include <cstdint>
#include <istream>
#include <string>
#include <unordered_map>
#include <vector>

namespace aoc2020::day14 {

template <typename TUpdateMemoryPolicy> struct vm_t {
  std::bitset<64> is_1{};
  std::bitset<64> is_x{};
  std::unordered_map<uint64_t, uint64_t> memory{};

  void mask(const std::string_view arg) {
    is_1.reset();
    is_x.reset();
    size_t index = 0;
    for (auto it = std::rbegin(arg); std::rend(arg) != it; it++) {
      switch (*it) {
      case 'X':
        is_x[index] = true;
        break;
      case '1':
        is_1[index] = true;
        break;
      }
      ++index;
    }
  }

  void mem(const std::string op, const std::string arg) {
    TUpdateMemoryPolicy::mem(*this, std::stoul(op.substr(4, std::size(op) - 1)),
                             std::stoul(arg));
  }

  uint64_t sum_memory() const {
    uint64_t sum{0};
    for (const auto &[address, value] : memory) {
      sum += value;
    }
    return sum;
  }
};

struct part1_policy {
  static void mem(auto &vm, const uint64_t addr, const uint64_t val) {
    const std::bitset<64> value{val};

    vm.memory[addr] = (vm.is_1 | (value & vm.is_x)).to_ulong();
  }
};

auto part1(std::istream &in) {
  std::string op;
  std::string equals;
  std::string arg;
  vm_t<part1_policy> vm{};

  while (in >> op >> equals >> arg) {
    if (equals != "=") {
      throw std::runtime_error(std::string{"Expecting '=': "} + equals);
    }
    if (op == "mask") {
      vm.mask(arg);
    } else if (0u == op.find("mem[")) {
      vm.mem(op, arg);
    } else {
      throw std::runtime_error(std::string{"Unknown op: "} + op);
    }
  }

  return vm.sum_memory();
}

struct part2_policy {
  static void mem(auto &vm, const uint64_t addr, const uint64_t value) {
    std::bitset<64> base_addr{addr};
    std::vector<size_t> floating_bit_offsets{};

    for (size_t index = 0; index < 64; ++index) {
      if (vm.is_1[index]) {
        base_addr[index] = true;
      } else if (vm.is_x[index]) {
        floating_bit_offsets.push_back(index);
      }
    }

    for (uint64_t floating_value = 0;
         floating_value < (1ul << std::size(floating_bit_offsets));
         ++floating_value) {
      auto floating_addr = base_addr;
      const std::bitset<64> floating_value_bits{floating_value};
      for (size_t floating_bit_index = 0;
           floating_bit_index < std::size(floating_bit_offsets);
           ++floating_bit_index) {
        floating_addr[floating_bit_offsets[floating_bit_index]] =
            floating_value_bits[floating_bit_index];
      }
      if (0 == value) {
        vm.memory.erase(floating_addr.to_ulong());
      } else {
        vm.memory[floating_addr.to_ulong()] = value;
      }
    }
  }
};

auto part2(std::istream &in) {
  std::string op;
  std::string equals;
  std::string arg;
  vm_t<part2_policy> vm{};

  while (in >> op >> equals >> arg) {
    if (equals != "=") {
      throw std::runtime_error(std::string{"Expecting '=': "} + equals);
    }
    if (op == "mask") {
      vm.mask(arg);
    } else if (0u == op.find("mem[")) {
      vm.mem(op, arg);
    } else {
      throw std::runtime_error(std::string{"Unknown op: "} + op);
    }
  }

  return vm.sum_memory();
}

} // namespace aoc2020::day14
