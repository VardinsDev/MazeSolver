#include "robot.h"
#include <iostream>

#include "matrix.h"

Robot::Robot(int startX, int startY, char startDir)
    : x(startX), y(startY), direction(startDir) {}

void Robot::turnLeft() {
    switch (direction) {
        case 'N':
            direction = 'W';
            // " is two bytes, ' is one
            break;
        case 'W':
            direction = 'S';
            break;
        case 'S':
            direction = 'E';
            break;
        case 'E':
            direction = 'N';
            break;
        default:
            std::cout << "Direction not defined" << std::endl;
            break;
    }
}

void Robot::turnRight() {
    switch (direction) {
        case 'N':
            direction = 'E';
            break;
        case 'E':
            direction = 'S';
            break;
        case 'S':
            direction = 'W';
            break;
        case 'W':
            direction = 'N';
            break;
        default:
            std::cout << "Direction not defined" << std::endl;
    }
}

void Robot::moveForward() {
    switch (direction) {
        case 'N':
            y--;
            break;
        case 'W':
            x--;
            break;
        case 'S':
            y++;
            break;
        case 'E':
            x++;
            break;
        default:
            std::cout << "Direction not defined" << std::endl;
            break;
    }
}

int Robot::getX() const {
    return x;
}

int Robot::getY() const {
    return y;
}


/**
 * @return true if there is an obstacle in the way of the direction the robot is looking, false if not.
 */
bool Robot::scan(const Matrix& matrix) {
    switch (direction) {
        case 'N':
            if (matrix.getTileAt(x, y-1) == ' ' || matrix.getTileAt(x, y-1) == 'E') {
                return false;
            }
            if (matrix.getTileAt(x, y-1) == '#') {
                return true;
            }
        case 'E':
            if (matrix.getTileAt(x+1, y) == ' ' || matrix.getTileAt(x-1, y) == 'E') {
                return false;
            }
            if (matrix.getTileAt(x+1, y) == '#') {
                return true;
            }
        case 'S':
            if (matrix.getTileAt(x, y+1) == '#') {
                return true;
            }
            if (matrix.getTileAt(x, y+1) == 'E' || matrix.getTileAt(x, y+1) == ' ') {
                return false;
            }
        case 'W':
            if (matrix.getTileAt(x-1, y) == ' ' || matrix.getTileAt(x-1, y) == 'E') {
                return false;
            }
            if (matrix.getTileAt(x-1, y) == '#') {
                return true;
            }
        default:
            return true;
    }
}

bool Robot::hasReachedExit(const Matrix& matrix) {
    // Check if the tile at our current (x, y) is the Exit character
    if (matrix.getTileAt(x, y) == 'E') {
        return true;
    }
    return false;
}
