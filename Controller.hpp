#pragma once
#include "Room.hpp"
#include <memory>
#include <map>
#include "Data.hpp"
class Controller {
public:
	
	//Getters
	shared_ptr<Room> getCurrentRoom() { return currentRoom_; }
	bool gameNotOver() const {return gameNotOver_;}
	shared_ptr<Room> getRoomR() const { return roomR_; }
	shared_ptr<Room> getCave() const { return cave_; }
	shared_ptr<Room> getDarkAttic() const { return darkAttic_; }
	/////////////////////////////////////////////////////////////////////


	//Room Control
	void changeRoom(string direction, const string& message1,string commande);
	void setCurrentRoom(shared_ptr<Room>);
	void creatingSpecialRooms();
	void linkRoomR();
	void addRoom(shared_ptr<Room> room);
	///////////////////////////////////////////////////////////////////////


	//Object Control
	void addObject(shared_ptr<Object> object);
	void useObject(string objectName);
	void takeObject(string objectName);
	void lookObject(string objectName);
	vector<shared_ptr<Object >> objectsToUse();
	///////////////////////////////////////////////////////////////////////////////

	
	//Commande Control
	void executeCommande(string commande, string object);
	///////////////////////////////////////////////////////////////////////////////

private:
	map<string, shared_ptr<Room>> rooms_;
	map<string, shared_ptr<Object>> objects_;
	shared_ptr<Room> currentRoom_;
	bool gameNotOver_ = true ;
	shared_ptr<Room> roomR_, cave_, darkAttic_;
};
