#include"Controller.hpp"



void Controller::changeRoom(string direction, const string& message1,string commande) {
	if(currentRoom_->isDoubleLink() && currentRoom_->getDirections().count(commande))
	{
		auto room = currentRoom_->getDirection(direction);
		cout << message1 << endl;
		currentRoom_ = room;
		currentRoom_->showRoom();
	}
	else
	{
		cout << wrongDirection;
	}
}

void Controller::setCurrentRoom(shared_ptr<Room> room) {
	currentRoom_ = room;
}
void Controller::addRoom(shared_ptr<Room> room)
{
	rooms_.insert(make_pair(room->getName(), room));
}

void Controller::creatingSpecialRooms() {
	roomR_  = make_shared<Room>(roomRName, roomRDescription, true);
	addRoom(roomR_) ;
	darkAttic_ = make_shared<Room>(darkAtticName, darkAtticDescription, false);
	addRoom(darkAttic_);
	cave_ = make_shared<Room>(caveName, caveDescription, false);
	addRoom(cave_);
}

void Controller::linkRoomR()
{
	shared_ptr<Room> mainHallWay = this->getCurrentRoom();
	roomR_->setDirection(west, mainHallWay);
	mainHallWay->setDirection(east, roomR_);
}


void Controller::addObject(shared_ptr<Object> object)
{
	objects_.insert(make_pair(object->getName(), object));
}


vector<shared_ptr<Object >> Controller::objectsToUse()
{
	vector<shared_ptr<Object >> vec;
	for (auto&& object : currentRoom_->getObjects())
	{
		vec.push_back(object.second);
	}

	for (auto&& object : objects_)
	{
		vec.push_back(object.second);
	}
	return vec;
}

void Controller::useObject(string objectName)
{
	bool objectNotFound = true;
	for (auto&& object : objectsToUse())
	{
		if (((object->getName().find(objectName) != string::npos) || (object->nameWithoutSpace().find(objectName) != string::npos)) && (objectName.size() > 2))
		{
			objectNotFound = false;
			if(object->getName() == keyName)
			{
				if(currentRoom_->getName() == mainHallWayName)
				{
					cout << object->getUsingMessage() << endl << endl;
					linkRoomR();
				}
				else
				{
					cout <<usingKeyWrongRoom << endl << endl;
				}
			}
			else if (object->getName() == hammerName)
			{
				if(currentRoom_->getName() == kitchenName)
				{
					cout << object->getUsingMessage() << endl << endl;
					currentRoom_ = rooms_.at(caveName);
					currentRoom_->showRoom();
				}
				else
				{
					cout << usingHammerWrongRoom << endl << endl;
				}
			}

			else if (object->getName() == ladderName && currentRoom_->getName() == bedroomName)
			{
				cout << ladderUp << endl;
				currentRoom_= rooms_.at(darkAtticName);
				currentRoom_->showRoom();

			}
			else if (object->getName() == ladderName && currentRoom_->getName() == darkAtticName)
			{
				cout << ladderDown << endl;
				currentRoom_ = rooms_.at(bedroomName);
				currentRoom_->showRoom();
			}
			

			else if (object->getName() == ropeName && currentRoom_->getName() ==caveName)
			{
				cout <<  usingMessageRope<<endl;
				currentRoom_ = rooms_.at(kitchenName);
				currentRoom_->showRoom();
			}
			else if (object->getName() == tobogganName)
			{
				cout << object->getUsingMessage() << endl << endl;
				currentRoom_ = rooms_.at(kitchenName);
				currentRoom_->showRoom();
			}
			else
			{
				cout << object->getUsingMessage() << endl<<endl;
			}

				
			break;
		}	
		
	}
	if (objectNotFound)
		{
		cout << noObjectToUse << endl << endl;
		}
}


void Controller::takeObject(string objectName)
{
	bool objectNotFound = true;
	for (auto&& object : currentRoom_->getObjects())
	{
		if ( (object.second->getName().find(objectName) != string::npos) || (object.second->nameWithoutSpace().find(objectName) != string::npos) )
		{
			objectNotFound = false;
			if (object.second->isheavy())
			{
				cout << object.second->getTakingMessage() << endl << endl;
			}
			else 
			{
				addObject(object.second);
				cout << object.second->getTakingMessage() << endl << endl;
			}
			break;
		}
	}
	if (objectNotFound) {
		cout << noObjectToTake << endl << endl;
	}
}


void Controller::lookObject(string objectName)
{
	if (objectName == "")
	{
		currentRoom_->showRoom();
	}
	else
	{
		bool objectNotFound = true;
		for (auto&& object : currentRoom_->getObjects())
		{
			if ((object.second->getName().find(objectName) != string::npos) || (object.second->nameWithoutSpace().find(objectName) != string::npos))
			{
				objectNotFound = false;
				cout << object.second->getDescription() << endl << endl;
				break;
			}
		}
		if (objectNotFound) {
			cout << noObjectToShow << endl << endl;
		}
	}
}


void Controller::executeCommande(string commande, string object) {
	gameNotOver_ = true;

	if (commande == lookCommande)
	{
		lookObject(object);
	}

	else if (commande == takeCommande)
	{
		takeObject(object);
	}

	else if (commande ==useCommande)
	{
		useObject(object);
	}
	else if (commande == exitCommande)
	{
		gameNotOver_ = false;
		cout << gameOver << endl;
	}	

	else if (commande == north)
	{
		changeRoom(north, goNorth,commande);
	}
	else if (commande == south)
	{
		changeRoom(south,goSouth,commande);
	}
	else if (commande == east)
	{
		changeRoom(east,goEast,commande);
	}
	else if (commande == west)
	{
		changeRoom(west, goWest,commande);
	}
	else {
		cout << inputError;
	}
}


