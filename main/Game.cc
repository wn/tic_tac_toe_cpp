#include "Game.h"
#include "Cell.h"
#include <iostream>

Game::Game() {
    currentPlayer = ONE;
    game = std::map<int, Cell>();
    gameOver = false;
    winner = EMPTY;
    numOfMoves = 0;
}

std::string Game::valAtPos(int pos) {
    if (!isValidPos(pos)) {
        return "ERROR";
    }
    
    if (game[pos].isPlayerOne()) {
        return "X";
    } else if (game[pos].isPlayerTwo()) {
        return "0";
    } else {
        // pos is empty
        return std::to_string(pos);
    }
}

void Game::swapCurrentPlayer() {
    if (currentPlayer == ONE) {
        currentPlayer = TWO;
    } else if (currentPlayer == TWO) {
        currentPlayer = ONE;
    }
}

bool Game::isSamePlayers(int x, int y, int z) {
    Cell c1 = game[x];
    Cell c2 = game[y];
    Cell c3 = game[z];
    return c1.isSamePlayer(c2) && c2.isSamePlayer(c3);
}

bool Game::isNotEmpty(int pos) {
    return !game[pos].isEmpty();
}

void Game::parseInput(int pos) {
    if (!isGameOver() && isValidPos(pos)) {
        if (game[pos].setPlayer(currentPlayer)) {
            swapCurrentPlayer();
            numOfMoves++;
        }
    }
    if (numOfMoves == 9) {
        gameOver = true;
    }
}

bool Game::isGameOver() {
    return gameOver;
}

void Game::parseResult() {
    // Possible winning combo is [(1,2,3), (1,4,7), (1,5,9), (2,5,8), (3,6,9), (3,5,7), (4,5,6), (7,8,9)]
    // If any of the 5 branch is reached, gameOver = true;
    if (isSamePlayers(1,2,3) || isSamePlayers(1,4,7) || isSamePlayers(1,5,9)) {
        gameOver = true;
        winner = game[1].getPlayer();
    }
    if (isSamePlayers(2,5,8)) {
        gameOver = true;
        winner = game[2].getPlayer();
    }
    if (isSamePlayers(3,6,9) || isSamePlayers(3,5,7)) {
        gameOver = true;
        winner = game[3].getPlayer();
    }
    if (isSamePlayers(4,5,6)) {
        gameOver = true;
        winner = game[4].getPlayer();
    }
    if (isSamePlayers(7,8,9)) {
        gameOver = true;
        winner = game[7].getPlayer();
    }
}

void Game::drawGame() {
    system("clear");

    std::cout << "THE EXCITING GAME OF TIC-TAC-TOE!" << std::endl;
    std::cout << "GET 3 IN A ROW TO WIN!" << std::endl;
    std::cout << std::endl;

    if (isGameOver()) {
        switch (winner) {
            case ONE:
                std::cout << "WINNER IS: PLAYER 1!!!" << std::endl;
                break;
            case TWO:
                std::cout << "WINNER IS: PLAYER 2!!!" << std::endl;
                break;
            case EMPTY:
                std::cout << "GAME IS A DRAW!!!" << std::endl;
                break;
        }
    } else {
        std::cout << "It is now " << (currentPlayer == ONE ? "Player 1" : "Player 2") <<" turn" << std::endl;
    }
    for (int i = 0; i < 13; i++) {
        for (int j = 0; j < 13; j++) {
            if (i % 4 == 0 && j % 4 == 0) {
                std::cout << "+";
            } else if (i % 4 == 0){
                std::cout << "-";
            } else if (j % 4 == 0) {
                std::cout << "|";
            } else if ((i + 2) % 4 == 0 && (j + 2) % 4 == 0) {
                int row = (i - 2) / 4; // 0-index
                int col = (j + 2) / 4; // 1-index
                int pos = row * 3 + col;
                std::cout << valAtPos(pos);
            } else {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}