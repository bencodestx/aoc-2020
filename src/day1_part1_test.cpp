#include <boost/ut.hpp>

int main() {
  using namespace boost::ut;

  "stub"_test = [] { expect(true); };
}
