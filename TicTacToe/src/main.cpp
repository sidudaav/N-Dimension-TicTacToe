#include <iostream>

#include "Board.h"

using namespace std;

int main() {
	int n;

	cout << "DIMENSION: ";
	cin >> n;
	cout << endl;

	Board board(n);

	int x, y;
	while (!board.getWinner() && !board.full()) {
		board.printBoard(cout);

		cout << endl << "WHAT SQUARE DO YOU WANT: ";
		cin >> x >> y;

		board.addMove(Player::human, pair<int, int> {x, y});
		board.addComputerMove();
	}

	board.printBoard(cout);
	cout << endl;
	
	int winner = board.getWinner();
	if (winner) {
		if (winner == 1) cout << "YOU WON!";
		else cout << "THE COMPUTER WON";
	} else cout << "THE GAME IS A TIE";
	
	cout << endl << endl;
}