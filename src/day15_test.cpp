#include "aoc2020/day15.hpp"

#include <sstream>

#include <boost/ut.hpp>

int main() {
  using namespace aoc2020::day15;
  using namespace boost::ut;

  "For example, suppose the starting numbers are 0,3,6"_test = [&] {
    memory_game game(10);
    game.speak(0u);
    game.speak(3u);
    game.speak(6u);

    expect(0_u == game.speak_next());
    expect(3_u == game.speak_next());
    expect(3_u == game.speak_next());
    expect(1_u == game.speak_next());
    expect(0_u == game.speak_next());
    expect(4_u == game.speak_next());
    expect(0_u == game.speak_next());
  };

  "Given the starting numbers 0,3,6, the 10th number spoken is 0."_test = [&] {
    std::stringstream in{"0,3,6"};
    expect(0_u == play_game(in, 10u));
  };

  "Given the starting numbers 1,3,2, the 2020th number spoken is 1."_test =
      [&] {
        std::stringstream in{"1,3,2"};
        expect(1_u == part1(in));
      };

  "Given the starting numbers 2,1,3, the 2020th number spoken is 10."_test =
      [&] {
        std::stringstream in{"2,1,3"};
        expect(10_u == part1(in));
      };

  "Given the starting numbers 1,2,3, the 2020th number spoken is 27."_test =
      [&] {
        std::stringstream in{"1,2,3"};
        expect(27_u == part1(in));
      };

  "Given the starting numbers 2,3,1, the 2020th number spoken is 78."_test =
      [&] {
        std::stringstream in{"2,3,1"};
        expect(78_u == part1(in));
      };

  "Given the starting numbers 3,2,1, the 2020th number spoken is 438."_test =
      [&] {
        std::stringstream in{"3,2,1"};
        expect(438_u == part1(in));
      };

  "Given the starting numbers 3,1,2, the 2020th number spoken is 1836."_test =
      [&] {
        std::stringstream in{"3,1,2"};
        expect(1836_u == part1(in));
      };

  "Given the starting numbers 0,3,6, the 30000000th number spoken is 175594."_test =
      [&] {
        std::stringstream in{"0,3,6"};
        expect(175594_u == part2(in));
      };

  "Given the starting numbers 1,3,2, the 30000000th number spoken is 2578."_test =
      [&] {
        std::stringstream in{"1,3,2"};
        expect(2578_u == part2(in));
      };

  "Given the starting numbers 2,1,3, the 30000000th number spoken is 3544142."_test =
      [&] {
        std::stringstream in{"2,1,3"};
        expect(3544142_u == part2(in));
      };

  "Given the starting numbers 1,2,3, the 30000000th number spoken is 261214."_test =
      [&] {
        std::stringstream in{"1,2,3"};
        expect(261214_u == part2(in));
      };

  "Given the starting numbers 2,3,1, the 30000000th number spoken is 6895259."_test =
      [&] {
        std::stringstream in{"2,3,1"};
        expect(6895259_u == part2(in));
      };

  "Given the starting numbers 3,2,1, the 30000000th number spoken is 18."_test =
      [&] {
        std::stringstream in{"3,2,1"};
        expect(18_u == part2(in));
      };

  "Given the starting numbers 3,1,2, the 30000000th number spoken is 362."_test =
      [&] {
        std::stringstream in{"3,1,2"};
        expect(362_u == part2(in));
      };
}
