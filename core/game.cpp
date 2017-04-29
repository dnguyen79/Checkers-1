#include "game.h"

#include <QDebug>
Game::Game(MainWindow *mainWindow)
{
	this->mainWindow = mainWindow;
	//init();
	currentState = new PlayerAState(this);
}

void Game::init()
{//dodaj pozniej w tym miejscu dodawanie sasiadow!

	/*
	for(unsigned int i=0 ; i < 8; ++i)
	{
		QList<CoreTile* > temporaryCoreTileList;
		for(unsigned int k = 0; k < 8; ++k)
		{
			temporaryCoreTileList.push_back(NULL);
		}
		tiles.push_back(temporaryCoreTileList);
	}

	*/
	for(unsigned int i=0 ; i < 8; ++i)
	{
		QList<CoreTile* > temporaryCoreTileList;
		for(unsigned int k = 0; k < 8; ++k)
		{
			bool isActive;
			if(!((k+i)%2)) isActive = true;
			else isActive = false;

			GuiTile* currentGuiTile = mainWindow->initGuiTile(k,i,isActive);

			if(currentGuiTile == NULL) qDebug("PROBLEM!");
			CoreTile* currentCoreTile = new CoreTile(isActive,k,i,currentGuiTile);
			temporaryCoreTileList.push_back(currentCoreTile);
			//tiles[k][i] = new CoreTile(isActive,k,i,currentGuiTile);
			//tiles[k][i]->setIsMarked(true);
		}
		tiles.push_back(temporaryCoreTileList);
	}


	for(unsigned int i = 0 ; i < 8; ++i)
	{
		if(i!=3 && i!=4)
		{
			for(unsigned int k = 0; k < 8; ++k)
			{
				if((i+k)%2 == 0)
				{
					bool isPlayersA;
					if(i < 4) isPlayersA = true;
					else isPlayersA = false;
					CorePlayer* currentCorePlayer = new CorePlayer(k,i,mainWindow->initGuiPlayer(Position(k,i), isPlayersA));
					players.push_back(currentCorePlayer);
					//addCorePlayer(new CorePlayer(k,i,mainWindow->initGuiPlayer(Position(k,i), isPlayersA)));
				}

			}
		}
	}
//	pla = new CorePlayer(0,0,mainWindow->initGuiPlayer(Position(0,0), true));
	//qDebug("asssd");


	//players

	/*
	for(unsigned int i=0 ; i < 8; ++i)
	{
		QList<CoreTile* > temporaryCoreTileList;
		for(unsigned int k = 0; k < 8; ++k)
		{
			temporaryCoreTileList.push_back(NULL);
		}
		tiles.push_back(temporaryCoreTileList);
	}

	*/

}

void Game::playerWasPressed(Position position)
{
	int x = position.x;
	int y = position.y;


	if(tiles[y][x]->getIsMarked())
	{
		tiles[y][x]->setIsMarked(false);
	}
	else
	{
		tiles[y][x]->setIsMarked(true);
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
