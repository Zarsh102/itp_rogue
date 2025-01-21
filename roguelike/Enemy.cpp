#include "Enemy.h"

#include "Grid.h"

const char Enemy::enemySymbol = '!';

void Enemy::MoveTowardsPlayer(int playerX, int playerY, 
	const std::vector< std::vector<char>>& grid, int colSize, int rowSize)
{
	// move right towards player
	if (x < playerX)
	{
		if ((x < rowSize - 1) &&
			(grid[x + 1][y] != Grid::wallSymbol))
		{
			x++;
			return;
		}
	}

	if (x > playerX) 
	{	
		if ((x > 1) &&
			(grid[x - 1][y] != Grid::wallSymbol))
		{
			x--;
			return;
		}
	}

	if (y < playerY)
	{
		if ((y < colSize - 1) &&
			(grid[x][y + 1] != Grid::wallSymbol))
		{
			y++;
			return;
		}
	}

	if (y > playerY)
	{
		if ((y > 1) &&
			(grid[x][y - 1] != Grid::wallSymbol))
		{
			y--;
			return;
		}
	}
}
