#pragma once
#include <memory>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Object {
public:
	Object(const string& name,const string& description,const string& usingMessage,
		const string& takingMessage, bool heavy)
		:name_(name), description_(description), 
		usingMessage_(usingMessage), takingMessage_(takingMessage),
		 heavy_(heavy) { };

	
	
	//Getters
	string getName() const { return name_; }
	string getDescription() const { return description_ ; }
	string getUsingMessage() const { return usingMessage_ ; }
	string getcurrentRoom() const { return currentRoom_; }
	vector<string>& getkeyWords() { return keyWords_; }
	bool isheavy() { return heavy_; }
	string getTakingMessage() const { return takingMessage_; }
	////////////////////////////////////////////////////////////////

	string nameWithoutSpace();
	void setKeyWords(const string& keyWords);
	pair <string, pair<string, char>> use() const;
	string show() const{ return description_ + "\n"; };

private:
	string name_;
	string description_;
	string currentRoom_;
	string usingMessage_;
	string takingMessage_;
	bool heavy_;
	vector<string> keyWords_;

};
