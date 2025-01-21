#pragma once

#include <vector>
#include <random>

class Grid {
public:
	Grid(int rowSize, int columnSize) 
		: _rowSize{rowSize},
		  _colSize{columnSize},
			mt{rd()}
	{
		initialize_cells();
	};

	void clearTreasure() {
		treasureRemaining = 0;
	}

	void create_new_dungeon() {
		initialize_cells();
	}

	void print_dungeon();

	void set_row_size(int newRowSize) {
		resize_grid(newRowSize, _colSize);
	}

	void set_column_size(int newColSize) {
		resize_grid(_rowSize, newColSize);
	}

	void resize_grid(int rowSize, int columnSize)
	{
		_rowSize = rowSize;
		_colSize = columnSize;
		initialize_cells();
	}

	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();

	bool checkForTreasure();
	bool checkForExit();

	int getRemainingTreasureCount() { return treasureRemaining; }

private:
	int treasureRemaining{ 0 };
	void collectTreasure();

	void initialize_cells();
	void generate_dungeon();

	std::vector< std::vector<char>> grid;

	std::random_device rd;
	std::mt19937 mt;

	int _rowSize;
	int _colSize;

	const char playerSymbol = '@';
	const char treasureSymbol = '*';
	const char wallSymbol = '#';
	const char emptySymbol = ' ';
	const char exitSymbol = '^';

	int playerX{ 0 };
	int playerY{ 0 };
};