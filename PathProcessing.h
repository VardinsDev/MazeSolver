#ifndef MAZESOLVER_PATHPROCESSING_H
#define MAZESOLVER_PATHPROCESSING_H
#include "map.h"
#include "robot.h"


class PathProcessing {
public:
    void run(Robot robot, const Map& map);
};


#endif //MAZESOLVER_PATHPROCESSING_H
