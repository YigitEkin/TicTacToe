//
// Created by Yigit ekin on 29.05.2021.
//

#ifndef BACKEND_NWAYNODE_H
#define BACKEND_NWAYNODE_H
#include "DecisionTree.h"
#include "Game.h"
class nWayNode {
public:
    nWayNode();
    nWayNode(const int &noOfNodes,unsigned short *parentGame, short mark, short markLocation);
    ~nWayNode();
    const static unsigned short X = 1;
    const static unsigned short Empty = 10;
    const static unsigned short O = 2;
    bool isGameOver();
private:
    friend class DecisionTree;
    friend class Game;
    nWayNode* branches;
    void operator = (const nWayNode &copy);
    unsigned short currentBoard[9];
    unsigned short nodecount;
    unsigned short nodeResult;
    unsigned short totalWinCount;
    unsigned short totalDrawCount;
    unsigned short getTotalWin();
    unsigned short getTotalDraw();
    unsigned short getGameStatus( const unsigned short & mark); // returns 1 if win. returns 2 if lose. returns 3 if not ended. 4 draw.
    bool isXWin();
    bool isOWin();
    //IsGAMEOVER
};
#endif //BACKEND_NWAYNODE_H
