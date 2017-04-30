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

	for(int i = 0; i < 8; ++i)
	{
		for(int k = 0 ; k < 8; ++k)
		{
			game->tiles[k][i]->setIsMarked(false);
		}
	}

	game->pressedPlayer = NULL;
}

void PlayerAState::playerWasPressed(Position position)
{
	//nie mozna sie ruszyc do tylu
	//nie mozna sie ruszyc tam gdzie jest pionek

	//jezeli jest pionek nasz, to nie rozpatrujemy cos jest dalej
	//jezeli pionek jest przeciwnika, to sprawdzamy czy za nim jest puste pole,
	//wtedy bedzie wymuszane bicie.

	// jezeli postawimy 2 playery na 1 polu to sie jebie, ale to normalne wiec trzeba zapobiec
	int x = position.x;
	int y = position.y;

	if(!game->players[y][x]->getIsPlayersA())
	{
		qDebug() << "It is not your turn!";
		return;
	}

	bool isMarked = game->tiles[y][x]->getIsMarked();
	game->pressedPlayer = game->players[position.y][position.x];

	//game->tiles[y][x]->setIsMarked(!isMarked);

	//mark every neighbour
	for(int i = 0; i < game->tiles[y][x]->neighbours.length(); ++i)
	{
		CoreTile* neighbour = game->tiles[y][x]->neighbours[i];//->setIsMarked(!isMarked);
		if(neighbour->position.y < y)
		{
			int dx = neighbour->position.x - x;
			int dy = neighbour->position.y - y;

			if(neighbour->position.x + dx < 0 ||neighbour->position.x + dx > 7
					||neighbour->position.y + dy > 7  || neighbour->position.y +dy < 0)
			{

			}
			else
			{
				if(game->players[neighbour->position.y + dy][neighbour->position.x + dx] == NULL)
				{
					game->tiles[neighbour->position.y + dy][neighbour->position.x + dx]->setIsMarked(true);
				}
			}

		}
		else
		{
			neighbour->setIsMarked(true);
		}
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
