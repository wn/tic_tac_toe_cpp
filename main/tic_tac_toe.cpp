#include <iostream>
#include "Game.h"

Game game;

void setup() {
    game = Game();
}

void input() {
    int input;
    std::cin >> input;
    game.parseInput(input);
}

void logic() {
    game.parseResult();
}

int main() {
    setup();
    game.drawGame();
    while (!game.isGameOver()) {
        input();
        logic();
        game.drawGame();
    }
    return 0;
}