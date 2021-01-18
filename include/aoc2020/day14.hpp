#pragma once

#include <bitset>
#include <cstdint>
#include <istream>
#include <string>
#include <unordered_map>
#include <vector>

namespace aoc2020::day14 {

using bitset = std::bitset<64>;

template <typename TUpdateMemoryPolicy> struct vm_t {
  bitset is_1{};
  bitset is_x{};
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
      case '0':
        break;
      default:
        throw std::runtime_error(std::string{"Invalid bit: "} + *it);
      }
      ++index;
    }
  }

  void mem(const std::string op, const std::string arg) {
    TUpdateMemoryPolicy::mem(*this, std::stoul(op.substr(4, std::size(op) - 1)),
                             std::stoul(arg));
  }

  auto sum_memory() const {
    uint64_t sum{0};
    for (const auto &[address, value] : memory) {
      sum += value;
    }
    return sum;
  }
};

struct part1_policy {
  static void mem(auto &vm, const auto addr, const auto val) {
    const bitset value{val};

    vm.memory[addr] = (vm.is_1 | (value & vm.is_x)).to_ulong();
  }
};

struct part2_policy {
  static void mem(auto &vm, const auto addr, const auto value) {
    bitset base_addr{addr};
    std::vector<size_t> floating_bit_offsets{};

    update_addr_and_offsets(vm, base_addr, floating_bit_offsets);

    for (uint64_t floating_value = 0;
         floating_value < (1ul << std::size(floating_bit_offsets));
         ++floating_value) {
      auto floating_addr =
          apply_floating_bits(base_addr, floating_value, floating_bit_offsets);

      if (0 == value) {
        vm.memory.erase(floating_addr.to_ulong());
      } else {
        vm.memory[floating_addr.to_ulong()] = value;
      }
    }
  }

private:
  static void update_addr_and_offsets(const auto &vm, auto &addr,
                                      auto &offsets) {
    for (size_t index = 0; index < 64; ++index) {
      if (vm.is_1[index]) {
        addr[index] = true;
      } else if (vm.is_x[index]) {
        offsets.push_back(index);
      }
    }
  }

  static bitset apply_floating_bits(auto base, auto value,
                                    const auto &offsets) {
    auto addr = base;
    const bitset bits{value};
    for (size_t index = 0; index < std::size(offsets); ++index) {
      addr[offsets[index]] = bits[index];
    }
    return addr;
  }
};

template <typename TUpdateMemoryPolicy> auto day14(auto &in) {
  std::string op;
  std::string equals;
  std::string arg;
  vm_t<TUpdateMemoryPolicy> vm{};

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

auto part1(auto &in) { return day14<part1_policy>(in); }

auto part2(auto &in) { return day14<part2_policy>(in); }

} // namespace aoc2020::day14
