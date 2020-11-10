#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int* readFile(int* size)
{
	ifstream fin("input.txt");
	if (fin.is_open())
	{
		for (int i{ 0 }; fin >> i; ++(*size)) {}
		int* str = new int[*size]{ 0 };
		fin.clear();
		fin.seekg(0, ios_base::beg);
		for (int i{ 0 }; i < *size; ++i)
		{
			fin >> str[i];
		}
		fin.close();
		return str;
	}
	else
	{
		return 0;
	}
}

int* find_inv(int* inv, int size)
{
	ifstream fin("Inversion_Table.txt");
	if (fin.is_open())
	{
		int* finv = new int[size] {0};
		int i{ 0 };
		while (!fin.eof())
		{
			for (i = 0; i < size; ++i)
			{
				fin >> finv[i];
			}
			for (i = 0; i < size; ++i)
			{
				if (inv[i]!=finv[i])
				{
					break;
				}
			}
			if (i==size)
			{
				if (fin >> finv[0])
				{
					for (i = 1; i < size; ++i)
					{
						fin >> finv[i];
					}
				}
				else
				{
					return 0;
				}
				break;
			}
		}
		delete[] inv;
		return finv;
	}
	else
	{
		delete[] inv;
		return 0;
	}
}

void writeFile(int* num, int size, const char* file)
{
	ofstream fout(file, ios_base::app);
	if (num == 0)
	{
		fout << "No such line exists";
	}
	else {
		for (int i{ 0 }; i < size; ++i)
		{
			fout << num[i] << " ";
		}
	}
	fout << endl;
	fout.close();
}