#pragma once

#include <cstdint>
#include <istream>
#include <stdexcept>
#include <vector>

namespace aoc2020::day8 {

enum class operation_t : std::uint8_t { nop, acc, jmp };

using argument_t = std::int64_t;

struct instruction_t final {
  operation_t operation{};
  argument_t argument{};
};

std::istream &operator>>(std::istream &in, operation_t &operation) {
  std::string opcode{};
  if (in >> opcode) {
    if (opcode == "nop") {
      operation = operation_t::nop;
    } else if (opcode == "acc") {
      operation = operation_t::acc;
    } else if (opcode == "jmp") {
      operation = operation_t::jmp;
    } else {
      throw std::runtime_error("Unknown opcode: '" + opcode + "'");
    }
  }
  return in;
}

std::istream &operator>>(std::istream &in, instruction_t &instruction) {
  return (in >> instruction.operation >> instruction.argument);
}

using program_t = std::vector<instruction_t>;

auto input(std::istream &in) {
  instruction_t instruction{};
  program_t program{};
  while (in >> instruction) {
    program.push_back(instruction);
  }
  return program;
}

auto part1(const auto &) { return "stub"; }

auto part2(const auto &) { return "stub"; }

} // namespace aoc2020::day8
