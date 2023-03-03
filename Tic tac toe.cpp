// TIC TAC TOE

#include <bits/stdc++.h>
#include <bits/stdc++.h>
#define MAX 3
using namespace std;

string x_player;
string y_player;
bool x_turn;
bool x_win = false, y_win = false;

vector<vector<char>> game(MAX, vector<char> (MAX, '.'));

void reset() {
	for(int i=0; i<MAX; ++i) {
		for(int j=0; j<MAX; ++j) {
			game[i][j] = '.';
		}
	}
}

// configure the x_turn bool variable 
void whoPlaysFirst() {
	while(1) {
		string name;
		cout << "Who is going to play first (" << x_player << ", " << y_player << "):";
		cin >> name;
		if(name == x_player) {
			x_turn = true;
			return;
		} else if(name == y_player) {
			x_turn = false;
			return;
		} else {
			cout << "Invalid name...Please retry\n" ;
		}
	}
}

// initialize x_player and y_player with there names
void playerName() {
	cout << "Enter a name for the X player:\n";
	cin >> x_player;
	cout << "Enter a name for the O player:\n";
	cin >> y_player;
}

// print the game matrix
void printGame() {
	for(int i=0; i<MAX; ++i) {
		for(int j=0; j<MAX; ++j) {
			cout << game[i][j] << " ";
		}
		cout << endl;
	}
}

// checks if all spaces are completely filled
bool gameOver() {
	char k='1';
	for(int i=0; i<MAX; ++i) {
		for(int j=0; j<MAX; ++j) {
			if(game[i][j] == '.') {
				return false;
			}
		}
	}
	return true;
}

bool columnCheck(int j, char ch) {
	for(int i=0; i<MAX; ++i) {
		if(game[i][j] != ch) return false;
	}
	return true;
}

bool rowCheck(int i, char ch) {
	for(int j=0; j<MAX; ++j) {
		if(game[i][j] != ch) return false;
	}
	return true;
}

bool mainDiagonalCheck(char ch) {
	return (game[0][0] == ch && game[1][1] == ch && game[2][2] == ch);
}

bool otherDiagonalCheck(char ch) {
	return (game[0][2] == ch && game[1][1] == ch && game[2][0] == ch);
}

bool checkWin(int i, int j, char ch) {
	if(rowCheck(i, ch) || columnCheck(j, ch)) {
		return true;
	}
	if(i == 1 && j == 1) {
		return (mainDiagonalCheck(ch) || otherDiagonalCheck(ch));
	} else if((i == 0 && j == 0) || (i == 2 && j == 2)) {
		return mainDiagonalCheck(ch);	
	} else if((i == 0 && j == 2) || (i == 2 && j == 0)) {
		return otherDiagonalCheck(ch);
	}
}

// Main menu of game
void menu() {
	playerName();
	whoPlaysFirst();
	while(!gameOver()) {
		cout << "\n";
		printGame();
		cout << "Player of current turn: " << (x_turn?x_player:y_player) << endl;
		int i, j;
		while(1) {
			cout << "Choose a row number (0 to 2): ";
			cin >> i;
			if(i < 0 || i >= MAX) {
				cout << i << " is not a valid row.\n";
		 		continue;
			}
			cout << "Choose a column number (0 to 2): ";
			cin >> j;
			if(j < 0 || j >= MAX) {
				cout << j << " is not a valid column.\n";
				continue;
			}
			if(game[i][j] == 'X' || game[i][j] == 'O') {
				cout << i << " " << j << " is already filled.\n";
				continue;
			}
			break;
		} 
		if(x_turn) {
			game[i][j] = 'X';
			if(checkWin(i, j, 'X')) {
				x_win = true;
				break;
			}
		} else {
			game[i][j] = 'O';
			if(checkWin(i, j, 'O')) {
				y_win = true;
				break;
			}
		}
		x_turn = !x_turn;
	}
	printGame();
	cout << "Game is over:\n";
	if(x_win) {
		cout << x_player << " wins!";
	} else if(y_win) {
		cout << y_player << " wins!";
	} else {
		cout << "it is a tie!";
	}
	cout << "\n";
}

int main() {
	bool repeat = true;
	while(repeat) {
		reset();
		menu();
		while(1) {
			string choice;
			cout << "Would you like to play again? (Y/N)\n";
			cin >> choice;
			if(choice == "Y") {
				break;
			} else if(choice == "N") {
				repeat = false;
				break;
			} else {
				cout << choice << " is not a valid answer.\n";
			}
		}
	}
	cout << "Bye!";
}