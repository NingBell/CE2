//TextBuddy.h
#ifndef TEXTBUDDY_H
#define TEXTBUDDY_H

#include <iostream>
#include <string>

using namespace std;

class TextBuddy{
private:
	enum CommandType { ADD_LINE, DISPLAY_ALL, DELETE_LINE, CLEAR_ALL, EXIT, INVALID};
public:
	//Modifier Functions
	static void displayWelcomeMessage(string fileName);
	static CommandType determineCommandType(string command);
	static void exercuteUserCommand(string fileName, string userCommand);
	static string getCommandType(string userCommand);
	static string getContent(string userCommand);
	static void addContent(string fileName, string content);
	static void displayAll(string fileName);
	static void deleteContent(string fileName, string content);
	static void clearAll(string fileName);
};

#endif
