#ifndef PLAYERASTATT_H
#define PLAYERASTATT_H

#include "state.h"
class Game;

class PlayerAState : public State
{
public:
	PlayerAState(Game* game);


	// State interface
public:
	void init();
	void handleInput();
	void update();
	//void render(); // calling GUI methods in mainWindow!
};

#endif // PLAYERASTATT_H
