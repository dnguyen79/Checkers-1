#ifndef MARKEDASTATE_H
#define MARKEDASTATE_H

//#include "state.h"
#include "game.h"
class Game;

class MarkedAState : public State
{
	//friend class Game;

public:
	MarkedAState(Game* game);
	//~MarkedAState();

	// State interface
public:
	void init();
	void playerWasPressed(Position position);
	void tileWasPressed(Position position);
	void update();
	//void render(); // calling GUI methods in mainWindow!
};

#endif // MARKEDASTATE_H
