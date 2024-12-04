#include <iostream>
using namespace std;
const int ROWS = 3;
const int COLS = 3;
char board[ROWS][COLS] = {{' ', ' ', ' '},
                          {' ', ' ', ' '},
                          {' ', ' ', ' '}};
char currentPlayer = 'X';
void displayBoard() {
    cout << "-------------" << endl;
    for (int i = 0; i < ROWS; i++) {
        cout << "| ";
        for (int j = 0; j < COLS; j++) {
            cout << board[i][j] << " | ";
        }
        cout << endl << "-------------" << endl;
    }
}
bool checkWin() {
    for (int i = 0; i < ROWS; i++) {
        if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) {
            return true;
        }
    }
    for (int j = 0; j < COLS; j++) {
        if (board[0][j] == currentPlayer && board[1][j] == currentPlayer && board[2][j] == currentPlayer) {
            return true;
        }
    }
    if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) {
        return true;
    }
    if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer) {
        return true;
    }
    return false;
}
bool checkDraw() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}
void switchPlayer() {
    if (currentPlayer == 'X') {
        currentPlayer = 'O';
    } else {
        currentPlayer = 'X';
    }
}
int main() {
    bool playAgain = true;
    while (playAgain) {
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                board[i][j] = ' ';
            }
        }
        currentPlayer = 'X';
        while (true) {
            displayBoard();
            int row, col;
            cout << "Player " << currentPlayer << ", enter your move (row, col): ";
            cin >> row >> col;
            if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ') {
                cout << "Invalid move. Please try again." << endl;
                continue;
            }
            board[row - 1][col - 1] = currentPlayer;
            if (checkWin()) {
                cout << "Player " << currentPlayer << " wins!" << endl;
                break;
            } else if (checkDraw()) {
                cout << "It's a draw!" << endl;
                break;
            }
            switchPlayer();
        }
        cout << "Do you want to play again? (y/n): ";
        char choice;
        cin >> choice;
        playAgain = (choice == 'y' || choice == 'Y');
    }
    return 0;
}
