//
// Created by rhys on 7/8/26.
//

#ifndef MAZESOLVER_UTILS_H
#define MAZESOLVER_UTILS_H
#include "map.h"
#include "robot.h"


class Utils {
public:
    void clearScreen();
    void printMaze(const Map& map, const Robot& robot);
};


#endif //MAZESOLVER_UTILS_H
