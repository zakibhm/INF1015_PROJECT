#include"Controller.hpp"


void Controller::addRoom(shared_ptr<Room> room) { 
	rooms_.insert(make_pair(room->getName(), room)); 
}

void Controller::changeRoom(string direction, const string& message1) {
	auto room = currentRoom_->getDirection(direction);

	cout << message1 << endl;
	currentRoom_ = room;
	currentRoom_->showRoom();
}

void Controller::setCurrentRoom(shared_ptr<Room> room) {
	currentRoom_ = room;
}


void Controller::creatingSpecialRooms() {
	roomR_ = make_shared<Room>("Room R", "This is a strange room with red walls");
	darkAttic_ = make_shared<Room>("Dark attic", "This attic is dark, you only see a ladder go down");
	cave_ = make_shared<Room>("Deep cave", "This is a scary cave under the kitchen ,be careful there are bats here !!");
}

void Controller::linkRoomR()
{
	shared_ptr<Room> mainHallWay = this->getCurrentRoom();
	roomR_->setDirection("E", mainHallWay);
	mainHallWay->setDirection("W", roomR_);
	this->addRoom(roomR_);
	currentRoom_->showRoom();
}

void Controller::linkCave()
{
	shared_ptr<Room> kitchen = this->getCurrentRoom();
	cave_->setDirection("N", kitchen);
	kitchen->setDirection("S", cave_);
	this->addRoom(cave_);
	currentRoom_->showRoom();
}

void Controller::linkDarkAttic()
{
	shared_ptr<Room> bedRoom = this->getCurrentRoom();
	darkAttic_->setDirection("S", bedRoom);
	bedRoom->setDirection("N", darkAttic_);
	this->addRoom(darkAttic_);
	currentRoom_->showRoom();
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
	for (auto&& object : objectsToUse())
	{
		//if (count(object.second->getkeyWords().begin(), object.second->getkeyWords().end(), objectName))
		if ((object->getName().find(objectName) != string::npos) || (object->nameWithoutSpace().find(objectName) != string::npos))
		{
			if(object->getName() == "small green key" && currentRoom_->getName() == "Main Hallway")
			{
				cout << object->getUsingMessage() << endl;
				linkRoomR();
			}
			else if (object->getName() == "ladder" && currentRoom_->getName() == "Small Bedroom")
			{
				cout << "You go up the ladder" << endl;
				linkDarkAttic();
				currentRoom_=currentRoom_->getDirection("N");
			}
			else if (object->getName() == "ladder" && currentRoom_->getName() == "Dark attic")
			{
				cout << "You go down the ladder" << endl;
				currentRoom_ = currentRoom_->getDirection("S");
				currentRoom_->showRoom();
			}
			else if (object->getName() == "silver hammer" && currentRoom_->getName() == "Kitchen")
			{
				cout << object->getUsingMessage() << endl;
				linkCave();
				currentRoom_ = currentRoom_->getDirection("S");
			}

			else if (object->getName() == "old tall rope" && currentRoom_->getName() == "Black cave")
			{
				cout << "You use the rope to climb up to the kitchen" << endl;
				currentRoom_ = currentRoom_->getDirection("N");
				currentRoom_->showRoom();
			}
			else
			{
				cout << object->getUsingMessage() << endl;
				currentRoom_->showRoom();
			}

				
			break;
		}	
	}
}


void Controller::takeObject(string objectName)
{
	for (auto&& object : currentRoom_->getObjects())
	{
		if ( (object.second->getName().find(objectName) != string::npos) || (object.second->nameWithoutSpace().find(objectName) != string::npos) )
		{
			if (object.second->isheavy())
			{
				cout << object.second->getTakingMessage() << endl;
			}
			else 
			{
				addObject(object.second);
				cout << object.second->getTakingMessage() << endl;
			}
			break;
		}
	}
}



void Controller::executeCommande(string commande, string object) {
	gameNotOver_ = true;

	if (!(currentRoom_->getDirections().count(commande)))
	{
		if (commande == "Look" && object =="")
		{
			currentRoom_->showRoom();
		}

		else if (commande == "take" && currentRoom_->getObjectsNumber() > 0)//&& count(currentRoom_->getKeyWordsVec().begin(), currentRoom_->getKeyWordsVec().end(),object)
		{
			takeObject(object);
		}

		else if (commande == "use" && currentRoom_->getObjectsNumber() > 0)// && count(currentRoom_->getKeyWordsVec().begin(), currentRoom_->getKeyWordsVec().end(), object)
		{
			useObject(object);
		}
		else if (commande == "exit")
		{
			gameNotOver_ = false;
			cout << "ok game done now, go away !" << endl;
		}
		else {
			cout << "Invalid Input!! \n";
			currentRoom_->showRoom();
		}
		
	}
	else 
	{
		if (commande == "N")
		{
			changeRoom("N", "Going North");
		}
		else if (commande == "S")
		{
			changeRoom("S", "Going South");
		}
		else if (commande == "E")
		{
			changeRoom("E", "Going East");
		}
		else if (commande == "W")
		{
			changeRoom("W", "Going West");
		}
	}
}


