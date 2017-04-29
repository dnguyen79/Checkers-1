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

void PlayerAState::playerWasPressed(Position position)
{
	int x = position.x;
	int y = position.y;

	if(!game->players[y][x]->getIsPlayersA())
	{
		qDebug() << "It is not your turn!";
		return;
	}

	bool isMarked = game->tiles[y][x]->getIsMarked();

	game->tiles[y][x]->setIsMarked(!isMarked);
	//mark every neighbour
	for(int i = 0; i < game->tiles[y][x]->neighbours.length(); ++i)
	{
		game->tiles[y][x]->neighbours[i]->setIsMarked(!isMarked);
	}

	game->currentState = new MarkedAState(game);
	delete this;
}

void PlayerAState::tileWasPressed(Position position)
{
	qDebug() << "First clicked on your player!";
}

void PlayerAState::update()
{

}
