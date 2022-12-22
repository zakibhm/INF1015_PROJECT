#include <memory>
#include <map>
#include "string"
#include <vector>
#include <iostream>

#include "Objet.h";

using namespace std;

class Salle {
public:
	Salle(const string& nom, const string& description, bool verouille = false) : nom_(nom), description_(description), verouille_(verouille) {};

	string getNom() const;
	string getDescription() const;
	map<string, shared_ptr<Salle>>& getDirections();
	void ajouterSalle(string d, shared_ptr<Salle> s);
	void ajouterObjet(shared_ptr<Objet> objet) {
		objets_.push_back(objet);
	}
	std::ostream& afficher(std::ostream& o);

	bool deverouiller(std::string objet);
	bool getVerouille() {
		return verouille_;
	};

private:
	bool verouille_;
	string nom_;
	string description_;
	map<string, shared_ptr<Salle>> directions_;
	vector<shared_ptr<Objet>> objets_;
};
