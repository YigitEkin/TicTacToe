//
// Created by Harun Can on 5/29/2021.
//

#ifndef BACKEND_DECISIONTREE_H
#define BACKEND_DECISIONTREE_H
#include "nWayNode.h"
#include "Game.h"
#include <vector>
class nWayNode;
using namespace std;

class DecisionTree {
public:
    DecisionTree(unsigned short mark);
    ~DecisionTree();
    nWayNode* root;
private:
    friend class Game;
    unsigned short initialBoard[9];
    //ROOT
    void addHelper(nWayNode* root);
    void winCountCalculator(nWayNode* root);
    void destructorHelper(nWayNode* root);
    unsigned short mark;
};


#endif //BACKEND_DECISIONTREE_H
