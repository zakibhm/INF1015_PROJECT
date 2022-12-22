#include "Salle.h"

string Salle :: getNom() const 
{ 
    return nom_;
}

string Salle :: getDescription() const
{
    return description_;
}


map<string, shared_ptr<Salle>>& Salle::getDirections() {
	return directions_;
}

void Salle:: ajouterSalle(string d, shared_ptr<Salle> s) {
	directions_[d] = s;
}
std::ostream& Salle::afficher(std::ostream& o)
{
	o
		<< "Nom de la salle : "
		<< nom_
		<< endl
		<< "Description: "
		<< description_ 
		<< endl
		<< "Les chambres acessibles sont: \n ";

	for (auto& p : directions_)
	{
		o
			<< "\t"
			<< "dans la direction: " << p.first 
			<< " -->> "
			<< p.second->getNom()
			<< endl
			<< endl;
	}

	if (objets_.size() != 0) {
		o << "Les objets dans la salle sont: " << endl;

		for (auto& objet : objets_) {
			if (!objet->prene) {
				o << objet->nom;
			}
		}
	}

	o << endl;
	
	return o;
}
bool Salle::deverouiller(std::string objet)
{
	if (nom_ == objet) {
		verouille_ = false;
		return true;
	}
	return false;
}
;