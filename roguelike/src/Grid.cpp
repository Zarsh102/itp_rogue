#include "Grid.h"
#include "Player.h"

#include <iostream>

const char Grid::treasureSymbol = '*';
const char Grid::wallSymbol = '#';
const char Grid::emptySymbol = ' ';
const char Grid::exitSymbol = '^';

void Grid::print_dungeon()
{
	// loop the grid and print each row of characters
	for (int i = 0; i < _rowSize; ++i)
	{
		for (int j = 0; j < _colSize; ++j)
		{
			if (i == player.getX() && j == player.getY())
			{
				std::cout << Player::playerSymbol;
			}
			else if (enemy.getX() == i && enemy.getY() == j) {
				std::cout << Enemy::enemySymbol;
			}
			else {
				std::cout << grid[i][j];
			}
		}
		std::cout << '\n';
	}
}

void Grid::move(Direction direction) {
	bool playerMoved = false;
	
	switch(direction) {
		case Direction::Up:
			playerMoved = player.moveUp(grid);
			break;	
		case Direction::Down:
			playerMoved = player.moveDown(grid);
			break;
		case Direction::Left:
			playerMoved = player.moveLeft(grid);
			break;
		case Direction::Right:
			playerMoved = player.moveRight(grid);
			break;
		}

	if(playerMoved) {
		enemy.MoveTowardsPlayer(player.getX(), player.getY(), grid, _colSize, _rowSize);
	}
}

bool Grid::checkForTreasure()
{
	if (grid[player.getX()][player.getY()] == treasureSymbol)
	{
		collectTreasure();
		return true;
	}

	return false;
}

bool Grid::checkForExit()
{
	if (grid[player.getX()][player.getY()] == exitSymbol)
	{
		return true;
	}

	return false;
}

void Grid::collectTreasure()
{
	grid[player.getX()][player.getY()] = emptySymbol;
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

	player.setPosition(x, y);

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

	enemy.setPosition(x, y);
	grid[x][y] = exitSymbol;
}
