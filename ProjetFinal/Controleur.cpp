#include "Controleur.h"

Controleur::Controleur(std::shared_ptr<Vue> vue, std::map<std::string, std::shared_ptr<Objet>> objets) : ptrVue_(vue), objets_(objets)
{
	auto changerSalle = [&](std::string direction) {
		auto salle = ptrVue_->getSalle();
		auto nouvelleSalle = salle->getDirections()[direction];
		if (nouvelleSalle->getVerouille()) {
			auto c = ptrVue_->cle_;

			if (c != nullptr) {
				if (nouvelleSalle->deverouiller(c->salle)) {
					ptrVue_->setSalle(nouvelleSalle);
				}
			}

			else {
				ptrVue_->setErreur("Salle verouille");
			}
		}
		else {
			ptrVue_->setSalle(salle->getDirections()[direction]);
		}
	};

	auto regarder = [&](std::string a) {
		if (a == "Look") {
			ptrVue_->afficher();
		}
		else {

			ptrVue_->setErreur(objets_[a]->description);
		}
	};

	auto prendre = [&](std::string objet) {
		ptrVue_->cle_ = objets_[objet];
	};

	auto quitter = [&](std::string = "") {
		ptrVue_->run = false;
	};

	commandes_["N"] = changerSalle;
	commandes_["S"] = changerSalle;
	commandes_["E"] = changerSalle;
	commandes_["W"] = changerSalle;
	commandes_["Look"] = regarder;
	commandes_["Take"] = prendre;
	commandes_["Exit"] = quitter;
};

void Controleur::saise()
{
	std::getline(std::cin, message_);

	auto p = sliceString();
	
	auto commande = commandes_.find(p.first);

	if (commande != commandes_.end()) {
		executerCommande(p);
	}
	else {
		ptrVue_->setErreur("Commande invalide!");
	}
}

void Controleur::executerCommande(std::pair<std::string, std::string> commande)
{
	commandes_.at(commande.first)(commande.second);
}

std::pair<std::string, std::string> Controleur::sliceString()
{
	std::string line;
	std::vector<std::string> vec;
	std::stringstream ss(message_);

	while (std::getline(ss, line, ' ')) {
		vec.push_back(line);
	}

	if (vec.size() > 1) {
		return std::make_pair(vec[0], vec[1]);
	}

	else 
	{
		return 	std::make_pair(vec[0], vec[0]);
	}
}