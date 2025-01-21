#include <iostream>
#include <array>

#include <random>

#include <Windows.h>

#include "Grid.hpp"

int main()
{
	const int ColumnSize = 100;
	const int RowSize = 20;

	Grid grid(RowSize, ColumnSize);

	bool isRunning{ true };

	int treasureCount{ 0 };

	while (isRunning)
	{
		system("cls");
	grid.print_dungeon();

		std::cout << "Collected " << treasureCount << '\n';

		char ch;
		std::cin >> ch;

		switch (ch)
		{
		case 'w':
			grid.moveUp();
			break;
		case 'a':
			grid.moveLeft();
			break;
		case 's':
			grid.moveDown();
			break;
		case 'd':
			grid.moveRight();
			break;
		case 'q':
			isRunning = false;
			break;
		}

		if (grid.checkForTreasure())
		{
			treasureCount++;
		}
		}
	}

	return 0;
}