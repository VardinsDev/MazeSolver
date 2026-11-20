//
// Created by rhys on 7/8/26.
//

#include "PathProcessing.h"

#include <chrono>
#include <thread>

#include "Utils.h"

void PathProcessing::run(Robot robot, const Map& map) {
    Utils utils;
    Map mutableMap = map;
    bool pathBad = false;

    int turnStreak = 0;
    while (!robot.hasReachedExit(map)) {
        if (!robot.scan(map)) {
            if (pathBad) {
                robot.turnRight();
                if (robot.scan(map)) {

                }
            }
            robot.moveForward();
            turnStreak = 0;
        } else {
            turnStreak ++;
            if (turnStreak == 2) {
                robot.turnRight();
                if (robot.scan(map)) {
                    pathBad = true;
                }
            }
            robot.turnRight();
        }
        utils.clearScreen();
        utils.printMaze(map, robot);
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
    }
}
