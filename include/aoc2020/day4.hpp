#pragma once

#include <algorithm>
#include <cctype>
#include <istream>
#include <sstream>
#include <string>
#include <vector>

namespace aoc2020::day4 {

using passport_t = std::string;
using passports_t = std::vector<passport_t>;

static constexpr auto input = [](std::istream &in) {
  passports_t passports{};
  passport_t passport{};
  std::string line;
  while (std::getline(in, line)) {
    if (std::empty(line)) {
      passports.push_back(passport);
      passport = {};
    } else {
      if (not std::empty(passport)) {
        passport += "\n";
      }
      passport += line;
    }
  }
  if (not std::empty(passport)) {
    passports.push_back(passport);
  }
  return passports;
};

static constexpr auto has_key = [](const passport_t &passport,
                                   const std::string &key) {
  return std::string::npos != passport.find(key + ":");
};

static constexpr auto is_valid_part1 = [](const passport_t &passport) {
  return has_key(passport, "byr") and has_key(passport, "iyr") and
         has_key(passport, "eyr") and has_key(passport, "hgt") and
         has_key(passport, "hcl") and has_key(passport, "ecl") and
         has_key(passport, "pid");
};

namespace detail {
static constexpr auto in_range = [](const std::string &value, auto min,
                                    auto max) {
  std::stringstream value_stream{value};
  int n;
  value_stream >> n;
  return n >= min and n <= max;
};

static constexpr auto byr = [](const std::string &value) {
  return in_range(value, 1920, 2020);
};

static constexpr auto iyr = [](const std::string &value) {
  return in_range(value, 2010, 2020);
};

static constexpr auto eyr = [](const std::string &value) {
  return in_range(value, 2020, 2030);
};

static constexpr auto hgt = [](const std::string &value) {
  if (std::size(value) - 2 == value.find("cm")) {
    return in_range(value, 150, 193);
  } else if (std::size(value) - 2 == value.find("in")) {
    return in_range(value, 59, 76);
  } else {
    return false;
  }
};

static constexpr auto hcl = [](const std::string &value) {
  if (7 != std::size(value)) {
    return false;
  }
  if ('#' != value[0]) {
    return false;
  }
  return std::all_of(std::begin(value) + 1, std::end(value),
                     [](const auto digit) {
                       return isdigit(digit) or (digit >= 'a' and digit <= 'f');
                     });
};

static constexpr auto ecl = [](const std::string &value) {
  const std::array<std::string, 7> valid_values{"amb", "blu", "brn", "gry",
                                                "grn", "hzl", "oth"};
  return std::any_of(
      std::begin(valid_values), std::end(valid_values),
      [&value](const std::string &candidate) { return candidate == value; });
};

static constexpr auto pid = [](const std::string &value) {
  return std::size(value) == 9 and
         std::all_of(std::begin(value), std::end(value),
                     [](const auto digit) { return isdigit(digit); });
};

} // namespace detail

static constexpr auto validate_key =
    [](const passport_t &passport, const std::string &key, auto &&validator) {
      const auto pos = passport.find(key + ":");
      if (std::string::npos == pos) {
        return false;
      }
      std::stringstream value_stream{passport.substr(pos + 4)};
      std::string value;
      value_stream >> value;
      return validator(value);
    };

static constexpr auto is_valid_part2 = [](const passport_t &passport) {
  return validate_key(passport, "byr", detail::byr) and
         validate_key(passport, "iyr", detail::iyr) and
         validate_key(passport, "eyr", detail::eyr) and
         validate_key(passport, "hgt", detail::hgt) and
         validate_key(passport, "hcl", detail::hcl) and
         validate_key(passport, "ecl", detail::ecl) and
         validate_key(passport, "pid", detail::pid);
};

static constexpr auto part1 = [](const passports_t &passports) {
  return std::count_if(std::begin(passports), std::end(passports),
                       is_valid_part1);
};

static constexpr auto part2 = [](const passports_t &passports) {
  return std::count_if(std::begin(passports), std::end(passports),
                       is_valid_part2);
};
} // namespace aoc2020::day4
