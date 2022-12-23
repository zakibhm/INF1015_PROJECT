#pragma once
#include <string>
#include <iostream>
using namespace std;

//Game messages
const string gamePresentationMessage = ">>>>>>>> INF1015 DUNGEON CRAWLER 2022 <<<<<<<<<\n>  >  >  >  GAME OF THE YEAR EDITION  <  <  <  <\n\n";
const string noObjectToUse = "This object is unavailable to use";
const string noObjectToTake = "There is no object with this name to take in this room";
const string noObjectToShow = "There is no object with this name to show in this room";
const string gameOver = "ok game done now, go away !";
const string goNorth = "Going North\n";
const string goWest = "Going West\n";
const string goEast = "Going East\n";
const string goSouth = "Going South\n";
const string wrongDirection = "Invalid Direction!! \n\n";
const string inputError = "Invalid Input!! \n\n";
const string north = "N";
const string south = "S";
const string east = "E";
const string west = "W";
const string lookCommande = "look";
const string takeCommande = "take";
const string useCommande = "use";
const string exitCommande = "exit";
///////////////////////////////////////////////////////////////////




//Data of Rooms
const std::string enteranceName = "Entrance";
const std::string enternanceDescription = "This is the entrance of the house you notice golden lights at the top";

const std::string mainHallWayName = "Main Hallway";
const std::string mainHallWayDescription = "This is the main hallway. There is a bunch of boxes against the wall, but you see a small keyhole between boxes.";

const std::string livingRoomName = "Living Room";
const std::string livingRoomDescription = "This is the living room. There is a TV with PS5 to play games and a couch to had some rest.";

const std::string kitchenName = "Kitchen";
const std::string kitchenDescription = "This is the Kitchen. All the food is coocked here.";

const std::string officeName = "Working Office";
const std::string officeDescription = "This is the working office. It contains all the tools for studying and programming.";

const std::string bedroomName = "Small Bedroom";
const std::string bedRoomDescription = "This is the small bedroom. It is not particularly clean or well organised. There is a small window.";

const std::string roomRName = "Room R";
const std::string roomRDescription = "This is a strange room with red walls";

const std::string caveName = "Deep cave";
const std::string caveDescription = "This is a scary cave under the kitchen ,be careful there are bats here !!";

const std::string darkAtticName = "Dark attic";
const std::string darkAtticDescription = "This attic is dark, you only see a ladder go down";
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




//Data of Objects
const string pianoName = "cheap electric piano";
const string pianoDescription = "this is an old entery-level yamaha with 61 keys. it looks like any cheap stuff from the late 90s";
const string usingMessagePiano = "you play some chords on the piano. it does not sound very well";
const string takingMessagePiano = "this piano is too cumbersome to carry arround";


const string hammerName = "silver hammer";
const string hammerDescription = "This is a silver hammer. It is a very powrful hammer used to break the shaky grounds";
const string usingMessageHammer = "You did Break the Kitchen floor !!";
const string takingMessageHammer = "You had the powerful hammer with you";
const string usingHammerWrongRoom = "The ground of this room is too heavy to break it";

const string keyName = "small green key";
const string keyDescription = "This is a green key used to unlock new rooms !!" ;
const string usingMessagekey = "A passage to Room R opens" ;
const string takingMessagekey = "The keys are in your pocket";
const string usingKeyWrongRoom = "There is no need to use keys in this room, there are no speacial rooms to unlock";

const string tvName = "Rounded plazma television";
const string tvDescription = "This is an 60 inch Rounded 4K Samsung TV. You can watch any movie that you want in it";
const string usingMessageTv = "You are watching the last film of OnePiece";
const string takingMessageTv = "You can not take the TV with you, It is too big to care !";

const string strawberryName = "red strawberry" ;
const string strawberryDescription = "This is a fresh strawberry, You can eat it if you want to have more calories to continue your way in the house";
const string usingMessageStrawberry = "You're eating the delicious strawberries";
const string takingMessageStrawberry = "You had took some strawberries with you";

const string desktopName = "working desktop";
const string desktopDescription =  "This is a working desktop. It has an i7 11th Gen with 16Gb of RAM and 1Tb ssd of hard Disk" ;
const string usingMessageDesktop = "You're sending mails to the company that you're working in";
const string takingMessageDesktop = "You can not take the Desktop with you, it's fixed on the office ";

const string ladderName = "ladder";
const string ladderDescription = "This is a tall ladder made with black wood. Be carful when you use it";
const string usingMessageLadder = "";
const string takingMessageLadder = "You can not take the ladder with you, it's fixed on the top of the bedroom";
const string ladderUp = "You go up the ladder";
const string ladderDown = "You go down the ladder\n";

const string ropeName = "old tall rope";
const string ropeDescription = "This is a tall strong rope. You can use it to go up to the kitchen after you falled";
const string usingMessageRope = "You use the rope to climb up to the kitchen\n";
const string takingMessageRope = "You can not take the rope with you, it's fixed on the top of the cave";

const string tobogganName = "blue toboggan";
const string tobogganDescription = "This is a blue toboggan that leads you directly to the kitchen";
const string usingMessageToboggan = "Youpiiiii, let's go to the kitchen";
const string takingMessageToboggan = "This object is too big to take it with you!!";

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
