#pragma once
#include <string>
#include <iostream>
#include <Windows.h>

using namespace std;

template <class T, class ...Params>
class DLLImportFunc
{
public:
	DLLImportFunc(string dll_name, string func_name)
	{
		wstring local_dll_name(dll_name.begin(), dll_name.end());
		dll = LoadLibrary((LPCWSTR)local_dll_name.c_str());

		func = (T(*)(Params...))GetProcAddress(dll, func_name.c_str());
	}

	T operator()(Params... params)
	{
		return ((T(*)(Params...))(func))(params...);
	}

	virtual ~DLLImportFunc()
	{
		::FreeLibrary(dll);
	}
	
private:
	HMODULE dll;
	void* func;
	
};

