//
// Created by Yigit ekin on 29.05.2021.
//

#include "nWayNode.h"

nWayNode::~nWayNode() {

}

unsigned short nWayNode::getTotalWin() {
    return 0;
}

nWayNode::nWayNode(const int &noOfNodes) {

}

bool nWayNode::isGameOver() {
    bool empty = true;
    for (int i = 0; i < 9; ++i) {
        if (currentBoard[i] == Empty) {
            empty = false;
        }
    }

    return isOWin() || isXWin() || empty;
}

bool nWayNode::isOWin() {
    int target = 3 * O;

    return (currentBoard[0] + currentBoard[1] + currentBoard[2] == target)  || //first column
           (currentBoard[3] + currentBoard[4] + currentBoard[5] == target)  || //second column
           (currentBoard[6] + currentBoard[7] + currentBoard[8] == target)  || // third column
           (currentBoard[0] + currentBoard[3] + currentBoard[6] == target)  || // first row
           (currentBoard[1] + currentBoard[4] + currentBoard[7] == target)  || // second row
           (currentBoard[2] + currentBoard[5] + currentBoard[8] == target)  || // third row
           (currentBoard[0] + currentBoard[4] + currentBoard[8] == target)  || // main diagonal
           (currentBoard[2] + currentBoard[4] + currentBoard[6] == target); // sub diagonal
}

bool nWayNode::isXWin() {
    int target = 3 * X;

    return (currentBoard[0] + currentBoard[1] + currentBoard[2] == target)  || //first column
        (currentBoard[3] + currentBoard[4] + currentBoard[5] == target)  || //second column
        (currentBoard[6] + currentBoard[7] + currentBoard[8] == target)  || // third column
        (currentBoard[0] + currentBoard[3] + currentBoard[6] == target)  || // first row
        (currentBoard[1] + currentBoard[4] + currentBoard[7] == target)  || // second row
        (currentBoard[2] + currentBoard[5] + currentBoard[8] == target)  || // third row
        (currentBoard[0] + currentBoard[4] + currentBoard[8] == target)  || // main diagonal
        (currentBoard[2] + currentBoard[4] + currentBoard[6] == target);    // sub diagonal
}

unsigned short nWayNode::getGameStatus(const unsigned short& mark) {
    if (!isGameOver())
        return 3;
    else {
        if ( mark == X) {
            if (isXWin()) {
                return 1;
            } else
                return 2;
        }

        if ( mark == O) {
            if (isOWin()) {
                return 1;
            } else
                return 2;
        }
    }
}
