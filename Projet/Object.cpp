#include "Object.hpp"

pair <string, pair<string, char>> Object::use() const {

	cout << usingMessage_ << "\n";
	return make_pair("  ", make_pair("  ", ' '));
};

void Object::setKeyWords(const string& keyWords) {
	string words = keyWords;
	int index;
	do {
		string word;
		words.replace(0, words.find(',') + 1, "  ");
		this->keyWords_.push_back((words.substr(0, word.find(','))));
		string word2;
		word2.append(1, ',');
		index = (int)words.find(word2);

	} while (index >= 0 && index < words.length());

	this->keyWords_.push_back(keyWords);

};


string Object::nameWithoutSpace()
{
	int i = 0, j = 0;
	string newName;
	while (name_[i])
	{
		if (name_[i] != ' ')
			newName[j++] = name_[i];
		i++;
	}
	return newName;
}





