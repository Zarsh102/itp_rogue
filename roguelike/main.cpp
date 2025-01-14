#include <iostream>
#include <array>

#include <random>

#include "Grid.hpp"

int main()
{
	const int ColumnSize = 100;
	const int RowSize = 20;

	Grid grid(RowSize, ColumnSize);

	grid.resize_grid(10, 10);

	grid.print_dungeon();

	return 0;
}