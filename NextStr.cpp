#include <iostream>
#include <iomanip>
#include "FileWork.h"
using namespace std;

int* nextStr(int* str, int size)
{
	int* InvTab = new int[size] {0};
	for (int i{ 0 }; i < size; ++i)
	{
		for (int j{ i - 1 }; j >= 0; --j)
		{
			if (str[i] < str[j])
			{
				++InvTab[str[i] - 1];
			}
		}
	}
	InvTab = find_inv(InvTab, size);
	if (InvTab == 0)
	{
		return 0;
	}
	else
	{
		delete[]str;
		str = new int[size] {0};
		for (int i{ 1 }, j{ 0 }; i <= size; ++i)
		{
			j = 0;
			for (int k{ 0 }; k < InvTab[i - 1] || str[j] != 0; ++j)
			{
				if (str[j] == 0) {
					++k;
				}
			}
			str[j] = i;
		}
		delete[]InvTab;
		return str;
	}
}