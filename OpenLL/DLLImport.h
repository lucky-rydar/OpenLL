#pragma once
#include <string>
#include <iostream>
#include <Windows.h>

using namespace std;

template <class T, class ...Params>
class DLLImport
{
public:
	DLLImport(string dll_name, string func_name)
	{
		wstring local_dll_name(dll_name.begin(), dll_name.end());
		dll = LoadLibrary((LPCWSTR)local_dll_name.c_str());
		
		if (dll == NULL)
		{
			cout << "Library has not found: ";
			cout << GetLastError() << endl;
		}
			

		func = GetProcAddress(dll, func_name.c_str());
		if (func == NULL)
		{
			cout << "Function has not found: ";
			cout << GetLastError() << endl;
		}
			
	}

	T operator()(Params... params)
	{
		if (func != nullptr)
			return ((T(*)(Params...))(func))(params...);
		else
			return NULL;
	}

	virtual ~DLLImport()
	{
		::FreeLibrary(dll);
	}
	
private:
	HMODULE dll;
	void* func;
	
};

