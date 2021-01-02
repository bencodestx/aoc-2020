#include <boost/ut.hpp>

#include <string_view>

int main() {
  using namespace boost::ut;

  constexpr std::string_view example_passwords{
      R"(1-3 a: abcde
1-3 b: cdefg
2-9 c: ccccccccc)"};

  "stub"_test = [&] { expect(not std::empty(example_passwords)); };
}
