#include "playerbstate.h"

#include <QDebug>
PlayerBState::PlayerBState(Game *game)
	:State(game)
{
	init();
}

void PlayerBState::init()
{
	qDebug() << "PlayerBState";

	for(int i = 0; i < 8; ++i)
	{
		for(int k = 0 ; k < 8; ++k)
		{
			game->tiles[k][i]->setIsMarked(false);
		}
	}

	game->pressedPlayer = NULL;
}

void PlayerBState::playerWasPressed(Position position)
{
	int x = position.x;
	int y = position.y;

	if(game->players[y][x]->getIsPlayersA())
	{
		qDebug() << "It is not your turn!";
		return;
	}

	bool isMarked = game->tiles[y][x]->getIsMarked();
	game->pressedPlayer = game->players[position.y][position.x];

	game->tiles[y][x]->setIsMarked(!isMarked);

	//mark every neighbour
	for(int i = 0; i < game->tiles[y][x]->neighbours.length(); ++i)
	{
		game->tiles[y][x]->neighbours[i]->setIsMarked(!isMarked);
	}

	game->currentState = new MarkedBState(game);
	delete this;
}

void PlayerBState::tileWasPressed(Position position)
{

}

void PlayerBState::update()
{

}
