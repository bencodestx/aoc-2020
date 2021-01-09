#pragma once

#include <istream>
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

auto part1(std::istream &) { return "stub"; }

auto part2(std::istream &) { return "stub"; }

} // namespace aoc2020::day7
