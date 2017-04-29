#include "game.h"

#include <QDebug>
Game::Game()
{
	init();
}

void Game::init()
{
	for(unsigned int i=0 ; i < 8; ++i)
	{
		QList<CoreTile* > temporaryCoreTileList;
		for(unsigned int k = 0; k < 8; ++k)
		{
			temporaryCoreTileList.push_back(NULL);
		}
		tiles.push_back(temporaryCoreTileList);
	}
}

void Game::playerWasPressed(Position position)
{
	//only for debug
	int x = position.x;
	int y = position.y;

	if(tiles[x][y]->getIsMarked())
	{
		qDebug() << "Was marked!";
		tiles[x][y]->setIsMarked(false);
	}
	else
	{
		tiles[x][y]->setIsMarked(true);
	}
}

void Game::tileWasPressed(Position position)
{
	qDebug() << "tile was pressed!";
}

void Game::addCoreTile(CoreTile *coreTile)
{
	tiles[coreTile->position.x][coreTile->position.y] = coreTile;
}

void Game::addCorePlayer(CorePlayer *corePlayer)
{
	players.push_back(corePlayer);
}
