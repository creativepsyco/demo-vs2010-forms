#include "gtest/gtest.h" //include to use Google Unit test's stuff
#include "DataStorage.h"
#include "DataStorage.cpp"

/************************************************************************/

/* We write test cases here */

/************************************************************************/
void string2charPtr(String ^orig, char *&out)
{
	int length = orig->Length;
	out = new char[length+1];
	for(int i=0;i<length;i++)
		out[i] = (char) orig[i];
	out[length] = '\0';
}

TEST(basic_test, add_simple_route)

{
	DataStorage^ instance = DataStorage::GetInstance();
	int s = instance->GetMessage();
	ASSERT_EQ(s, 1);
	ASSERT_EQ(1, 1);

}





void runTest(int argument_count, char** argument_vars)

{

	testing::InitGoogleTest(&argument_count, argument_vars); //initialize GTest

	RUN_ALL_TESTS();

	std::getchar(); //pause the program after all the testing

}