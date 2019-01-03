#ifndef GAME_H_
#define GAME_H_

#include <string>
#include <map>
#include "Player.h"
#include "Cell.h"

class Game {
    public:
        std::map<int, Cell> game;
        Player currentPlayer;
        Player winner;
        bool gameOver;
        int numOfMoves; // Count the number of moves made to determine when nine moves has been made. 

        Game();

        std::string valAtPos(int pos);
        bool isGameOver();
        void parseInput(int pos);
        void parseResult();
        void drawGame();

        static bool isValidPos(int pos) {
            return pos >= 1 && pos <= 9;
        }

    private:
        void swapCurrentPlayer();
        bool isSamePlayers(int x, int y, int z);
        bool isNotEmpty(int pos);
};

#endif