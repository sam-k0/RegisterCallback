#pragma once
#define gmx extern "C" __declspec(dllexport)
#define gmtrue 1.0;
#define gmfalse 0.0;
#include <string>
class gmu {

public:
	static char* string_to_charptr(string s)
	{
		return _strdup(s.c_str());
	}

	static const char* string_to_constcharptr(string s)
	{
		return s.c_str();
	}

	static string constcharptr_to_string(const char* p)
	{
		return string(p);
	}

	static void debugmessage(string s)
	{
		cout << s << endl;
	}
};

