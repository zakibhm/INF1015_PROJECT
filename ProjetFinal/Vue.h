#pragma once
#include "memory"

#include "Salle.h"

class Vue {
public:
	Vue(std::shared_ptr<Salle> salle);
	void afficher();
	void setSalle(std::shared_ptr<Salle> salle);
	std::shared_ptr<Salle> getSalle();
	void setErreur(std::string erreur);

	bool run = true;
	std::shared_ptr<Objet> cle_;


private:
	std::string erreur_ = "";
	std::shared_ptr<Salle> salleActuelle_;
	std::shared_ptr<Objet> objetActuelle = nullptr;
};