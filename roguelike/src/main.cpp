#include <iostream>
#include <array>

#include <random>

#include <Windows.h>

#include "Grid.h"

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
			grid.move(Direction::Up);
			break;
		case 'a':
			grid.move(Direction::Left);
			break;
		case 's':
			grid.move(Direction::Down);
			break;
		case 'd':
			grid.move(Direction::Right);
			break;
		case 'q':
			isRunning = false;
			break;
		case 'c':
			grid.clearTreasure();
			break;
		default:
			std::cout << ch << " is not a valid command\n";
		}

		if (grid.checkForTreasure())
		{
			treasureCount++;
		}
		
		if (grid.checkForExit() && grid.getRemainingTreasureCount() == 0)
		{
			grid.create_new_dungeon();
		}
	}

	return 0;
}