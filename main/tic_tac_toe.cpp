#include <iostream>
#include <chrono>
#include <thread>
#include <map>
#include <string>

using namespace std;

enum Player {
    EMPTY, ONE, TWO
};

enum Result {
    UNKNOWN, PLAYER_ONE, PLAYER_TWO
};

class Cell {
    public:
        Player cellValue;
        Cell() {
            cellValue = EMPTY;
        }

        Player getPlayer() {
            return cellValue;
        }

        bool setPlayer(Player x) {
            if (!isEmpty()) {
                return false;
            } else {
                cellValue = x;
                return true;
            }
        }

        bool isEmpty() {
            return cellValue == EMPTY;
        }

        bool isPlayerOne() {
            return cellValue == ONE;
        }

        bool isPlayerTwo() {
            return cellValue == TWO;
        }

        bool isSamePlayer(Cell c) {
            return !isEmpty() && this->cellValue == c.cellValue;
        }
};

class Game {
    public:
        map<int, Cell> game;
        Player currentPlayer;

        Player winner;

        // Count the number of moves made to determine when nine moves has been made. 
        int numOfMoves;

        Game() {
            currentPlayer = ONE;
            game = map<int, Cell>();
            gameOver = false;
            winner = EMPTY;
            numOfMoves = 0;
        }

        string valAtPos(int pos) {
            if (!isValidPos(pos)) {
                return "ERROR";
            }
            if (game[pos].isPlayerOne()) {
                return "X";
            } else if (game[pos].isPlayerTwo()) {
                return "0";
            } else {
                // pos is empty
                return to_string(pos);
            }
        }

        static bool isValidPos(int pos) {
            return pos >= 1 && pos <= 9;
        }

        void parseInput(int pos) {
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

        bool isGameOver() {
            return gameOver;
        }

        void parseResult() {
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

    private:
        bool gameOver;

        void swapCurrentPlayer() {
            if (currentPlayer == ONE) {
                currentPlayer = TWO;
            } else if (currentPlayer == TWO) {
                currentPlayer = ONE;
            }
        }

        bool isSamePlayers(int x, int y, int z) {
            Cell c1 = game[x];
            Cell c2 = game[y];
            Cell c3 = game[z];
            return c1.isSamePlayer(c2) && c2.isSamePlayer(c3);
        }

        bool isNotEmpty(int pos) {
            return !game[pos].isEmpty();
        }
};

Game game;

void setup() {
    game = Game();
}

void draw() {
    system("clear");

    cout << "THE EXCITING GAME OF TIC-TAC-TOE!" << endl;
    cout << "GET 3 IN A ROW TO WIN!" << endl;
    cout << endl;

    if (game.isGameOver()) {
        switch (game.winner) {
            case ONE:
                cout << "WINNER IS: PLAYER 1!!!" << endl;
                break;
            case TWO:
                cout << "WINNER IS: PLAYER 2!!!" << endl;
                break;
            case EMPTY:
                cout << "GAME IS A DRAW!!!" << endl;
                break;
        }
    } else {
        cout << "It is now " << (game.currentPlayer == ONE ? "Player 1" : "Player 2") <<" turn" << endl;
    }
    for (int i = 0; i < 13; i++) {
        for (int j = 0; j < 13; j++) {
            if (i % 4 == 0 && j % 4 == 0) {
                cout << "+";
            } else if (i % 4 == 0){
                cout << "-";
            } else if (j % 4 == 0) {
                cout << "|";
            } else if ((i + 2) % 4 == 0 && (j + 2) % 4 == 0) {
                int row = (i - 2) / 4; // 0-index
                int col = (j + 2) / 4; // 1-index
                int pos = row * 3 + col;
                cout << game.valAtPos(pos);
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

void input() {
    int input;
    cin >> input;
    game.parseInput(input);
}

void logic() {
    game.parseResult();
}

int main() {
    setup();
    while (!game.isGameOver()) {
        draw();
        input();
        logic();
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
    draw();
    return 0;
}