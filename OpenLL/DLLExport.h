#pragma once
#include <string>
#include <iostream>
#include <Windows.h>

using namespace std;

template <class T, class ...Params>
class DLLExport
{
public:
	DLLExport(string dll_name, string func_name)
	{
		wstring local_dll_name(dll_name.begin(), dll_name.end());
		dll = LoadLibrary((LPCWSTR)local_dll_name.c_str());

		auto temp_func = (T(*)(Params...))GetProcAddress(dll, func_name.c_str());
		func = (FARPROC)temp_func;
	}

	T operator()(Params... params)
	{
		auto temp = (T(*)(Params...))func;
		return temp(params...);
	}

	virtual ~DLLExport()
	{
		::FreeLibrary(dll);
	}
	
private:
	HMODULE dll;
	FARPROC func;
	
};

