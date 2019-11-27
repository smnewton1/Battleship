// Sam Newton - Lab 9 Battleship - CSIS 111
//The following program reads in an x and y coordinate from the user and emulates a simple version of the popular Battlship game.
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool FleetSunk(int length, char userBoard[25][25], char board[25][25]);
void Fire(int X, int Y, char board[25][25], char uBoard[25][25]);

int main() {

	//initilization of variables including two 2D arrays of 25x25 dimensions.
	int xCoordinate;
	int yCoordinate;
	int boards = 25;
	char board[25][25];
	char userBoard[25][25];

	//opens a text file called "board.txt"
	ifstream input;
	input.open("board.txt");


	//program exits if file "board.txt" does not exist 
	if (!input) {
		cout << "Unable to open file board.txt" << endl;
		exit(1);   
	}

	//fills "key" board 
	for (int j = 0; j < boards; j++) {
		for (int i = 0; i < boards; i++) {
			input >> board[i][j];
		}
	}

	//fills user board with just water
	for (int x = 0; x < boards; x++) {
		for (int y = 0; y < boards; y++) {
			userBoard[x][y] = '~';
		}
	}

	//main loop which prints userBoard, prompts for coordinates, and then calls both the Fire and FleetSunk functions.
	do{
		cout << endl;

		for (int y = 0; y < boards; y++) {
			for (int x = 0; x < boards; x++) {
				cout << userBoard[x][y];
			}
			cout << endl;
		}
		cout << "Enter an X Coordinate: ";
		cin >> xCoordinate;
		cout << "Enter a Y Coordinate: ";
		cin >> yCoordinate;


		//verification of + x and y coordinates
		while (xCoordinate < 0 || yCoordinate < 0) {
			cout << "Please enter positive coordinates only." << endl;
			cout << "Enter an X Coordinate: ";
			cin >> xCoordinate;
			cout << "Enter a Y Coordinate: ";
			cin >> yCoordinate;
		}
		


		Fire(xCoordinate, yCoordinate, board, userBoard);
	} while (FleetSunk(25, userBoard, board) == false);

	cout << "The Fleet Was Destroyed!" << endl;
	system("pause");
	return 0;
}

void Fire(int X, int Y, char board[25][25], char userBoard[25][25]) {

	//arrays start at 0, so to make things easier I set the input coordinate values to one less.
	X = X - 1;
	Y = Y - 1;

	if (board[X][Y] == '~') {
		cout << "Miss!" << endl;
	}
	else if (board[X][Y] == '#' && userBoard[X][Y] != 'H') {
		cout << "Hit!" << endl;
		userBoard[X][Y] = 'H';
	}
	else if (board[X][Y] == '#' && userBoard[X][Y] == 'H') {
		cout << "Another hit!" << endl;
	}

}

bool FleetSunk(int length, char userBoard[25][25], char board[25][25]) {
	for (int Y=0; Y < length; Y++) {
		for (int X=0; X < length; X++) {
			if (board[X][Y] == '#') {
				if (userBoard[X][Y] != 'H') {
					return false;
				}
			}
		}
	}
	return true;
}