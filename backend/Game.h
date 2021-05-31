//
// Created by Yigit Ekin on 31.05.2021.
//

#ifndef BACKEND_GAME_H
#define BACKEND_GAME_H
#include "DecisionTree.h"
class DecisionTree;
#include <iostream>

using namespace std;

class Game {
private:
    unsigned short currentBoard[9];
    unsigned short opponentsMark;
    //Decision Tree
    void selectBestMove();
public:
    DecisionTree decisionTree;
    Game( unsigned short mark);

    void initGame();
    void PlayGame();
    void printBoard();
    bool playMove(int index);
};
#endif //BACKEND_GAME_H
