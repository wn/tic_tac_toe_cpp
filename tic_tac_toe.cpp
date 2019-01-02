#include <iostream>
#include <chrono>
#include <thread>
#include <map>
#include <string>

using namespace std;

bool gameOver;

enum Players {
    EMPTY, ONE, TWO
};

int INPUT;

class Game {
    public:
        map<int, Players> game;
        Players currentPlayer;

        Game() {
            currentPlayer = ONE;
            game = map<int, Players>();
        }

        string valAtPos(int pos) {
            if (!isValidPos(pos)) {
                return "ERROR";
            }
            if (game[pos] == ONE) {
                return "X";
            } else if (game[pos] == TWO) {
                return "0";
            } else {
                return to_string(pos);
            }
        }

        static bool isValidPos(int pos) {
            return pos <= 9 && pos >= 1;
        }

        void parseInput(int pos) {
            if (isValidPos(pos)) {
                game[pos] = currentPlayer;
                swapPlayer();
            }
        }

    private:
        void swapPlayer() {
            if (currentPlayer == ONE) {
                currentPlayer = TWO;
            } else if (currentPlayer == TWO) {
                currentPlayer = ONE;
            }
        }
};

Game game;

void setup() {
    gameOver = false;
    game = Game();
}

void draw() {
    system("clear");
    cout << "THE EXCITING GAME OF TIC-TAC-TOE!" << endl << endl;
    cout << "It is now " << (game.currentPlayer == ONE ? "Player 1" : "Player 2") <<" turn" << endl;
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
    cin >> INPUT;
}

void logic() {
    game.parseInput(INPUT);
}

int main() {
    setup();
    while (!gameOver) {
        draw();
        input();
        logic();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    return 0;
}