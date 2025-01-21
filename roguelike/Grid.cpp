#include "Grid.hpp"

#include <iostream>

void Grid::print_dungeon()
{
	// loop the grid and print each row of characters
	for (int i = 0; i < _rowSize; ++i)
	{
		for (int j = 0; j < _colSize; ++j)
		{
			if (i == playerX && j == playerY)
			{
				std::cout << playerSymbol;
			}
			else {
			std::cout << grid[i][j];
		}
		}
		std::cout << '\n';
	}
}

void Grid::moveUp()
{
	if ((playerX > 1) && 
		(grid[playerX - 1][playerY] != wallSymbol))
	{
		playerX--;
	}

}

void Grid::moveDown()
{
	if ((playerX < _rowSize - 1) &&
		(grid[playerX + 1][playerY] != wallSymbol))
		playerX++;
}

void Grid::moveLeft()
{
	if ((playerY > 1) &&
		(grid[playerX][playerY - 1] != wallSymbol))
		playerY--;
}

void Grid::moveRight()
{
	if ((playerY < _colSize - 1) &&
		(grid[playerX][playerY + 1] != wallSymbol))
		playerY++;
}

bool Grid::checkForTreasure()
{
	if (grid[playerX][playerY] == treasureSymbol)
	{
		collectTreasure();
		return true;
	}

	return false;
}

void Grid::collectTreasure()
{
	grid[playerX][playerY] = emptySymbol;
	treasureRemaining--;
}

void Grid::initialize_cells()
{
	grid.clear();
	grid.resize(_rowSize);
	
	for (int i = 0; i < _rowSize; ++i)
	{
		grid[i].resize(_colSize, wallSymbol);
	}

	generate_dungeon();
}

void Grid::generate_dungeon()
{
	const int MaxWalkableCells = (_colSize * _rowSize) / 2;
	const int MaxNumberSteps = MaxWalkableCells * 10;

	int stepsTaken{ 0 };
	int cellsConverted{ 0 };

	treasureRemaining = 0;

	std::uniform_int_distribution<> column_dist(1, _colSize-1);
	std::uniform_int_distribution<> row_dist(1, _rowSize-1);

	int x = row_dist(mt);
	int y = column_dist(mt);

	playerX = x;
	playerY = y;

	while (stepsTaken < MaxNumberSteps
		&& cellsConverted < MaxWalkableCells)
	{
		if (grid[x][y] == wallSymbol)
		{
			grid[x][y] = emptySymbol;
			cellsConverted++;
		}

		if (stepsTaken > 0 && stepsTaken % 250 == 0)
		{
			grid[x][y] = treasureSymbol;
			treasureRemaining++;
		}

		std::uniform_int_distribution<> direction_dist(0, 3);
		int direction = direction_dist(mt);

		// 0 = up, 1 = right, 2 = down, 3 = left
		switch (direction)
		{
		case 0:
			if (y <= 1) continue;
			y--;
			break;
		case 1:
			if (x <= 1) continue;
			x--;
			break;
		case 2:
			if (y >= _colSize - 2) continue;
			y++;
			break;
		case 3:
		default:
			if (x >= _rowSize - 2) continue;
			x++;
			break;
		}

		stepsTaken++;
	}
}
