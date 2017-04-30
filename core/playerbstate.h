#ifndef PLAYERBSTATE_H
#define PLAYERBSTATE_H

//#include "state.h"
#include "game.h"
class Game;

class PlayerBState : public State
{

public:
	PlayerBState(Game* game);
	//~PlayerAState();
	// State interface
	void init();
	void playerWasPressed(Position position);
	void tileWasPressed(Position position);
	void update();
	//void render(); // calling GUI methods in mainWindow!
};

#endif // PLAYERBSTATE_H
