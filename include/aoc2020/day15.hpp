#pragma once

#include <string>
#include <unordered_map>

namespace aoc2020::day15 {

struct memory_game {
  size_t current_turn{1u};
  size_t previous_turn_of_last_spoken_number{0u};
  std::unordered_map<size_t, size_t> number_to_previous_turn{};

  auto speak(size_t number) {
    auto &previous_turn = number_to_previous_turn[number];
    previous_turn_of_last_spoken_number = previous_turn;
    previous_turn = current_turn++;
    return number;
  }

  auto speak_next() {
    if (0 == previous_turn_of_last_spoken_number) {
      return speak(0u);
    } else {
      return speak(current_turn - 1u - previous_turn_of_last_spoken_number);
    }
  }
};

auto part1(auto &in, size_t turns = 2020u) {
  memory_game game{};
  size_t number;
  while (in >> number) {
    game.speak(number);
    char comma;
    if (not(in >> comma)) {
      break;
    }
  }
  while (game.current_turn <= turns) {
    number = game.speak_next();
  }
  return number;
}

auto part2(auto &) { return 0u; }

} // namespace aoc2020::day15
