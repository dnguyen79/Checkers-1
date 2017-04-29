#include "playerastate.h"

#include <QDebug>
PlayerAState::PlayerAState(Game *game)
	:State(game)
{
	this->init();
}

void PlayerAState::init()
{
	qDebug("playerAState!");
}

void PlayerAState::handleInput()
{

}

void PlayerAState::update()
{

}
