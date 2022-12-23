/*
* Date: 22 decembre 2022
* NOMS: MOUALDI    Sofiane     2115145
*       BOUCHAMA   Zekaria     2174321
* 
* Titre: Livrable 2 projet INF1015
* 
* 
* Description : Ce livrable est une conception logicielle d'une disposition d'un ensemble de salles où le personnage peut 
*               traverser de salles en salles à la découverte de nouvelles salles. Chaque salle contient des objets avec lesquels le joueur peut interragir.

*/

#include "View.hpp"
using namespace std;

int main() {

	unique_ptr<Controller> gameController = make_unique<Controller>();
	unique_ptr<GameView> gameView = make_unique<GameView>(move(gameController));
	while (gameView->GameNotOver())
	{
		gameView->ReadCoammande();
	}
	
};

