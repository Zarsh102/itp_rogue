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

	while (isRunning)
	{
		system("cls");
	grid.print_dungeon();

		char ch;
		std::cin >> ch;

		switch (ch)
		{
		case 'q':
			isRunning = false;
			break;
		}
	}

	return 0;
}