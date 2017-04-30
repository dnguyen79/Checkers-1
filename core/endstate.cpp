#include "endstate.h"

#include <QDebug>
EndState::EndState(Game *game)
	:State(game)
{
	init();
}

void EndState::init()
{
	qDebug() << "EndState!";
	//clear sreen
}

void EndState::playerWasPressed(Position position)
{

}

void EndState::tileWasPressed(Position position)
{

}

void EndState::update()
{

}
