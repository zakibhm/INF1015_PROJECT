#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <functional>

#include "Vue.h"

class Controleur {
public:
	Controleur(std::shared_ptr<Vue> vue, std::map<std::string, std::shared_ptr<Objet>> objets);
	void saise();

	

	std::pair<std::string, std::string> sliceString();

private:
	void executerCommande(std::pair<std::string, std::string> commande);
private:
	std::map<std::string, std::function<void(std::string)>> commandes_;
	std::map<std::string, std::shared_ptr<Objet>> objets_;
	std::string message_;
	std::shared_ptr<Vue> ptrVue_;
};