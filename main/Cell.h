#ifndef CELL_H_
#define CELL_H_

#include "Player.h"

class Cell {
    public:
        Player cellValue;
        Cell();

        Player getPlayer();
        bool setPlayer(Player x);
        bool isEmpty();
        bool isPlayerOne();
        bool isPlayerTwo();
        bool isSamePlayer(Cell c);
};

#endif