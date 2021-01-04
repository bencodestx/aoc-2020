#include "aoc2020/day4.hpp"

#include <boost/ut.hpp>

#include <sstream>
#include <string>

const std::string example_passports{
    R"(ecl:gry pid:860033327 eyr:2020 hcl:#fffffd
byr:1937 iyr:2017 cid:147 hgt:183cm

iyr:2013 ecl:amb cid:350 eyr:2023 pid:028048884
hcl:#cfa07d byr:1929

hcl:#ae17e1 iyr:2013
eyr:2024
ecl:brn pid:760753108 byr:1931
hgt:179cm

hcl:#cfa07d eyr:2025 pid:166559648
iyr:2011 ecl:brn hgt:59in)"};

const std::string invalid_passports{
    R"(eyr:1972 cid:100
hcl:#18171d ecl:amb hgt:170 pid:186cm iyr:2018 byr:1926

iyr:2019
hcl:#602927 eyr:1967 hgt:170cm
ecl:grn pid:012533040 byr:1946

hcl:dab227 iyr:2012
ecl:brn hgt:182cm pid:021572410 eyr:2020 byr:1992 cid:277

hgt:59cm ecl:zzz
eyr:2038 hcl:74454a iyr:2023
pid:3556412378 byr:2007)"};

const std::string valid_passports{
    R"(pid:087499704 hgt:74in ecl:grn iyr:2012 eyr:2030 byr:1980
hcl:#623a2f

eyr:2029 ecl:blu cid:129 byr:1989
iyr:2014 pid:896056539 hcl:#a97842 hgt:165cm

hcl:#888785
hgt:164cm byr:2001 iyr:2015 cid:88
pid:545766238 ecl:hzl
eyr:2022

iyr:2010 hgt:158cm hcl:#b6652a ecl:blu byr:1944 eyr:2021 pid:093154719)"};

int main() {
  using namespace aoc2020::day4;
  using namespace boost::ut;

  std::stringstream in(example_passports);
  const auto passports = input(in);

  "input"_test = [&] {
    expect(4_u == std::size(passports));
    expect(passports[0] == "ecl:gry pid:860033327 eyr:2020 "
                           "hcl:#fffffd\nbyr:1937 iyr:2017 cid:147 hgt:183cm");
    expect(passports[1] == "iyr:2013 ecl:amb cid:350 eyr:2023 "
                           "pid:028048884\nhcl:#cfa07d byr:1929");
    expect(passports[2] == "hcl:#ae17e1 iyr:2013\neyr:2024\necl:brn "
                           "pid:760753108 byr:1931\nhgt:179cm");
    expect(passports[3] ==
           "hcl:#cfa07d eyr:2025 pid:166559648\niyr:2011 ecl:brn hgt:59in");
  };

  "example_1"_test = [&] { expect(is_valid_part1(passports[0])); };
  "example_2"_test = [&] { expect(not is_valid_part1(passports[1])); };
  "example_3"_test = [&] { expect(is_valid_part1(passports[2])); };
  "example_4"_test = [&] { expect(not is_valid_part1(passports[3])); };

  "part1"_test = [&] { expect(2_i == part1(passports)); };

  "part2_invalid"_test = [&] {
    std::stringstream invalid(invalid_passports);
    expect(0_i == part2(input(invalid)));
  };

  "part2_valid"_test = [&] {
    std::stringstream valid(valid_passports);
    expect(4_i == part2(input(valid)));
  };
}
