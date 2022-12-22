#pragma once
#include "Controller.hpp"


class GameView {
public:

	GameView(unique_ptr<Controller> controleur) : controller_(move(controleur)) {
		setMap();
		gamePresentation();
		controller_->getCurrentRoom()->showRoom();
	};
	void ReadCoammande();
	bool GameNotOver() const { return controller_->gameNotOver(); }
	

private:
	void setMap();
	void gamePresentation();
	pair<string, string> splitCommande(string commande);
	void terminalViewStyle();

	unique_ptr<Controller> controller_;
};