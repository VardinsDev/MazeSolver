//
// Created by rhys on 7/7/26.
//

#ifndef MAZESOLVER_ROBOT_H
#define MAZESOLVER_ROBOT_H
#pragma once
#include <vector>

#include "map.h"


class Robot {
private:
    int x, y;
    char direction;
public:
    Robot(int startX, int startY, char startDir);

    void turnLeft();
    void turnRight();
    int getX() const;
    int getY() const;
    void moveForward();
    bool scan(const Map& map);
    bool hasReachedExit(const Map& map);
};


#endif //MAZESOLVER_ROBOT_H
