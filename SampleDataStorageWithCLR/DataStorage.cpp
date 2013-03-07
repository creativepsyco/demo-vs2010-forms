#include "stdafx.h"
#include "DataStorage.h"
using namespace System::Xml;
using namespace System;
using namespace System::Collections;
DataStorage::DataStorage(void)
{
}

// Returns Data by reading from the XML File
// For more details Refer to:
// http://support.microsoft.com/kb/815658
ArrayList^ DataStorage::GetData()
{
	ArrayList^ aList = gcnew ArrayList();
	String ^s = "";
	XmlTextReader^ reader = gcnew XmlTextReader ("stuff.xml");
	while (reader->Read())
	{
		switch (reader->NodeType)
		{
		case XmlNodeType::Element: // The node is an element.
			Console::Write("<{0}", reader->Name);
			Console::WriteLine(">");
			if (reader->Name == "name")
			{
				reader->Read(); // text
				reader->Read();
			}
			break;
		case XmlNodeType::Text: //Display the text in each element.
			s= reader->Value;
			Console::WriteLine(reader->Value);
			aList->Add(s); //Store into the list
			break;
		case XmlNodeType::EndElement: //Display the end of the element.
			Console::Write("</{0}", reader->Name);
			Console::WriteLine(">");
			break;
		}
	}
	return aList;
}

bool DataStorage::StoreData(String^ s)
{
	// Left as an exercise
	// Create the xml file
	// With all the entries in place as well
	// as the current inserted entry
	return false;
}

// Returns the DataStorage Instance for use
DataStorage^ DataStorage::GetInstance()
{
	if (DataStorage::myInstance)
	{
		return DataStorage::myInstance;
	} 
	else 
	{
		myInstance = gcnew DataStorage();
		return myInstance;
	}
}