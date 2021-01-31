#include "aoc2020/day15.hpp"

#include <sstream>

#include <boost/ut.hpp>

int main() {
  using namespace aoc2020::day15;
  using namespace boost::ut;

  "For example, suppose the starting numbers are 0,3,6"_test = [&] {
    memory_game game{};
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
    expect(0_u == part1(in, 10u));
  };

  "Given the starting numbers 1,3,2, the 2020th number spoken is 1."_test =
      [&] {
        std::stringstream in{"1,3,2"};
        expect(1_u == part1(in));
      };

  "Given the starting numbers 2,1,3, the 2020th number spoken is 1."_test =
      [&] {
        std::stringstream in{"2,1,3"};
        expect(10_u == part1(in));
      };

  "Given the starting numbers 1,2,3, the 2020th number spoken is 1."_test =
      [&] {
        std::stringstream in{"1,2,3"};
        expect(27_u == part1(in));
      };

  "Given the starting numbers 2,3,1, the 2020th number spoken is 1."_test =
      [&] {
        std::stringstream in{"2,3,1"};
        expect(78_u == part1(in));
      };

  "Given the starting numbers 3,2,1, the 2020th number spoken is 1."_test =
      [&] {
        std::stringstream in{"3,2,1"};
        expect(438_u == part1(in));
      };

  "Given the starting numbers 3,1,2, the 2020th number spoken is 1."_test =
      [&] {
        std::stringstream in{"3,1,2"};
        expect(1836_u == part1(in));
      };

  "part2"_test = [&] {
    std::stringstream in{};
    expect(0_u == part2(in));
  };
}
