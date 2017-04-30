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
	qDebug() << "Choose your move!";
	if(game->pressedPlayer->getPosition().x == position.x && game->pressedPlayer->getPosition().y == position.y)
	{
		game->currentState = new PlayerAState(game);
		delete this;
	}
}

void MarkedAState::tileWasPressed(Position position)
{
	if(game->tiles[position.y][position.x]->getIsMarked())
	{
		//change position for pressedPlayer
		Position oldPosition = game->pressedPlayer->getPosition();
		game->players[position.y][position.x] = game->players[oldPosition.y][oldPosition.x];
		game->players[oldPosition.y][oldPosition.x] = NULL;
		game->pressedPlayer->setPosition(position);
		game->currentState = new PlayerAState(game);
		delete this;
	}
	else
	{
		qDebug("You have to choose marked tile!");
	}
}

void MarkedAState::update()
{

}
