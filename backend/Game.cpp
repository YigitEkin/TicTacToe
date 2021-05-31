//
// Created by Yiğit ekin on 31.05.2021.
//

#include "Game.h"

void Game::selectBestMove() {
    int indexToGo = 0;
    int maxValue = 0;
    for (int i = 0; i < decisionTree.root->nodecount; ++i)
        if ( decisionTree.root->branches[i].totalWinCount > maxValue) {
            indexToGo = i;
            maxValue = decisionTree.root->branches[i].totalWinCount;
        }

    //if there is a chance to win
    if (maxValue) {
        for (int i = 0; i < 9; ++i)
            currentBoard[i] = decisionTree.root->branches[i].currentBoard[i];
    } else { // if there are only possibilities including draws
        indexToGo = 0;
        maxValue = 0;
        for (int i = 0; i < decisionTree.root->nodecount; ++i)
            if ( decisionTree.root->branches[i].totalDrawCount > maxValue) {
                indexToGo = i;
                maxValue = decisionTree.root->branches[i].totalDrawCount;
            }

        for (int i = 0; i < 9; ++i)
            currentBoard[i] = decisionTree.root->branches[i].currentBoard[i];
    }
}

void Game::PlayGame() {
    initGame();

    if (decisionTree.mark == nWayNode::O) {
        if (decisionTree.root->nodecount % 2 != 0)
            selectBestMove();
        printBoard();
    }


    else if (decisionTree.mark == nWayNode::X) {
        if (decisionTree.root->nodecount % 2 == 0)
            selectBestMove();
        printBoard();
    }
}

void Game::initGame() {
    for (int i = 0; i < 9; ++i)
        currentBoard[i] = decisionTree.initialBoard[i];

}

Game::Game(unsigned short mark) : decisionTree(mark) {
    decisionTree.mark = mark;
    initGame();
    if (decisionTree.mark == nWayNode::X)
        opponentsMark = nWayNode::O;
    else
        opponentsMark = nWayNode::X;
}

void Game::printBoard() {
    for (int i = 0; i < 9; ++i) {
        if (i % 3 == 0)
            cout << endl;
        if ( currentBoard[i] == nWayNode::X) {
            cout << "X ";
        } else if (currentBoard[i] == nWayNode::O) {
            cout << "O ";
        } else
            cout << "- ";
    }
}

bool Game::playMove(int index) {
    if (currentBoard[index] == nWayNode::Empty) {
        cout << endl << "This move is not possible" << endl;
        return false;
    }
    currentBoard[index] = opponentsMark;
    return true;
}





