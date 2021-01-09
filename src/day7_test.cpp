#include "aoc2020/day7.hpp"

#include <boost/ut.hpp>

#include <sstream>

const std::string example{
    R"(light red bags contain 1 bright white bag, 2 muted yellow bags.
dark orange bags contain 3 bright white bags, 4 muted yellow bags.
bright white bags contain 1 shiny gold bag.
muted yellow bags contain 2 shiny gold bags, 9 faded blue bags.
shiny gold bags contain 1 dark olive bag, 2 vibrant plum bags.
dark olive bags contain 3 faded blue bags, 4 dotted black bags.
vibrant plum bags contain 5 faded blue bags, 6 dotted black bags.
faded blue bags contain no other bags.
dotted black bags contain no other bags.)"};

const std::string second_example{
    R"(shiny gold bags contain 2 dark red bags.
dark red bags contain 2 dark orange bags.
dark orange bags contain 2 dark yellow bags.
dark yellow bags contain 2 dark green bags.
dark green bags contain 2 dark blue bags.
dark blue bags contain 2 dark violet bags.
dark violet bags contain no other bags.)"};

int main() {
  using namespace aoc2020::day7;
  using namespace boost::ut;

  std::stringstream in{example};
  const auto rules = input(in);

  "input"_test = [&] {
    expect(std::size(rules) == 9_u);
    expect(rules.at("light red").contents ==
           contents_list_t{{1, "bright white"}, {2, "muted yellow"}});
    expect(rules.at("dark orange").contents ==
           contents_list_t{{3, "bright white"}, {4, "muted yellow"}});
    expect(rules.at("bright white").contents ==
           contents_list_t{{1, "shiny gold"}});
    expect(rules.at("muted yellow").contents ==
           contents_list_t{{2, "shiny gold"}, {9, "faded blue"}});
    expect(rules.at("shiny gold").contents ==
           contents_list_t{{1, "dark olive"}, {2, "vibrant plum"}});
    // ...
    expect(rules.at("dotted black").contents == contents_list_t{});
  };

  "bright white"_test = [&] {
    expect(can_contain(rules, "shiny gold", "bright white"));
  };

  "muted yellow"_test = [&] {
    expect(can_contain(rules, "shiny gold", "muted yellow"));
  };

  "dark orange"_test = [&] {
    expect(can_contain(rules, "shiny gold", "dark orange"));
  };

  "light red"_test = [&] {
    expect(can_contain(rules, "shiny gold", "light red"));
  };

  "part1 example"_test = [&] { expect(4_u == part1(rules)); };

  "part2 initial example"_test = [&] { expect(32_u == part2(rules)); };

  "part2 second example"_test = [&] {
    std::stringstream second_in{second_example};
    expect(126_u == part2(input(second_in)));
  };
}
