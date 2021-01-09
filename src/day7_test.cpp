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

int main() {
  using namespace aoc2020::day7;
  using namespace boost::ut;

  "input"_test = [] {
    std::stringstream in{example};
    const auto rules = input(in);

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
}
