#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include "DLLImportFunc.h"

using namespace std;

DLLImportFunc<int, int, int> sum("test_dll.dll", "sum");

int main(int argc, char** argv)
{
	cout << sum(2, 2) << endl;

	return 0;
}