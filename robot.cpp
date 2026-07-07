#include "robot.h"
#include <iostream>

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