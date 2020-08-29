#include <iostream>
#include <string>
#include <Windows.h>
#include "DLLExport.h"

using namespace std;

int main(int argc, char** argv)
{
	DLLExport<int, int, int> func("test_dll.dll", "sum");
	
	cout << func(1, 1) << endl;

	return 0;
}