#pragma once
#include <iostream>
#include <vector>
#include <utility>
#include <stdlib.h>
#include <time.h>

enum Player {
	human = 1, computer = 2
};

class Board {
public:
	Board() : board_data(std::vector<std::vector<int>> { {0, 0, 0}, { 0, 0, 0 }, { 0, 0, 0 }}) {}
	Board(int n) : board_data(std::vector<std::vector<int>>(n, std::vector<int>(n, 0))) {}

	void printBoard(std::ostream& os) const;
	int getWinner() const;

	void addMove(Player player, std::pair<int, int> coord);
	void addComputerMove();

	bool full() const;
	
private:
	std::vector<std::vector<int>> board_data;
};