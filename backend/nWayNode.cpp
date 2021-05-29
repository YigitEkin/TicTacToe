//
// Created by Yigit ekin  on 29.05.2021.
//

#include "nWayNode.h"

//nWayNode::nWayNode()  {
//    nWayNode* branches;
//    unsigned short currentBoard[9];
//    unsigned short nodeResult;
//    unsigned short totalWinCount;
//    unsigned short getTotalWin();
//    unsigned short getGameStatus();
//}

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
 * @author Harun Can Surav
 * Constructor for node
 * @param noOfNodes is the number of childs the node is going to have
 * @param parentGame is the inherited board
 * @param mark is the mark which will be added (X-O)
 * @param markLocation is the location where the aforementioned mark will be added
 */
nWayNode::nWayNode(const int &noOfNodes,unsigned short *parentGame, int mark, int markLocation) {
	for(int i = 0; i < 9; i++) {
		currentBoard[i] = parentGame[i];
	}
	currentBoard[markLocation] = mark;
	branches = new nWayNode[noOfNodes];
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
