#include "aoc2020/day8.hpp"

#include <boost/ut.hpp>

const std::string example_text{
    R"(nop +0
acc +1
jmp +4
acc +3
jmp -3
acc -99
acc +1
jmp -4
acc +6)"};

int main() {
  using namespace aoc2020::day8;
  using namespace boost::ut;

  "input"_test = [&] {
    std::stringstream in{example_text};
    const auto program = input(in);
    expect(9_u == std::size(program));
  };
}
