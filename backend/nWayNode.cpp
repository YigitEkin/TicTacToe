//
// Created by Yigit ekin  on 29.05.2021.
//

#include "nWayNode.h"

nWayNode::nWayNode()  {

    nodecount = 9;
    for(int i = 0; i < 9; i++) {
        currentBoard[i] = Empty;
    }
    for (int i = 0; i < nodecount; ++i) {
        branches[i] = nWayNode();
    }
}


nWayNode::~nWayNode() {
}

/**
 * @author Harun Can Surav
 * @return total wins below (including current node)
 */
unsigned short nWayNode::getTotalWin() {
    if(nodecount == 0) {
        if (nodeResult == 1) {
            totalWinCount = 1;
        }
        else {
            totalWinCount = 0;
        }
    }
    else {
        for(int i = 0; i < nodecount; i++) {
            totalWinCount += branches[i].totalWinCount;
        }
    }
    return totalWinCount;
}

/**
 * @author Yiğit Ekin
 * @return total draws below (including current node)
 */
unsigned short nWayNode::getTotalDraw() {
    if(nodecount == 0) {
        if (nodeResult == 4) {
            totalDrawCount = 1;
        }
        else {
            totalWinCount = 0;
        }
    }
    else {
        for(int i = 0; i < nodecount; i++) {
            totalWinCount += branches[i].totalWinCount;
        }
    }
    return totalDrawCount;
}

/**
 * @author Harun Can Surav
 * Constructor for node
 * @param noOfNodes is the number of childs the node is going to have
 * @param parentGame is the inherited board
 * @param mark is the mark which will be added (X-O)
 * @param markLocation is the location where the aforementioned mark will be added
 */
nWayNode::nWayNode(const int &noOfNodes,unsigned short *parentGame, short mark, short markLocation) {
    nodecount = noOfNodes;
    for(int i = 0; i < 9; i++) {
        currentBoard[i] = parentGame[i];
    }
    currentBoard[markLocation] = mark;
    if(noOfNodes != 0)
        branches = new nWayNode[noOfNodes];
    else
        branches = nullptr;
}

/**
 * @author Yigit Ekin
 * Determining is whether the current state corresponds to a ending case
 * @return true if game is over. false if game is not over
 */
bool nWayNode::isGameOver() {
    bool empty = true;

    for (int i = 0; i < 9; ++i) {
        if (currentBoard[i] != 0 && currentBoard[i] == Empty) {
            empty = false;
        }
    }

    return isOWin() || isXWin() || empty;
}

/**
 * @author Yigit Ekin
 * Determining is whether the current state corresponds to winning case for mark O
 * @return true if O wins. false if O loses
 */
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

/**
 * @author Yigit Ekin
 * Determining is whether the current state corresponds to winning case for mark X
 * @return true if X wins. false if X loses
 */
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

/**
 * @author Yigit Ekin
 * Determining is whether the current state corresponds to winning case for mark X
 * @param mark the mark of the user (X-O)
 * @return 1 if the stated mark wins. 2 if the stated mark loses. 3 if the game has not ended. 4 if it is a draw
 */
unsigned short nWayNode::getGameStatus(const unsigned short& mark) {
    if (!isGameOver())
        return 3;
    else {
        if (mark == X) {
            if (isXWin()) {
                return 1;
            } else if (isOWin()) {
                return 2;
            } else {
                return 4;
            }
        }

        if (mark == O) {
            if (isOWin()) {
                return 1;
            } else if (isXWin()) {
                return 2;
            } else {
                return 4;
            }
        }
    }
    return -1;
}
void nWayNode::operator=(const nWayNode &copy) {
    this->nodecount = copy.nodecount;
    this->nodeResult = copy.nodeResult;
    for(int i = 0; i < 9; ++i)
        this->currentBoard[i] = copy.currentBoard[i];
    this->totalWinCount = copy.totalWinCount;
}



