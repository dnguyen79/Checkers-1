#include "markedbstate.h"
#include <QtMath>

#include <QDebug>
MarkedBState::MarkedBState(Game *game)
	:State(game)
{
	init();
}

void MarkedBState::init()
{
	qDebug() << "MarkedBState!";
}

void MarkedBState::playerWasPressed(Position position)
{
	qDebug() << "Choose your move!";
	if(game->pressedPlayer->getPosition().x == position.x && game->pressedPlayer->getPosition().y == position.y)
	{
		game->currentState = new PlayerBState(game);
		delete this;
	}
}

void MarkedBState::tileWasPressed(Position position)
{
	if(game->tiles[position.y][position.x]->getIsMarked())
	{
		//change position for pressedPlayer
		Position oldPosition = game->pressedPlayer->getPosition();
		game->players[position.y][position.x] = game->players[oldPosition.y][oldPosition.x];
		game->players[oldPosition.y][oldPosition.x] = NULL;
		game->pressedPlayer->setPosition(position);

		int dx = position.x - oldPosition.x;
		int dy = position.y - oldPosition.y;

		if(qFabs(dx) > 1 && qFabs(dy) > 1)
		{
			qDebug() << "killing Player";
			game->removePlayer(Position(oldPosition.x + dx/2, oldPosition.y + dy/2));
			if(++game->scoreB >= 12)
			{
				game->currentState = new EndState(game);// B state
				delete this;
				return;
			}
		}
		game->currentState = new PlayerAState(game);// A state
		delete this;
	}
	else
	{
		qDebug("You have to choose marked tile!");
	}

}

void MarkedBState::update()
{

}
