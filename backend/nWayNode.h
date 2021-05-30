//
// Created by Yigit ekin on 29.05.2021.
//

#ifndef BACKEND_NWAYNODE_H
#define BACKEND_NWAYNODE_H
#include "DecisionTree.h"
class nWayNode {
    const static unsigned short X = 1;
    const static unsigned short Empty = 10;
    const static unsigned short O = 2;
private:
	friend class DecisionTree;
    nWayNode* branches;
    unsigned short currentBoard[9];
    unsigned short nodecount;
    unsigned short nodeResult;
    unsigned short totalWinCount;
    unsigned short getTotalWin();
    unsigned short getGameStatus( const unsigned short & mark); // returns 1 if win. returns 2 if lose. returns 3 if not ended. 4 draw.
    bool isXWin();
    bool isOWin();
    bool isGameOver();
public:
	nWayNode();
    nWayNode(const int &noOfNodes,unsigned short *parentGame, short mark, short markLocation);
    ~nWayNode();
};
#endif //BACKEND_NWAYNODE_H
