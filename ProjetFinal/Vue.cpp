#include "Vue.h"

Vue::Vue(std::shared_ptr<Salle> salle) : salleActuelle_(salle)
{
}

void Vue::afficher()
{
	salleActuelle_->afficher(std::cout);

	std::cout << erreur_ << "\n";
	erreur_ = "";
	std::cout << ">> ";
}

void Vue::setSalle(std::shared_ptr<Salle> salle)
{
	salleActuelle_ = salle;
}

std::shared_ptr<Salle> Vue::getSalle()
{
	return salleActuelle_;
}

void Vue::setErreur(std::string erreur)
{
	erreur_ = erreur;
}
