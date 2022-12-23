#include "View.hpp"

void GameView::setMap()
{
	
	//Creating Rooms 
	shared_ptr<Room> entrance = make_shared<Room>(enteranceName,enternanceDescription);
	shared_ptr<Room> mainHallway = make_shared<Room>(mainHallWayName, mainHallWayDescription);
	shared_ptr<Room> livingRoom = make_shared<Room>(livingRoomName,livingRoomDescription);
	shared_ptr<Room> kitchen = make_shared<Room>(kitchenName,kitchenDescription);
	shared_ptr<Room> office = make_shared<Room>(officeName,officeDescription);
	shared_ptr<Room> bedRoom = make_shared<Room>(bedroomName, bedRoomDescription);

	controller_->addRoom(entrance);
	controller_->addRoom(mainHallway);
	controller_->addRoom(livingRoom);
	controller_->addRoom(kitchen);
	controller_->addRoom(office);
	controller_->addRoom(bedRoom);
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//Creating SpeacialRooms 
	controller_->creatingSpecialRooms();
	/////////////////////////////////////////////////////////////////////////////////////
	

	//Linking Rooms
	entrance->setDirection("E", livingRoom);
	livingRoom->setDirection("W", entrance);
	entrance->setDirection("W", kitchen);
	kitchen->setDirection("E", entrance);
	entrance->setDirection("N", mainHallway);
	mainHallway->setDirection("S", entrance);
	mainHallway->setDirection("N", office);
	office->setDirection("S", mainHallway);
	mainHallway->setDirection("W", bedRoom);
	bedRoom->setDirection("E", mainHallway);
	//////////////////////////////////////////////////////////////////////////////////////////

	////Creating Objects 
	shared_ptr<Object> piano = make_shared<Object>(pianoName, pianoDescription, usingMessagePiano, takingMessagePiano,true);
	shared_ptr<Object> hammer = make_shared<Object>(hammerName,hammerDescription,usingMessageHammer ,takingMessageHammer, false);
	shared_ptr<Object> key = make_shared<Object>(keyName,keyDescription ,usingMessagekey ,takingMessagekey ,false);
	shared_ptr<Object> tv = make_shared<Object>(tvName,tvDescription ,usingMessageTv,takingMessageTv, true);
	shared_ptr<Object> strawberry = make_shared<Object>(strawberryName,strawberryDescription ,usingMessageStrawberry,takingMessageStrawberry , false);
	shared_ptr<Object> desktop = make_shared<Object>(desktopName,desktopDescription,usingMessageDesktop,takingMessageDesktop, true);
	shared_ptr<Object> ladder = make_shared<Object>(ladderName,ladderDescription ,usingMessageLadder,takingMessageLadder,true);
	shared_ptr<Object> rope = make_shared<Object>(ropeName,ropeDescription,usingMessageRope,takingMessageRope, true);
	shared_ptr<Object> toboggant = make_shared<Object>(tobogganName, tobogganDescription, usingMessageToboggan, takingMessageToboggan, true);

	////adding Objects to rooms
	entrance->addObject(hammer);
	entrance->addObject(key);
	livingRoom->addObject(tv);
	livingRoom->addObject(piano);
	kitchen->addObject(strawberry);
	controller_->getCave()->addObject(rope);
	office->addObject(desktop);
	controller_->getDarkAttic()->addObject(ladder);
	bedRoom->addObject(ladder);
	bedRoom->addObject(toboggant);
	controller_->setCurrentRoom(entrance);
}


void GameView::terminalViewStyle()
{
	cout << "> ";
}

void GameView::gamePresentation()
{
	cout << gamePresentationMessage;
}

pair<string, string>  GameView::splitCommande(string commande)
{
	pair<string, string> combination;
	size_t pos = commande.find(" ");
	combination.first = commande.substr(0,pos);
	if (pos == string::npos)
		combination.second = "";
	else
		combination.second = commande.substr(pos+1);
	return combination;
}

void GameView::ReadCoammande()
{
	terminalViewStyle();
	string commande;
	getline(cin >> ws, commande);
	auto pair = splitCommande(commande);
	controller_->executeCommande(pair.first, pair.second);

}


