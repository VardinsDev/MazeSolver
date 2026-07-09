//
// Created by rhys on 7/8/26.
//

#include "PathProcessing.h"

#include <chrono>
#include <thread>

#include "Utils.h"

void run(Robot robot, const Matrix& matrix) {
    Utils utils;
    Matrix mutableMatrix = matrix;
    bool pathBad = false;

    int turnStreak = 0;
    while (!robot.hasReachedExit(matrix)) {
        if (!robot.scan(matrix)) {
            if (pathBad) {
                robot.turnRight();
                if (robot.scan(matrix)) {

                }
            }
            robot.moveForward();
            turnStreak = 0;
        } else {
            turnStreak ++;
            if (turnStreak == 2) {
                robot.turnRight();
                if (robot.scan(matrix)) {
                    pathBad = true;
                }
            }
            robot.turnRight();
        }
        utils.clearScreen();
        utils.printMaze(matrix, robot);
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
    }
}
