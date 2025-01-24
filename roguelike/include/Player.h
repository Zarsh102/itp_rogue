#pragma once

#include <vector>

using GridArray = std::vector<std::vector<char>>;

class Player
{
public:
  Player() = default;
  Player(int x, int y) : _x{x}, _y{y} {}

  void setPosition(int x, int y);

  bool moveUp(const GridArray& grid);
	bool moveDown(const GridArray& grid);
	bool moveLeft(const GridArray& grid);
	bool moveRight(const GridArray& grid);

  int getX() const { return _x; }
  int getY() const { return _y; }

  static const char playerSymbol;

private:
  int _x{0};
  int _y{0};
};