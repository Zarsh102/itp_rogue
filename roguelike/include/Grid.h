#pragma once

#include <vector>
#include <random>

#include "Enemy.h"
#include "Player.h"

enum class Direction {
	Up,
	Down,
	Left,
	Right
};

using GridArray = std::vector<std::vector<char>>;

class Grid {
public:
	Grid(int rowSize, int columnSize) 
		: mt{rd()},
		  _rowSize{rowSize},
			_colSize{columnSize},
		enemy{3, 4}
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

	void move(Direction direction);

	bool checkForTreasure();
	bool checkForExit();

	int getRemainingTreasureCount() { return treasureRemaining; }

	static const char treasureSymbol;
	static const char wallSymbol;
	static const char emptySymbol;
	static const char exitSymbol;

private:
	int treasureRemaining{ 0 };
	void collectTreasure();

	void initialize_cells();
	void generate_dungeon();

	GridArray grid;

	std::random_device rd;
	std::mt19937 mt;

	int _rowSize;
	int _colSize;

	Enemy enemy;
	Player player;
};