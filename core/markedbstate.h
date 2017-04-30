#ifndef MARKEDBSTATE_H
#define MARKEDBSTATE_H

//#include "state.h"
#include "game.h"
class Game;

class MarkedBState : public State
{
	//friend class Game;

public:
	MarkedBState(Game* game);
	//~MarkedAState();

	// State interface
public:
	void init();
	void playerWasPressed(Position position);
	void tileWasPressed(Position position);
	void update();
	//void render(); // calling GUI methods in mainWindow!
};

#endif // MARKEDBSTATE_H
