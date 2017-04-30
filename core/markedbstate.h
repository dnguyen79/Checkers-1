#ifndef MARKEDBSTATE_H
#define MARKEDBSTATE_H

//#include "state.h"
#include "game.h"
class Game;

class MarkedBState : public State
{
public:
	MarkedBState(Game* game);
	void init();
	void playerWasPressed(Position position);
	void tileWasPressed(Position position);
	void update();
};

#endif // MARKEDBSTATE_H
