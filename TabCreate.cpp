#include <iostream>
#include <iomanip>
#include "FileWork.h"
using namespace std;

void create_tab(int size)
{
	int* invTab = new int[size] {0};
	while (invTab[0] < size)
	{
		writeFile(invTab, size, "Inversion_Table.txt");
		++invTab[size - 2];
		for (int i{ 3 }; i <= size; ++i)
		{
			if (invTab[size-i+1]>i-2)
			{
				invTab[size - i + 1] = 0;
				++invTab[size - i];
			}
		}
	}
	delete[] invTab;
}