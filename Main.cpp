#include <iostream>
#include <iomanip>
#include "FileWork.h"
#include "TabCreate.h"
#include "NextStr.h"
using namespace std;

int main()
{
	int* size = new int{ 0 };
	int* str = readFile(size);
	create_tab(*size);
	writeFile(nextStr(str, *size), *size, "output.txt");
	delete size;
}