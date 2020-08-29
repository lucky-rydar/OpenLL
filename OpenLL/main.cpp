#include <iostream>
#include <string>
#include <Windows.h>
#include "DLLExport.h"

using namespace std;

int main(int argc, char** argv)
{
	cout << "Hello World!" << endl;
	// TODO: call {int sum(int, int)} func with DLLExport from "test_dll.dll"
	DLLExport<int, int, int> func("test_dll.dll", "sum");
	
	cout << func(1, 1) << endl;

	

	return 0;
}