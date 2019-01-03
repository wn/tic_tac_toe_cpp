#include "Cell.h"
#include "Player.h"

Player cellValue;
Cell::Cell() {
    cellValue = EMPTY;
}

Player Cell::getPlayer() {
    return cellValue;
}

bool Cell::setPlayer(Player x) {
    if (!isEmpty()) {
        return false;
    } else {
        cellValue = x;
        return true;
    }
}

bool Cell::isEmpty() {
    return cellValue == EMPTY;
}

bool Cell::isPlayerOne() {
    return cellValue == ONE;
}

bool Cell::isPlayerTwo() {
    return cellValue == TWO;
}

bool Cell::isSamePlayer(Cell c) {
    return !isEmpty() && this->cellValue == c.cellValue;
}