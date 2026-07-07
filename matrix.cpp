#include "matrix.h"

#include <utility>

Matrix::Matrix(std::vector<std::vector<char>> initialGrid)
    : grid(std::move(initialGrid)) {}

size_t Matrix::getRows() const{
    return grid.size();
}
size_t Matrix::getCols() const {
    return grid[0].size();
}
char Matrix::getTileAt(int x, int y) const{
    return grid[y][x];
}