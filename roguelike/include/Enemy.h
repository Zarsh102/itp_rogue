#pragma once

#include <vector>

class Enemy {
public:
	Enemy() {}
	Enemy(int xPos, int yPos) : x{ xPos }, y{ yPos } { }
	Enemy(int xPos, int yPos, int hp) : x{ xPos }, y{ yPos }, health{ hp } {}

	void MoveTowardsPlayer(int playerX, int playerY, 
		const std::vector< std::vector<char>>& grid, 
		int colSize, int rowSize);
	
	int getX() { return x; }
	int getY() { return y; }

	void setPosition(int xPos, int yPos) {
		x = xPos;
		y = yPos;
	}

	static const char enemySymbol;

private:
	int x{ 0 }, y{ 0 };
	int health{ 10 };
	
};