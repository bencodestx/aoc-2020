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

auto count_occupied_first_seat_in_direction(const dim_t dim,
                                            const layout_t &layout, size_t row,
                                            size_t col,
                                            const ssize_t row_direction,
                                            const ssize_t col_direction) {
  row = static_cast<size_t>(static_cast<ssize_t>(row) + row_direction);
  col = static_cast<size_t>(static_cast<ssize_t>(col) + col_direction);
  while (row < dim.rows and col < dim.cols) {
    switch (layout[row][col]) {
    case '#':
      return 1u;
    case 'L':
      return 0u;
    default:
      break;
    }
    row = static_cast<size_t>(static_cast<ssize_t>(row) + row_direction);
    col = static_cast<size_t>(static_cast<ssize_t>(col) + col_direction);
  }
  return 0u;
}

auto count_occupied_in_sight(const dim_t dim, const layout_t &layout,
                             const size_t row, const size_t col) {
  return count_occupied_first_seat_in_direction(dim, layout, row, col, 0, 1) +
         count_occupied_first_seat_in_direction(dim, layout, row, col, 0, -1) +
         count_occupied_first_seat_in_direction(dim, layout, row, col, 1, 0) +
         count_occupied_first_seat_in_direction(dim, layout, row, col, -1, 0) +
         count_occupied_first_seat_in_direction(dim, layout, row, col, 1, 1) +
         count_occupied_first_seat_in_direction(dim, layout, row, col, 1, -1) +
         count_occupied_first_seat_in_direction(dim, layout, row, col, -1, 1) +
         count_occupied_first_seat_in_direction(dim, layout, row, col, -1, -1);
}

template <size_t tolerance>
auto model(const dim_t dim, const layout_t &layout, auto &&count_fn) {
  auto new_layout = layout;
  for (size_t row = 0; row < dim.rows; ++row) {
    for (size_t col = 0; col < dim.cols; ++col) {
      switch (layout[row][col]) {
      case 'L': {
        if (count_fn(dim, layout, row, col) == 0) {
          new_layout[row][col] = '#';
        }
        break;
      }
      case '#':
        if (count_fn(dim, layout, row, col) >= tolerance) {
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

namespace detail {
template <size_t tolerance, typename Fn>
auto day11_implementation(std::istream &in, Fn &&fn) {
  auto layout = input(in);
  const dim_t dim{dimensions(layout)};
  while (true) {
    const auto new_layout = model<tolerance>(dim, layout, std::forward<Fn>(fn));
    if (new_layout == layout) {
      break;
    }
    layout = new_layout;
  }

  return count_occupied_seats(layout);
}
} // namespace detail

auto part1(std::istream &in) {
  return detail::day11_implementation<4>(in, count_occupied_adjacent);
}

auto part2(std::istream &in) {
  return detail::day11_implementation<5>(in, count_occupied_in_sight);
}

} // namespace aoc2020::day11
