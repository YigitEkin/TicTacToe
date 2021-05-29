//
// Created by Yigit ekin on 29.05.2021.
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

unsigned short nWayNode::getGameStatus() {
    return 0;
}

nWayNode::nWayNode(const int &noOfNodes) {

}
