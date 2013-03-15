// TestingProject.cpp : main project file.

#include "stdafx.h"
#include "Tester.h"
#include <conio.h>
using namespace System;

int main(int argument_count, char** argument_vars)
{
    Console::WriteLine(L"Hello World");
	runTest(argument_count, argument_vars);
	getch();
    return 0;
}
