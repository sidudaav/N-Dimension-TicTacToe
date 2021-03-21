#include "Board.h"

using namespace std;

void Board::printBoard(ostream& os) const {
	for (int i = 0; i < board_data.size(); ++i) {
		for (int j = 0; j < board_data[0].size(); ++j) {
			os << board_data[i][j];
			if (j  != board_data[0].size() - 1) os << "|";
		}

		cout << endl;
		if (i != board_data.size() - 1) {
			for (int i = 0; i < 2 * board_data.size(); ++i) cout << "-";
			cout << endl;
		}
	}
}

int Board::getWinner() const {
	for (int i = 0; i < board_data.size(); ++i) {
		bool winnerExists = true;
		if (board_data[i][0] != 0) {
			int val = board_data[i][0];
			for (int j = 0; j < board_data[0].size(); ++j) {
				if (board_data[i][j] != val) winnerExists = false;
			}

			if (winnerExists) return val;
		}
	}

	for (int j = 0; j < board_data[0].size(); ++j) {
		bool winnerExists = true;
		if (board_data[0][j] != 0) {
			int val = board_data[0][j];
			for (int i = 0; i < board_data.size(); ++i) {
				if (board_data[i][j] != val) winnerExists = false;
			}

			if (winnerExists) return val;
		}
	}

	for (int i = 0; i < board_data.size(); ++i) {
		if (board_data[0][0] == 0 || board_data[i][i] != board_data[0][0]) break;
		
		if (i == board_data.size() - 1) return board_data[0][0];
	}

	for (int i = 0; i < board_data.size(); ++i) {
		if (board_data[0][board_data.size() - 1] == 0 || board_data[i][board_data.size() - 1 - i] != board_data[0][board_data.size() - 1]) break;

		if (i == board_data.size() - 1) return board_data[0][board_data.size() - 1];
	}

	return 0;
}

void Board::addMove(Player player, pair<int, int> coord) {
	board_data[coord.first][coord.second] = player;
}

void Board::addComputerMove() {
	if (this->full()) return;

	srand(time(nullptr));

	int x, y;
	do {
		x = rand() % board_data.size();
		y = rand() % board_data.size();
	} while (board_data[x][y]);

	addMove(Player::computer, make_pair(x, y));
}

bool Board::full() const {
	for (int i = 0; i < board_data.size(); ++i) {
		for (int j = 0; j < board_data[0].size(); ++j) {
			if (!board_data[i][j]) return false;
		}
	}

	return true;
}