#ifndef ENDSTATE_H
#define ENDSTATE_H

//#include "state.h"
#include "game.h"
class Game;

class EndState : public State
{
	//friend class Game;

public:
	EndState(Game* game);
	//~MarkedAState();

	// State interface
public:
	void init();
	void playerWasPressed(Position position);
	void tileWasPressed(Position position);
	void update();
	//void render(); // calling GUI methods in mainWindow!
};
#endif // ENDSTATE_H
