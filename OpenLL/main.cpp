#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include "DLLExport.h"

using namespace std;

DLLExport<int, int, int> sum("test_dll.dll", "sum");

int main(int argc, char** argv)
{
	cout << sum(250, 100) << endl;

	return 0;
}