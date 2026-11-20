#include "map.h"

#include <utility>

Map::Map(std::vector<std::vector<char>> initialGrid)
    : grid(std::move(initialGrid)) {}

size_t Map::getRows() const{
    return grid.size();
}
size_t Map::getCols() const {
    return grid[0].size();
}
char Map::getTileAt(int x, int y) const{
    return grid[y][x];
}