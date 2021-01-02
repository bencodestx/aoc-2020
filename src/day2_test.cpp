#include "aoc2020/day2.hpp"

#include <boost/ut.hpp>

#include <sstream>

int main() {
  using namespace aoc2020::day2;
  using namespace boost::ut;

  const std::string example_passwords{
      R"(1-3 a: abcde
1-3 b: cdefg
2-9 c: ccccccccc)"};

  "input"_test = [&] {
    std::stringstream in(example_passwords);
    const auto actual = input<sled_rental_policy_t>(in);
    const passwords_and_policies_t<sled_rental_policy_t> expected = {
        {.password = "abcde",
         .policy = {.lowest = 1, .highest = 3, .letter = 'a'}},
        {.password = "cdefg",
         .policy = {.lowest = 1, .highest = 3, .letter = 'b'}},
        {.password = "ccccccccc",
         .policy = {.lowest = 2, .highest = 9, .letter = 'c'}}};
    expect(actual == expected);
  };

  "empty password"_test = [&] {
    const sled_rental_policy_t policy = {
        .lowest = 1, .highest = 1, .letter = 'a'};
    const password_t password = "";

    expect(not policy.validate(password));
  };

  "trivial password - match"_test = [&] {
    const sled_rental_policy_t policy = {
        .lowest = 1, .highest = 1, .letter = 'a'};
    const password_t password = "a";

    expect(policy.validate(password));
  };

  "trivial password - not match"_test = [&] {
    const sled_rental_policy_t policy = {
        .lowest = 1, .highest = 1, .letter = 'a'};
    const password_t password = "b";

    expect(not policy.validate(password));
  };

  "lowest 0 matches when letter not present"_test = [&] {
    const sled_rental_policy_t policy = {
        .lowest = 0, .highest = 1, .letter = 'a'};
    const password_t password = "b";

    expect(policy.validate(password));
  };

  "highest 0 does not match when letter present"_test = [&] {
    const sled_rental_policy_t policy = {
        .lowest = 1, .highest = 0, .letter = 'a'};
    const password_t password = "a";

    expect(not policy.validate(password));
  };

  "sample data passes part1"_test = [&] {
    std::stringstream in(example_passwords);
    const auto valid_passwords = part1(input<sled_rental_policy_t>(in));
    expect(2_i == valid_passwords);
  };

  "part2 input"_test = [&] {
    std::stringstream in(example_passwords);
    const auto actual = input<toboggan_rental_policy_t>(in);
    const passwords_and_policies_t<toboggan_rental_policy_t> expected = {
        {.password = "abcde",
         .policy = {.first_position = 1, .second_position = 3, .letter = 'a'}},
        {.password = "cdefg",
         .policy = {.first_position = 1, .second_position = 3, .letter = 'b'}},
        {.password = "ccccccccc",
         .policy = {.first_position = 2, .second_position = 9, .letter = 'c'}}};
    expect(actual == expected);
  };

  "part2, first example"_test = [&] {
    std::stringstream in{"1-3 a: abcde"};
    password_and_policy_t<toboggan_rental_policy_t> row;
    in >> row;
    expect(row.policy.validate(row.password));
  };

  "part2, second example"_test = [&] {
    std::stringstream in{"1-3 b: cdefg"};
    password_and_policy_t<toboggan_rental_policy_t> row;
    in >> row;
    expect(not row.policy.validate(row.password));
  };

  "part2, third example"_test = [&] {
    std::stringstream in{"2-9 c: ccccccccc"};
    password_and_policy_t<toboggan_rental_policy_t> row;
    in >> row;
    expect(not row.policy.validate(row.password));
  };

  "part2 can match the second character when the first does not"_test = [&] {
    std::stringstream in{"3-1 a: abcde"};
    password_and_policy_t<toboggan_rental_policy_t> row;
    in >> row;
    expect(row.policy.validate(row.password));
  };
}
