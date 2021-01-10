#pragma once

#include <istream>
#include <stdexcept>
#include <vector>
namespace aoc2020::day11 {

using layout_t = std::vector<std::string>;

auto input(std::istream &in) {
  layout_t result{};
  std::string line{};
  while (std::getline(in, line)) {
    result.push_back(line);
  }
  return result;
}

struct dim_t final {
  size_t rows{};
  size_t cols{};
};

auto dimensions(const layout_t &layout) {
  const dim_t dim{.rows = std::size(layout), .cols = std::size(layout.front())};

  if (std::any_of(std::begin(layout), std::end(layout), [dim](const auto &row) {
        return std::size(row) != dim.cols;
      })) {
    throw std::runtime_error("Non-conformant layout");
  }

  return dim;
}

auto count_occupied_seats(const layout_t &layout) {
  size_t count{0};
  for (const auto &row : layout) {
    for (const auto col : row) {
      if (col == '#') {
        ++count;
      }
    }
  }
  return count;
}

auto count_occupied_adjacent(const dim_t dim, const layout_t &layout,
                             const size_t row, const size_t col) {
  size_t count{0};
  size_t start_row = row > 0 ? row - 1 : 0;
  size_t start_col = col > 0 ? col - 1 : 0;
  for (size_t r = start_row; r < std::min(row + 2, dim.rows); ++r) {
    for (size_t c = start_col; c < std::min(col + 2, dim.cols); ++c) {
      if (c != col or r != row) {
        if (layout[r][c] == '#') {
          ++count;
        }
      }
    }
  }
  return count;
}

auto model(const dim_t dim, const layout_t &layout) {
  auto new_layout = layout;
  for (size_t row = 0; row < dim.rows; ++row) {
    for (size_t col = 0; col < dim.cols; ++col) {
      switch (layout[row][col]) {
      case 'L': {
        if (count_occupied_adjacent(dim, layout, row, col) == 0) {
          new_layout[row][col] = '#';
        }
        break;
      }
      case '#':
        if (count_occupied_adjacent(dim, layout, row, col) >= 4) {
          new_layout[row][col] = 'L';
        }
        break;
      case '.':
        break;
      default:
        throw std::runtime_error("Invalid state");
      }
    }
  }
  return new_layout;
}

auto part1(std::istream &in) {
  auto layout = input(in);
  const dim_t dim{dimensions(layout)};
  while (true) {
    const auto new_layout = model(dim, layout);
    if (new_layout == layout) {
      break;
    }
    layout = new_layout;
  }

  return count_occupied_seats(layout);
}

auto part2(std::istream &) { return "stub"; }

} // namespace aoc2020::day11
