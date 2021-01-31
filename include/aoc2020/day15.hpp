#pragma once

#include <string>
#include <vector>

namespace aoc2020::day15 {

struct memory_game {
  size_t current_turn{1u};
  size_t previous_turn_of_last_spoken_number{0u};
  std::vector<size_t> number_to_previous_turn{};

  memory_game(size_t turns) { number_to_previous_turn.resize(turns); }

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

  auto complete_all_turns() {
    size_t last_spoken_number{};
    while (current_turn <= std::size(number_to_previous_turn)) {
      last_spoken_number = speak_next();
    }
    return last_spoken_number;
  }
};

auto play_game(auto &in, size_t turns) {
  memory_game game(turns);
  size_t number;
  while (in >> number) {
    game.speak(number);
    in.get();
  }
  return game.complete_all_turns();
}

auto part1(auto &in) { return play_game(in, 2020u); }

auto part2(auto &in) { return play_game(in, 30'000'000u); }

} // namespace aoc2020::day15
