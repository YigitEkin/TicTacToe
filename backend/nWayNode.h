//
// Created by Yigit ekin on 29.05.2021.
//

#ifndef BACKEND_NWAYNODE_H
#define BACKEND_NWAYNODE_H
class nWayNode {
    const unsigned short X = 1;
    const unsigned short Empty = 10;
    const unsigned short O = 2;
private:
    nWayNode* branches;
    unsigned short currentBoard[9];
    unsigned short nodecount;
    unsigned short nodeResult;
    unsigned short totalWinCount;
    unsigned short getTotalWin();
    unsigned short getGameStatus( const unsigned short & mark); // returns 1 if win. returns 2 if lose. returns 3 if not ended
    bool isXWin();
    bool isOWin();
    bool isGameOver();
public:
    nWayNode( const int& noOfNodes);
    ~nWayNode();
};
#endif //BACKEND_NWAYNODE_H