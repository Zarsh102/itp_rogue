#include <iostream>
#include <array>
#include <conio.h>
#include <random>

#include <Windows.h>

#include "Grid.h"

#include "Player.h"

int main()
{
	const int ColumnSize = 100;
	const int RowSize = 20;

	Grid grid(RowSize, ColumnSize);
	Player player;

	bool isRunning{ true };

	while (isRunning)
	{
		system("cls");
		grid.print_dungeon();

		if (grid.isDamaged) {
			std::cout << "You were hit for " << grid.GetDamage() << std::endl; 
		}

		if (grid.GetHealth() <= 0)
		{ 
			std::cout << "You are dead!";
			isRunning = false;
			break;
		}

		char ch = _getch();

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
		case 'c':
			grid.clearTreasure();
			break;
		case 'i':
			grid.checkInventory();
			break;
		default:
			std::cout << ch << " is not a valid command\n";
		}

		grid.checkForTreasure();
		
		if (grid.checkForExit() && grid.getRemainingTreasureCount() == 0)
		{
			grid.create_new_dungeon();
		}
	}

	return 0;
}