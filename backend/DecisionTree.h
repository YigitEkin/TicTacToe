//
// Created by Harun Can on 5/29/2021.
//

#ifndef BACKEND_DECISIONTREE_H
#define BACKEND_DECISIONTREE_H
#include "nWayNode.h"

class DecisionTree {
public:
	DecisionTree();
	~DecisionTree();

private:
	static unsigned short[] initialBoard = {Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty};
	nWayNode* root;
	void addHelper(nWayNode* root);
	unsigned short mark;
};


#endif //BACKEND_DECISIONTREE_H
