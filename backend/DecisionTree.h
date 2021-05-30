//
// Created by Harun Can on 5/29/2021.
//

#ifndef BACKEND_DECISIONTREE_H
#define BACKEND_DECISIONTREE_H
#include "nWayNode.h"
class nWayNode;
class DecisionTree {
public:
	DecisionTree();
	~DecisionTree();

private:
	nWayNode* root;
	unsigned short initialBoard[9];
	void addHelper(nWayNode* input);
	unsigned short mark;
};


#endif //BACKEND_DECISIONTREE_H
