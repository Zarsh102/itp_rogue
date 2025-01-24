#include "Player.h"
#include "Grid.h"

const char Player::playerSymbol = '@';

void Player::setPosition(int x, int y)
{
  _x = x;
  _y = y;
}

bool Player::moveUp(const GridArray& grid)
{
  char cell = grid[_x-1][_y];

  if (_x > 0 && cell != Grid::wallSymbol)
  {
    _x--;
    return true;
  }

  return false;
}

bool Player::moveDown(const GridArray& grid)
{
  char cell = grid[_x+1][_y];
  int rowSize = grid.size();

  if (_x < rowSize && cell != Grid::wallSymbol)
  {
    _x++;
    return true;
  }

  return false;
}

bool Player::moveLeft(const GridArray& grid)
{
  char cell = grid[_x][_y-1];
  
  if (_y > 0 && cell != Grid::wallSymbol)
  {
    _y--;
    return true;
  }

  return false;
}

bool Player::moveRight(const GridArray& grid)
{
  char cell = grid[_x][_y+1];
  int colSize = grid[0].size();

  if (_y < colSize && cell != Grid::wallSymbol)
  {
    _y++;
    return true;
  }

  return false;
}