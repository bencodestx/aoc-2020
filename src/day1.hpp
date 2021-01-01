#pragma once

#include <algorithm>
#include <istream>
#include <numeric>
#include <vector>

static constexpr auto day1_input = [](std::istream &in) {
  std::vector<int> values{};
  int value;
  while (in >> value) {
    values.push_back(value);
  }
  return values;
};

template <typename Iter, size_t Count> struct day1_search final {
  day1_search(const auto &container) : end(std::end(container)) {
    Iter it = std::begin(container);
    for (auto &iterator : iterators) {
      iterator = it++;
    }
  }

  void next() {
    size_t i = Count - 1;
    while (true) {
      if (end != ++iterators[i]) {
        ++i;
        while (i < Count) {
          iterators[i] = iterators[i - 1] + 1;
          if (end == iterators[i]) {
            throw std::runtime_error("No solution found");
          }
          ++i;
        }
        return;
      }
      --i;
    }
  }

  auto operator[](const size_t i) { return *iterators[i]; }

  std::array<Iter, Count> iterators{};

private:
  const Iter end;
};

static constexpr auto day1_part1 = [](const auto &expenses) {
  day1_search<decltype(std::end(expenses)), 2> search{expenses};
  while (true) {
    const auto first = search[0];
    const auto second = search[1];
    if (2020 == (first + second)) {
      return first * second;
    }
    search.next();
  }
};
