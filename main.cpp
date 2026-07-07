#include <iostream>
#include <vector>

#include "robot.h"

using namespace std;
void printMaze(const std::vector<std::vector<char>>& matrix, const Robot& robot) {
    // 1. Get the dimensions of the matrix
    size_t rows = matrix.size();
    if (rows == 0) return; // Guard clause for empty matrix
    size_t cols = matrix[0].size();

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
            if (r == robot.getY() && c == robot.getX()) {
                    std::cout << " " << "R" << " ";
            }
            else {
                std::cout << " " << matrix[r][c] << " ";
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

int main() {
    const std::vector<std::vector<char>> mazeMatrix = {
        {'#', '#', '#'},
        {'#', ' ', 'E'},
        {'#', '#', '#'}
    };

    const Robot robot(1, 1, 'E');
    printMaze(mazeMatrix, robot);

    return 0;
}