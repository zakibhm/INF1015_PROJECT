/*

*dans  ce programme, on doit créer des salles et les relier entre elles avec les différentes directions (E, O, S, N)



* fichier main.cpp

* auteurs:				Farid Baba    Sidali Boukhezar

* Matricule:			1805602	   	  2183332

* date de remise:  12 décembre 2022

*/
#pragma once
#include "Vue.h"
#include "Controleur.h"
#include "Objet.h"



int main() {

	// initialisation des salles
	shared_ptr<Salle> chambre = make_shared<Salle>("la chambre", " cette piece  n'est pas rangee");
	shared_ptr<Salle> cuisine = make_shared<Salle>("la cuisine", " dans ces piece, il y a l'eau qui coule", true);
	shared_ptr<Salle> entree = make_shared<Salle>("l'entree", "vous etes a l'entree principale");
	shared_ptr<Salle> salon = make_shared<Salle>("le salon", " cette piece est en renovation");
	shared_ptr<Salle> couloir = make_shared<Salle>("le couloir", "dans cette piece, les lumieres ne fonctionnent pas");

	// Organisation
	couloir->ajouterSalle("N", cuisine);	//couloir
	couloir->ajouterSalle("S", entree);
	couloir->ajouterSalle("W", chambre);

	cuisine->ajouterSalle("S", couloir);	//cuisine

	chambre->ajouterSalle("E", couloir);	//chambre

	entree->ajouterSalle("N", couloir);		//entrée
	entree->ajouterSalle("E", salon);

	salon->ajouterSalle("W", entree);		//salon

	// Initialisation des objets
	Objet piano;
	piano.nom = "piano";
	piano.description = "Instrument de musique";
	piano.salle = "le salon";

	Objet cle;
	cle.nom = "cle";
	cle.description = "Permet d'ouvruir";
	cle.salle = "la cuisine";


	// Initialisation des ptr objets
	shared_ptr<Objet> ptrPiano = make_shared<Objet>(piano);
	cuisine->ajouterObjet(ptrPiano);

	shared_ptr<Objet> ptrCle = make_shared<Objet>(cle);
	chambre->ajouterObjet(ptrCle);

	// initialisation de la map objets
	std::map<std::string, shared_ptr<Objet>> objets;
	objets["piano"] = ptrPiano;
	objets["cle"] = ptrCle;

	// Initisaliser la vue avec la salle de depart
	std::shared_ptr<Vue> vue = std::make_shared<Vue>(entree);

	// Initialisation du controlleur
	Controleur controleur(vue, objets);

	while (vue->run) 
	{
		vue->afficher();
		controleur.saise();
	}


	return 0;
}
