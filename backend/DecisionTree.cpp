//
// Created by Harun Can on 5/29/2021.
//

#include "DecisionTree.h"
DecisionTree::DecisionTree() {
    for (int i = 0; i < 9; ++i) {
        initialBoard[i] = 10;
    }

	root = new nWayNode(9, initialBoard, nWayNode::Empty, 1);
	// Temporarily setting mark to be O (2)
	mark = nWayNode::O;
	addHelper(root);
}
/**
 * @author Harun Can Surav
 * a pre-order traversal algorithm which helps creating the decision tree of all possible games
 */
void DecisionTree::addHelper(nWayNode* input) {
	if(!input->isGameOver()) {
		input->nodeResult = input->getGameStatus(mark);
		if(input->nodecount % 2 == 0) {
			for(short i = 0; i < 9; i++) {
				if(input->branches[i].currentBoard[i] == nWayNode::Empty) {
					nWayNode* tmp = new nWayNode(input->nodecount-1, input->currentBoard, nWayNode::O, i);
					input->branches = tmp; //TODO
				}
			}
		} else {
			for(int i = 0; i < 9; i++) {
				if(input->branches[i].currentBoard[i] == nWayNode::Empty) {
					input->branches[i].currentBoard[i] = nWayNode::X;
				}
			}
		}
		for(int i = 0; i < input->nodecount; i++) {
			addHelper(input->branches + i);
		}
	}

}