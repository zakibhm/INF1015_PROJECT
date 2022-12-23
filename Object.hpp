#pragma once
#include <memory>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
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
	bool isheavy() { return heavy_; }
	string getTakingMessage() const { return takingMessage_; }
	////////////////////////////////////////////////////////////////

	string nameWithoutSpace();

private:
	string name_;
	string description_;
	string currentRoom_;
	string usingMessage_;
	string takingMessage_;
	bool heavy_;

};
