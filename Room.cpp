#include "Room.hpp"


void Room::showRoom() const {
	string string = "--" + name_ + "--" + "\n" + description_ + "\n";
	if (objects_.size() > 0)
	{
		string+= "You notice :\n";
		for (auto&& object : objects_)
		{
			string += "\t" + object.second->getName() + "\n";
		}
	}
	if (directions_.count("N") && doubleLink_) { string += directions_.at("N")->name_ + " is to the North (N) \n"; }
	if (directions_.count("E") && doubleLink_) { string += directions_.at("E")->name_ + " is to the East (E) \n"; }
	if (directions_.count("S") && doubleLink_) { string += directions_.at("S")->name_ + " is to the South (S) \n"; }
	if (directions_.count("W") && doubleLink_) { string += directions_.at("W")->name_ + " is to the West (W) \n"; }
	
	cout << string << endl;
}


void Room::addObject(shared_ptr<Object> object) {
	objects_.insert(make_pair(object->getName(), object));
}

void Room::setDirection(const string direction, const shared_ptr<Room> room)
{
	directions_[direction] = room;
}