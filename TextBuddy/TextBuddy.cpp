//This TestBuddy program can be used to manipulate text in a file.
//The filename can be given by the user.
//Assume the forms of editing can only be: add lines to the file; 
//display the current content in the file;
//delete a certain line; delete all the content and exit.

#include <iostream>
#include <string>
#include <fstream>
#include "TextBuddy.h"

using namespace std;

const string MESSAGE_START = "Welcome to TextBuddy. %s is ready for use";
const string MESSAGE_EMPTY = "%s is empty";
const string MESSAGE_ADDED = "added to %s: \"%s\"";
const string MESSAGE_DELETED = "deleted from %s: \"%s\"";
const string MESSAGE_CLEARED = "all content deleted from %s";
const string MESSAGE_INVALID_FORMAT = "invalid command format";

const int INITIAL_LINENUMBER = 1;
char buffer[300];

int main(int argc, char* argv[]){
	string fileName;
	//Check the number of parameters
	//Tell the user to enter fileName if the command is entered incorrectly
	if(argc < 2) {
		cerr << "Usage: " << argv[0] << "fileName" << endl;
		return 1;
	}

	fileName = argv[1];
	TextBuddy::displayWelcomeMessage(fileName);

	string userCommand;
	cout << "command: " <<endl;
	while(getline(cin, userCommand)){
		TextBuddy::exercuteUserCommand(fileName, userCommand);
		cout << "command: " <<endl;
	}

	return 0;
}
fdsafdsa;

void TextBuddy::displayWelcomeMessage(string fileName) {
	sprintf_s(buffer, MESSAGE_START.c_str(), fileName.c_str());
	cout << buffer << endl;
}

//This method is to determine the command type so that the userCommand is ready for further processing
TextBuddy::CommandType TextBuddy::determineCommandType(string command) {
	if (command == "add"){
		return ADD_LINE;
	}
	else if (command == "display") {
		return DISPLAY_ALL;
	}
	else if (command == "delete") {
		return DELETE_LINE;
	}
	else if (command == "clear") {
		return CLEAR_ALL;
	}
	else if (command == "exit") {
		return EXIT;
	}
	else
		return INVALID;
}

//This method takes in user command and then process it accordingly
void TextBuddy::exercuteUserCommand(string fileName, string userCommand) {
	CommandType CommandType;
	string content;
	
	CommandType = determineCommandType(getCommandType(userCommand));
	content = getContent(userCommand);
	
	switch (CommandType)
	{
		case ADD_LINE:
			return addContent(fileName, content);
		
		case DISPLAY_ALL:
			return displayAll(fileName);
		
		case DELETE_LINE:
			return deleteContent(fileName, content);
		
		case CLEAR_ALL:
			return clearAll(fileName);
		
		case EXIT:
			exit(0);
		
		case INVALID:
			sprintf_s(buffer, MESSAGE_INVALID_FORMAT.c_str());
		    cout << buffer <<endl;
		
		default:
			break;
	}
	
}

string TextBuddy::getCommandType(string userCommand){
	int TEnd;
	TEnd = userCommand.find_first_of(" ");
	
	return userCommand.substr(0, TEnd);
}

string TextBuddy::getContent(string userCommand){
	int TStart;
	TStart = userCommand.find_first_of(" ")+1;

	return userCommand.substr(TStart);
}

//This method is to add in new information to the file and then tell the user that the content is added
void TextBuddy::addContent(string fileName, string content){
	ofstream file;
	file.open(fileName, ios::app);
	file << content <<endl;
	file.close();
    
	sprintf_s(buffer, MESSAGE_ADDED.c_str(), fileName.c_str(), content.c_str());
	cout << buffer << endl;
}

//This method is to show all the information in the file and empty if nothing is inside the file
void TextBuddy::displayAll(string fileName){
	ifstream file;
	file.open(fileName);

	string line;
	int lineNumber = INITIAL_LINENUMBER;
	
	while(getline(file, line)){
		cout << lineNumber << ". " << line << endl;
		lineNumber++;
	}

	if(lineNumber == INITIAL_LINENUMBER){
		sprintf_s(buffer, MESSAGE_EMPTY.c_str(), fileName.c_str());
		cout << buffer << endl;
	}

	file.close();

	return;
}

//This method is to delete a certain information that provided by the user and then tell user that it is deleted
void TextBuddy::deleteContent(string fileName, string content){
	int lineNumber = stoi(content);
	
	ifstream originalFile;
	originalFile.open(fileName);
	
	ofstream modifiedFile;
	modifiedFile.open("TFile.txt");
	
	string TLine;
	string deletedLine;
	int TCount = 1;
	
	while(getline(originalFile, TLine)){
		if (TCount == lineNumber){
			deletedLine = TLine;
		}
		else{
			modifiedFile << TLine << endl;
		}
		TCount++;
	}
	
	originalFile.close();
	modifiedFile.close();
	
	remove(fileName.c_str());
	rename("TFile.txt", fileName.c_str());
	
	sprintf_s(buffer, MESSAGE_DELETED.c_str(), fileName.c_str(), deletedLine.c_str());
    cout << buffer << endl;
}

//This method is to clear all the information in the file
void TextBuddy::clearAll(string fileName){
	ifstream file;
	file.open("TFile.txt");
	file.close();
	
	remove(fileName.c_str());
	rename("TFile.txt", fileName.c_str());
	
	sprintf_s(buffer, MESSAGE_CLEARED.c_str(), fileName.c_str());
    cout << buffer << endl;
}