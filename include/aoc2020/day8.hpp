#pragma once

#include <cstdint>
#include <istream>
#include <stdexcept>
#include <vector>

namespace aoc2020::day8 {

enum class operation_t : std::uint8_t { nop, acc, jmp };

using argument_t = std::int64_t;
using accumulator_t = std::int64_t;
using next_instruction_t = std::int64_t;

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

struct computer_t final {
  program_t program{};
  next_instruction_t next_instruction{};
  accumulator_t accumulator{};
};

auto input(std::istream &in) {
  instruction_t instruction{};
  program_t program{};
  while (in >> instruction) {
    program.push_back(instruction);
  }
  return program;
}

auto index(next_instruction_t next_instruction) {
  return static_cast<size_t>(next_instruction);
}

void step(computer_t &computer) {
  const auto &instruction = computer.program[index(computer.next_instruction)];
  switch (instruction.operation) {
  case operation_t::nop:
    ++computer.next_instruction;
    break;
  case operation_t::acc:
    computer.accumulator += instruction.argument;
    ++computer.next_instruction;
    break;
  case operation_t::jmp:
    computer.next_instruction += instruction.argument;
    break;
  }
}

auto part1(const program_t &program) {
  computer_t computer{.program = program};
  std::vector<bool> instruction_executed{};
  instruction_executed.resize(std::size(program));
  while (not instruction_executed[index(computer.next_instruction)]) {
    instruction_executed[index(computer.next_instruction)] = true;
    step(computer);
  }
  return computer.accumulator;
}

auto part2(const auto &) { return "stub"; }

} // namespace aoc2020::day8
