#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include "DLLImport.h"

using namespace std;

DLLImport<int, int, int> sum("test_dll.dll", "sum");

int main(int argc, char** argv)
{
	cout << sum(2, 2) << endl;

	return 0;
}