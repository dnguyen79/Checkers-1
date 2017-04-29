#ifndef STATE_H
#define STATE_H

#include "game.h"

class Game;

class State
{
public:
	State(Game* game) :game(game) {}

	virtual void init() = 0;
	virtual void handleInput() = 0;
	virtual void update() = 0;

private:
	Game* game;
};

#endif // STATE_H
