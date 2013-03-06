#pragma once
#include <list>
using namespace std;
using namespace System;
using namespace System::Collections;

ref class DataStorage
{
public:
	DataStorage(void);
	ArrayList^ GetData();
	bool StoreData(String^ s);
	static DataStorage^ GetInstance();
private:
	static DataStorage^ myInstance;
};

