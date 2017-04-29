#include "markedastate.h"

#include <QDebug>
MarkedAState::MarkedAState(Game *game)
	:State(game)
{
	init();
}


void MarkedAState::init()
{
	qDebug("MarkedAState!");
}

void MarkedAState::playerWasPressed(Position position)
{

}

void MarkedAState::tileWasPressed(Position position)
{

}

void MarkedAState::update()
{

}
