#pragma once
#include <map>
#include "Object.hpp"
using namespace std;

class Room {
public:

	Room(const string& name, const string& description,bool doubleLink=true) :
		name_(name), description_(description),doubleLink_(doubleLink) {};
	
	
	//Getters
	map<string, shared_ptr<Room>>& getDirections(){ return directions_; }
	shared_ptr<Room> getDirection(const string direction) const{ return directions_.at(direction); }
	string getName() const { return name_ ; }
	shared_ptr<Object> getObjet(const string cleObjet) { return objects_.at(cleObjet); }
	string getDescription() const { return description_ ; }
	string getObjectName(const string cleObjet) { return objects_.at(cleObjet)->getName(); }
	int getObjectsNumber() const { return (int)objects_.size(); }
	map<string, shared_ptr<Object>> getObjects() const{ return objects_; }
	bool isDoubleLink() const { return doubleLink_; }
	///////////////////////////////////////////////////////////////////////////////////////////////////////////

	
	void showRoom() const;
	void addObject(shared_ptr<Object> object);
	void setDirection(const string direction, const shared_ptr<Room> room);
	
	

private:

	bool doubleLink_;
	string name_;
	string description_;
	map<string, shared_ptr<Room>> directions_;
	map<string, shared_ptr<Object>> objects_;
};
