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
    void printMaze(const Matrix& matrix, const Robot& robot);
};


#endif //MAZESOLVER_UTILS_H
