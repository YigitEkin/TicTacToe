//
// Created by Harun Can on 5/29/2021.
//

#include "DecisionTree.h"
DecisionTree::DecisionTree() {
	root = new nWayNode(9, initialBoard, nWayNode::Empty, 1);
	// Temporarily setting mark to be O (2)
	mark = nWayNode::O;
	addHelper(root);
}
/**
 * @author Harun Can Surav
 * a pre-order traversal algorithm which helps creating the decision tree of all possible games
 */
void DecisionTree::addHelper(nWayNode* root) {
	if(!root->isGameOver()) {
		root->nodeResult = root->getGameStatus(mark);
		if(root->nodecount % 2 == 0) {
			for(int i = 0; i < 9; i++) {
				if(	root->branches[i].currentBoard[i] == nWayNode::Empty) {
					root->branches[i].currentBoard[i] = nWayNode::O;
				}
			}
		} else {
			for(int i = 0; i < 9; i++) {
				if(	root->branches[i].currentBoard[i] == nWayNode::Empty) {
					root->branches[i].currentBoard[i] = nWayNode::X;
				}
			}
		}
		for(int i = 0; i < root->nodecount; i++) {
			addHelper(root->branches + i);
		}
	}

}