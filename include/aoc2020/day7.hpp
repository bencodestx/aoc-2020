#pragma once

#include <algorithm>
#include <istream>
#include <numeric>
#include <sstream>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <vector>

namespace aoc2020::day7 {

struct contents_t final {
  size_t count{};
  std::string color{};

  bool operator==(const contents_t &rhs) const {
    return count == rhs.count and color == rhs.color;
  }
};

using contents_list_t = std::vector<contents_t>;
struct rule_t final {
  std::string color{};
  contents_list_t contents{};
};

using rules_t = std::unordered_map<std::string, rule_t>;

std::istream &operator>>(std::istream &in, rule_t &rule) {
  rule.color.clear();
  rule.contents.clear();

  std::string line{};
  if (std::getline(in, line)) {
    std::stringstream tokens{line};
    std::string adjective{};
    std::string color{};
    tokens >> adjective >> color;
    rule.color = adjective + " " + color;
    std::string bags{};
    std::string contain{};
    tokens >> bags >> contain;
    std::string trailer{};
    do {
      contents_t contents{};
      std::string count{};
      tokens >> count >> adjective >> color;
      if (count != "no") {
        contents.count = std::stoul(count);
        contents.color = adjective + " " + color;
        rule.contents.push_back(contents);
        tokens >> trailer;
      } else {
        break;
      }
    } while (trailer == "bag," or trailer == "bags,");
  }
  return in;
}

auto input(std::istream &in) {
  rules_t rules{};
  rule_t rule{};
  while (in >> rule) {
    rules[rule.color] = rule;
  }
  return rules;
}

bool can_contain(const rules_t &rules, const std::string bag,
                 const std::string containing_bag) {
  const auto rule = rules.at(containing_bag);
  return std::any_of(std::begin(rule.contents), std::end(rule.contents),
                     [&](const auto &candidate) {
                       return (candidate.color == bag) or
                              can_contain(rules, bag, candidate.color);
                     });
}

auto part1(const rules_t &rules) {
  return std::count_if(
      std::begin(rules), std::end(rules), [&](const auto &pair) {
        return can_contain(rules, "shiny gold", pair.second.color);
      });
}

size_t count_contents(const rules_t &rules, const std::string bag) {
  const auto &rule = rules.at(bag);
  return std::accumulate(
      std::begin(rule.contents), std::end(rule.contents), size_t{},
      [&](const size_t total, const contents_t &contents) {
        return total + contents.count +
               contents.count * count_contents(rules, contents.color);
      });
};

auto part2(const rules_t &rules) { return count_contents(rules, "shiny gold"); }

} // namespace aoc2020::day7
