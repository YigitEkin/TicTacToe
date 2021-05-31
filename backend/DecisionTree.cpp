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
 * @author Harun Can Surav and Yiğit Ekin
 * a pre-order traversal algorithm which helps creating the decision tree of all possible games
 */
void DecisionTree::addHelper(nWayNode* root) {
    if (root->isGameOver()) {
        root->nodeResult = root->getGameStatus(mark);
        root->branches = nullptr;
        return;
    } else {
        int emptyCount = 0;
        std::vector<unsigned short> boardPlaysIndex; ///to collect empty indexes at the board
        for (unsigned short i = 0; i < 9; ++i) {
            if (root->currentBoard[i] == nWayNode::Empty) {
                boardPlaysIndex.push_back(i);
                ++emptyCount;
            }
        }

        for (int i = 0; i < emptyCount; ++i) {
            nWayNode temp(emptyCount - 1, root->currentBoard, mark, boardPlaysIndex[i]);
            root->branches[i] = temp;
        }

        for (int i = 0; i < emptyCount; ++i) {
            addHelper(root->branches + i);
        }
    }
}


