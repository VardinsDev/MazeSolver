#include "Utils.h"

#include <cstdlib>
#include <iostream>

#include "map.h"
#include "robot.h"

void Utils::clearScreen() {
#ifdef _WIN32
    std::system("cls");
#else
    std::system("clear");
#endif
}

void Utils::printMaze(const Map& map, const Robot& robot) {
    // 1. Get the dimensions using the new Map class methods
    size_t rows = map.getRows();
    size_t cols = map.getCols();

    // 2. Print top decorative border
    std::cout << "+";
    for (size_t c = 0; c < cols; ++c) {
        std::cout << "---";
    }
    std::cout << "+\n";

    // 3. Loop through rows and columns to print grid data
    for (size_t r = 0; r < rows; ++r) {
        std::cout << "|"; // Left vertical border
        for (size_t c = 0; c < cols; ++c) {
            // Check if the current grid slot matches the robot's coordinates
            // Note: c represents X (columns), r represents Y (rows)
            if (r == robot.getY() && c == robot.getX()) {
                std::cout << " " << "R" << " ";
            }
            else {
                // Use the public safe accessor instead of map[r][c]
                std::cout << " " << map.getTileAt(c, r) << " ";
            }
        }
        std::cout << "|\n"; // Right vertical border
    }

    // 4. Print bottom decorative border
    std::cout << "+";
    for (size_t c = 0; c < cols; ++c) {
        std::cout << "---";
    }
    std::cout << "+\n";
}
