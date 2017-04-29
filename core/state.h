#ifndef STATE_H
#define STATE_H

#include "game.h"

class Game;

class State
{
public:
	State(Game* game) :game(game) {}
	virtual ~State() {}
	virtual void init() = 0;
	virtual void playerWasPressed(Position position) = 0;
	virtual void tileWasPressed(Position position) = 0;
	virtual void update() = 0;

protected:
	Game* game;
};

#endif // STATE_H
