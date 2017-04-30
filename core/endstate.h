#ifndef ENDSTATE_H
#define ENDSTATE_H

//#include "state.h"
#include "game.h"
class Game;

class EndState : public State
{
public:
	EndState(Game* game);
public:
	void init();
	void playerWasPressed(Position position);
	void tileWasPressed(Position position);
	void update();
};
#endif // ENDSTATE_H
