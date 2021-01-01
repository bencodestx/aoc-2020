#include <boost/ut.hpp>

#include <sstream>
#include <vector>

int main() {
  using namespace boost::ut;

  constexpr auto example_expense_report{
      R"(1721
979
366
299
675
1456)"};

  static constexpr auto day1_input = [](std::istream &in) {
    std::vector<int> values{};
    int value;
    while (in >> value) {
      values.push_back(value);
    }
    return values;
  };

  static constexpr auto day1 = [](const auto &expenses) {
    const auto second =
        std::find_if(std::begin(expenses) + 1, std::end(expenses),
                     [first = expenses[0]](const auto candidate) {
                       return first + candidate == 2020;
                     });
    return expenses[0] * *second;
  };

  "input"_test = [&] {
    std::stringstream in(example_expense_report);
    expect(std::vector{1721, 979, 366, 299, 675, 1456} == day1_input(in));
  };

  "1010, 1010 == 1020100"_test = [&] {
    expect(1020100_i == day1(std::array{1010, 1010}));
  };

  "1010, 9999, 1010 == 1020100"_test = [&] {
    expect(1020100_i == day1(std::array{1010, 9999, 1010}));
  };

  "1721, 9999, 299 == 514579"_test = [&] {
    expect(514579_i == day1(std::array{1721, 9999, 299}));
  };
}
