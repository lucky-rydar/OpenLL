#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include "DLLImport.h"
#pragma warning(disable: 4996)

using namespace std;

DLLImport<int, int, int> sum("dll_learning.dll", "any_name");
//DLLImport<int, int, int> mult("dll_learning.dll", "mult");

int main(int argc, char** argv)
{
	cout << sum(3, 2) << endl;
	//cout << mult(10, 10) << endl;

	return 0;
}