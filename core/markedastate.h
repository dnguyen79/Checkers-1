#ifndef MARKEDASTATE_H
#define MARKEDASTATE_H

//#include "state.h"
#include "game.h"
class Game;

class MarkedAState : public State
{

public:
	MarkedAState(Game* game);
	void init();
	void playerWasPressed(Position position);
	void tileWasPressed(Position position);
	void update();
};

#endif // MARKEDASTATE_H
