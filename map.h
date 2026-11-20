//
// Created by rhys on 7/7/26.
//

#ifndef MAZESOLVER_MAP_H
#define MAZESOLVER_MAP_H
#include <vector>


class Map {
private:
    std::vector<std::vector<char>> grid;
public:
    Map(std::vector<std::vector<char>> initialGrid);

    // Member functions to interact with the grid safely
    size_t getRows() const;
    size_t getCols() const;
    char getTileAt(int x, int y) const;
};


#endif //MAZESOLVER_MAP_H
