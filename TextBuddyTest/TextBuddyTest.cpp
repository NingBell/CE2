#include "stdafx.h"
#include "CppUnitTest.h"
#include <fstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TextBuddyTest
{		
	TEST_CLASS(TextBuddyTest)
	{
	public:
		
		TEST_METHOD(Test)
		{
			const string fileName = "myfile.txt";
			const string line1 = "hello my friend";
			const string line2 = "nice to meet you";
			
			//add line1
			string output1 = TextBuddy::addContent(fileName, line1);
			string expected1 = "added to myfile.txt: \"hello my friend\"";
			Assert::AreEqual(output1, expected1);
			
			//add line2
			string output2 = TextBuddy::addContent(fileName, line2);
			string expected2 = "added to myfile.txt: \"nice to meet you\"";
			Assert::AreEqual(output2, expected2);
			
			//test the sort function
			string output3 = TextBuddy::sortAlphabetical(fileName);
			string expected3 = "all content in myfile.txt are sorted alphabetically";
			Assert::AreEqual(output3, expected3);

			//test the search function
			//found word
			string word1 = "hello";
			string searched1 = TextBuddy::searchWord(fileName, word1);
			string expected4 = "";
			Assert::AreEqual(expected4, searched1);
			//word not found
			string word2 = "good";
			string searched2 = TextBuddy::searchWord(fileName, word2);
			string expected5 = "word not found in myfile.txt";
			Assert::AreEqual(expected5, searched2);
		}

	};
}