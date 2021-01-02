#pragma once

#include <algorithm>
#include <cassert>
#include <istream>
#include <string>
#include <vector>

namespace aoc2020::day2 {
using password_t = std::string;

struct sled_rental_policy_t final {
  ssize_t lowest{};
  ssize_t highest{};
  char letter{};

  bool operator==(const sled_rental_policy_t &rhs) const {
    return lowest == rhs.lowest and highest == rhs.highest and
           letter == rhs.letter;
  }

  bool validate(const password_t &password) const {
    const auto count =
        std::count(std::begin(password), std::end(password), letter);
    return count >= lowest and count <= highest;
  }
};

struct toboggan_rental_policy_t final {
  size_t first_position{};
  size_t second_position{};
  char letter{};

  bool operator==(const toboggan_rental_policy_t &rhs) const {
    return first_position == rhs.first_position and
           second_position == rhs.second_position and letter == rhs.letter;
  }

  bool validate(const password_t &password) const {
    return (password[first_position - 1] == letter) ^
           (password[second_position - 1] == letter);
  }
};

template <typename policy_t> struct password_and_policy_t final {
  password_t password{};
  policy_t policy{};

  bool operator==(const password_and_policy_t &rhs) const {
    return password == rhs.password and policy == rhs.policy;
  }
};

template <typename policy_t>
using passwords_and_policies_t = std::vector<password_and_policy_t<policy_t>>;

std::istream &operator>>(std::istream &is, sled_rental_policy_t &policy) {
  char dash;
  char colon;

  if (is >> policy.lowest >> dash >> policy.highest >> policy.letter >> colon) {
    assert(dash == '-');
    assert(colon == ':');
  }

  return is;
}

std::istream &operator>>(std::istream &is, toboggan_rental_policy_t &policy) {
  char dash;
  char colon;

  if (is >> policy.first_position >> dash >> policy.second_position >>
      policy.letter >> colon) {
    assert(dash == '-');
    assert(colon == ':');
  }

  return is;
}

template <typename policy_t>
std::istream &operator>>(std::istream &is,
                         password_and_policy_t<policy_t> &row) {
  is >> row.policy >> row.password;
  return is;
}

template <typename policy_t> auto input(std::istream &is) {
  passwords_and_policies_t<policy_t> result{};
  password_and_policy_t<policy_t> row;
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
