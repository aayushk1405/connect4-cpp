#include <iostream>
#include "Connect4Game.h"
#include <cstdlib>
using namespace std;

int main(){
    int boardsize=7;  
    int pos, choice = 1;
    bool win;

    while(choice == 1){
        Connect4Game game;
        win = false;

        game.initBoard(boardsize);
        game.start();
        cout << "\n";

        while(!(game.boardfull() || win)){
            cout << "Player " << game.getturn() << "\n";
            cout << "Enter column number (0-6): ";
            cin >> pos;

            if(pos < 0 || pos >= boardsize){
                cout << "Invalid column! Try again.\n";
                continue;
            }

            if(game.rowsleft(pos) < 0){
                cout << "Column has filled up, please select any other.\n";
                continue;
            }

            game.insertvalue(pos);
            //win = game.iswin(game.getturn());

            system("clear");
            game.showboard();

            if(!win)
                game.switchturn(game.getturn());
        }

        if(win){
            cout << "\nPlayer " << game.getturn() << " is the winner of this game.\n";
        }else{
            cout << "\nThe game is a draw.\n";
        }

        cout << "Enter 1 if you wish to play again: ";
        cin >> choice;
    }

    return 0;
}
