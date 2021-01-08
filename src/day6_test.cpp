#include "aoc2020/day6.hpp"

#include <boost/ut.hpp>

#include <sstream>

int main() {
  using namespace aoc2020::day6;
  using namespace boost::ut;

  "in this group there are 6 questions to which anyone answered yes"_test =
      [&] {
        std::stringstream example_group{"abcx\nabcy\nabcz"};
        expect(6_u == part1(example_group));
      };

  "in this example the sum of these counts is 3 + 3 + 3 + 1 + 1 = 11"_test =
      [&] {
        std::stringstream example_groups{
            "abc\n\na\nb\nc\n\nab\nac\n\na\na\na\na\n\nb"};
        expect(11_u == part1(example_groups));
      };

  "part2 in this example the sum of these counts is 3 + 0 + 1 + 1 + 1 = 6"_test =
      [&] {
        std::stringstream example_groups{
            "abc\n\na\nb\nc\n\nab\nac\n\na\na\na\na\n\nb"};
        expect(6_u == part2(example_groups));
      };
}
