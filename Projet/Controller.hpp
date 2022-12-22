#pragma once
#include "Room.hpp"
#include <memory>
#include <map>
class Controller {
public:
	
	//				Getters
	shared_ptr<Room> getCurrentRoom() { return currentRoom_; }
	shared_ptr<Room> getRoom(string roomKey) {return rooms_.at(roomKey);}
	bool gameNotOver() const {return gameNotOver_;}
	shared_ptr<Room> getRoomR() const { return roomR_; }
	shared_ptr<Room> getCave() const { return cave_; }
	shared_ptr<Room> getDarkAttic() const { return darkAttic_; }

	/////////////////////////////////////////////////////////////////////


	//				Room Control
	void addRoom(shared_ptr<Room> room);
	void changeRoom(string direction, const string& message1);
	void setCurrentRoom(shared_ptr<Room>);
	void creatingSpecialRooms();
	void linkRoomR();
	void linkCave();
	void linkDarkAttic();
	///////////////////////////////////////////////////////////////////////


	//				Object Control
	//void createNewObject();
	void addObject(shared_ptr<Object> object);
	void useObject(string objectName);
	void takeObject(string objectName);
	vector<shared_ptr<Object >> objectsToUse();
	///////////////////////////////////////////////////////////////////////////////

	
	//				Commande Control
	void executeCommande(string commande, string object);
	///////////////////////////////////////////////////////////////////////////////

private:

	map<string, shared_ptr<Room>> rooms_;
	map<string, shared_ptr<Object>> objects_;
	shared_ptr<Room> currentRoom_;
	bool gameNotOver_ = true ;
	shared_ptr<Room> roomR_, cave_, darkAttic_;
};
