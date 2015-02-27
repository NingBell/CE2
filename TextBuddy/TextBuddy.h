//TextBuddy.h
#ifndef TEXTBUDDY_H
#define TEXTBUDDY_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class TextBuddy{
private:
	enum CommandType { ADD_LINE, DISPLAY_ALL, DELETE_LINE, CLEAR_ALL, SORT, EXIT, SEARCH, INVALID};
public:
	//Modifier Functions
	static string displayWelcomeMessage(string fileName);
	static CommandType determineCommandType(string command);
	static string exercuteUserCommand(string fileName, string userCommand);
	static string getCommandType(string userCommand);
	static string getContent(string userCommand);
	static string addContent(string fileName, string content);
	static string displayAll(string fileName);
	static string deleteContent(string fileName, string content);
	static string clearAll(string fileName);
	static void storeFileinVector(string fileName);
	static void writeToFile(string fileName);
	static string sortAlphabetical(string fileName);
	static bool getRightLines(vector<string> store, string word);
	static bool isContainingWord(string line, string word);
	static void printRightLines(vector<string> rightLines);
	static string searchWord(string fileName, string word);
};

#endif
