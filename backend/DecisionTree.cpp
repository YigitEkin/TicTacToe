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
 * @authors Harun Can Surav and Yiğit Ekin
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
/**
 * @author Harun Can Surav
 * Recursive function which calculates sum of winning games for each node
 * @param root is the node which you want to start calculating number of winning cases from
 */
void DecisionTree::winCountCalculator(nWayNode *root) {
    for(int i = 0; i < root->nodecount; i++) {
        winCountCalculator(root->branches + i);
    }
    root->getTotalWin();
}
/**
 * @author Harun Can Surav
 * A method which post order traverses the tree and deletes its nodes
 * @param root is the node which you want to destroy (with its children)
 */
void DecisionTree::destructorHelper(nWayNode *root) {
    for(int i = 0; i < root->nodecount; i++) {
        destructorHelper(root->branches + i);
    }
    delete root;
}

/**
 * @author Harun Can Surav
 * Destructor which re-allocates the decision tree...
 */
DecisionTree::~DecisionTree() {
    destructorHelper(root);
}


