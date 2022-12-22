#pragma once
#include <map>
#include "Object.hpp"
using namespace std;

class Room {
public:

	Room(const string& name, const string& description) :
		name_(name), description_(description)  {};
	
	
	//										Getters

	map<string, shared_ptr<Room>>& getDirections(){ return directions_; }
	shared_ptr<Room> getDirection(const string direction) const{ return directions_.at(direction); }
	string getName() const { return name_ + "\n"; }
	shared_ptr<Object> getObjet(const string cleObjet) { return objects_.at(cleObjet); }
	string getDescription() const { return description_ + "\n"; }
	string getObjectName(const string cleObjet) { return objects_.at(cleObjet)->getName(); }
	int getObjectsNumber() const { return (int)objects_.size(); }
	vector<string> getKeyWordsVec() const { return keyWordsVec_; }
	map<string, shared_ptr<Object>> getObjects() const{ return objects_; }

	///////////////////////////////////////////////////////////////////////////////////////////////////////////

	void showRoom() const;
	void addObject(shared_ptr<Object> object);
	void setDirection(const string direction, const shared_ptr<Room> room);
	void setKeyWords();
	
	

private:

	string name_;
	string description_;
	map<string, shared_ptr<Room>> directions_;
	map<string, shared_ptr<Object>> objects_;
	vector<string> keyWordsVec_;
};
