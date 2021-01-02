#include <boost/ut.hpp>

#include <algorithm>
#include <cassert>
#include <istream>
#include <sstream>
#include <string>
#include <vector>

namespace aoc2020::day2 {
using password_t = std::string;

struct policy_t final {
  ssize_t lowest{};
  ssize_t highest{};
  char letter{};

  bool operator==(const policy_t &rhs) const {
    return lowest == rhs.lowest and highest == rhs.highest and
           letter == rhs.letter;
  }

  bool validate(const password_t &password) const {
    const auto count =
        std::count(std::begin(password), std::end(password), letter);
    return count >= lowest and count <= highest;
  }
};

struct password_and_policy_t final {
  password_t password{};
  policy_t policy{};

  bool operator==(const password_and_policy_t &rhs) const {
    return password == rhs.password and policy == rhs.policy;
  }
};

using passwords_and_policies_t = std::vector<password_and_policy_t>;

std::istream &operator>>(std::istream &is, policy_t &policy) {
  char dash;
  char colon;

  if (is >> policy.lowest >> dash >> policy.highest >> policy.letter >> colon) {
    assert(dash == '-');
    assert(colon == ':');
  }

  return is;
}

std::istream &operator>>(std::istream &is, password_and_policy_t &row) {
  is >> row.policy >> row.password;
  return is;
}

auto input(std::istream &is) {
  passwords_and_policies_t result{};
  password_and_policy_t row;
  while (is >> row) {
    result.push_back(row);
  }
  return result;
}

auto part1(const auto &input) {
  return std::count_if(std::begin(input), std::end(input), [](const auto &row) {
    return row.policy.validate(row.password);
  });
}
} // namespace aoc2020::day2

int main() {
  using namespace aoc2020::day2;
  using namespace boost::ut;

  const std::string example_passwords{
      R"(1-3 a: abcde
1-3 b: cdefg
2-9 c: ccccccccc)"};

  "input"_test = [&] {
    std::stringstream in(example_passwords);
    const auto actual = input(in);
    const passwords_and_policies_t expected = {
        {.password = "abcde",
         .policy = {.lowest = 1, .highest = 3, .letter = 'a'}},
        {.password = "cdefg",
         .policy = {.lowest = 1, .highest = 3, .letter = 'b'}},
        {.password = "ccccccccc",
         .policy = {.lowest = 2, .highest = 9, .letter = 'c'}}};
    expect(actual == expected);
  };

  "empty password"_test = [&] {
    const policy_t policy = {.lowest = 1, .highest = 1, .letter = 'a'};
    const password_t password = "";

    expect(not policy.validate(password));
  };

  "trivial password - match"_test = [&] {
    const policy_t policy = {.lowest = 1, .highest = 1, .letter = 'a'};
    const password_t password = "a";

    expect(policy.validate(password));
  };

  "trivial password - not match"_test = [&] {
    const policy_t policy = {.lowest = 1, .highest = 1, .letter = 'a'};
    const password_t password = "b";

    expect(not policy.validate(password));
  };

  "lowest 0 matches when letter not present"_test = [&] {
    const policy_t policy = {.lowest = 0, .highest = 1, .letter = 'a'};
    const password_t password = "b";

    expect(policy.validate(password));
  };

  "highest 0 does not match when letter present"_test = [&] {
    const policy_t policy = {.lowest = 1, .highest = 0, .letter = 'a'};
    const password_t password = "a";

    expect(not policy.validate(password));
  };

  "sample data passes part1"_test = [&] {
    std::stringstream in(example_passwords);
    const auto valid_passwords = part1(input(in));
    expect(2_i == valid_passwords);
  };
}
