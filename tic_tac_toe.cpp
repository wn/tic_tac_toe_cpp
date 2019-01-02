#include <iostream>
#include <chrono>
#include <thread>
#include <map>
#include <string>

using namespace std;

void setup() {

}

void draw() {
    system("clear");
    cout << "THE EXCITING GAME OF TIC-TAC-TOE!" << endl << endl;
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
                cout << pos;
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

void input() {

}

void logic() {

}

int main() {
    
    return 0;
}