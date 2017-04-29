#ifndef PLAYERASTATT_H
#define PLAYERASTATT_H

#include "state.h"
#include "game.h"
class Game;

class PlayerAState : public State
{
	//friend class Game;

public:
	PlayerAState(Game* game);


	// State interface
public:
	void init();
	void playerWasPressed(Position position);
	void tileWasPressed(Position position);
	void update();
	//void render(); // calling GUI methods in mainWindow!
};

#endif // PLAYERASTATT_H
