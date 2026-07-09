//
// Created by rhys on 7/8/26.
//

#ifndef MAZESOLVER_UTILS_H
#define MAZESOLVER_UTILS_H
#include "matrix.h"
#include "robot.h"


class Utils {
public:
    void clearScreen();
    void printMaze(Matrix matrix, Robot robot);
};


#endif //MAZESOLVER_UTILS_H
