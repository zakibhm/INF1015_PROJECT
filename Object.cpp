#include "Object.hpp"

string Object::nameWithoutSpace()
{
	string newName = name_;
	newName.erase(remove(newName.begin(), newName.end(), ' '), newName.end());
	return newName;
}





