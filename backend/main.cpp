#include <iostream>
#include "Game.h"
int main() {
    Game a = Game( 1);

    int count = 0;
    int index;
    while( !a.decisionTree.root->isGameOver()) {
        cout << "Please enter the index that you want to play: " << endl;
        cin >> index;
        if (count % 2 == 0) {
            while (!a.playMove(index)) {
                cout << "Please enter the index that you want to play: " << endl;
                cin >> index;
            }
        }

        else {
            a.PlayGame();
        }
    }
    return 0;
}