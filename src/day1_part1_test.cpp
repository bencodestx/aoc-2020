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

  "input"_test = [&] {
    std::stringstream in(example_expense_report);
    expect(std::vector{1721, 979, 366, 299, 675, 1456} == day1_input(in));
  };
}
