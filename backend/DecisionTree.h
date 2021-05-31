//
// Created by Harun Can on 5/29/2021.
//

#ifndef BACKEND_DECISIONTREE_H
#define BACKEND_DECISIONTREE_H
#include "nWayNode.h"
#include <vector>
class nWayNode;
using namespace std;

class DecisionTree {
public:
	DecisionTree();
	~DecisionTree();

private:
	static unsigned short initialBoard[9];
	nWayNode* root;
	void addHelper(nWayNode* root);
	unsigned short mark;
};


#endif //BACKEND_DECISIONTREE_H
