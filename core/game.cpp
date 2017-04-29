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

	for(unsigned int i=0 ; i < 8; ++i)
	{
		QList<CoreTile* > temporaryCoreTileList;
		for(unsigned int k = 0; k < 8; ++k)
		{
			bool isActive;
			if(!((k+i)%2)) isActive = true;
			else isActive = false;

			GuiTile* currentGuiTile = mainWindow->initGuiTile(k,i,isActive);

			CoreTile* currentCoreTile = new CoreTile(isActive,k,i,currentGuiTile);
			temporaryCoreTileList.push_back(currentCoreTile);

		}
		tiles.push_back(temporaryCoreTileList);
	}
/*

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
					GuiPlayer* currentGuiPlayer = mainWindow->initGuiPlayer(Position(k,i), isPlayersA);
					CorePlayer* currentCorePlayer = new CorePlayer(k,i,currentGuiPlayer);
					players.push_back(currentCorePlayer);
				}

			}
		}
	}
	//players[0]->setPosition(Position(5,5));

*/
}

void Game::initPlayers()
{
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
					GuiPlayer* currentGuiPlayer = mainWindow->initGuiPlayer(Position(k,i), isPlayersA);
					CorePlayer* currentCorePlayer = new CorePlayer(k,i,currentGuiPlayer);
					players.push_back(currentCorePlayer);
				}

			}
		}
	}
}

void Game::playerWasPressed(Position position)
{
	int x = position.x;
	int y = position.y;
	k =10;

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
	players[0]->setPosition(position);
	//k = 100;
}

void Game::addCoreTile(CoreTile *coreTile)
{
	tiles[coreTile->position.x][coreTile->position.y] = coreTile;
}

void Game::addCorePlayer(CorePlayer *corePlayer)
{
	players.push_back(corePlayer);
}

MainWindow *Game::getMainWindow() const
{
	return mainWindow;
}
