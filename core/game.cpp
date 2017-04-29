#include "game.h"

#include <QDebug>
Game::Game(MainWindow *mainWindow)
{
	this->mainWindow = mainWindow;
	//init();
	currentState = new PlayerAState(this);
}

void Game::initTiles()
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
	//neighbours

	for(unsigned int i=0 ; i < 8; ++i)
	{
		for(unsigned int k = 0; k < 8; ++k)
		{
			if(tiles[k][i]->getIsActive())
			{
				if(i == 0)
				{
					if(k == 0) tiles[k][i]->neighbours.push_back(tiles[k+1][i+1]);
					else if(k!=0 && k!=7)
					{
						tiles[k][i]->neighbours.push_back(tiles[k+1][i+1]);
						tiles[k][i]->neighbours.push_back(tiles[k-1][i+1]);
					}
					else if(k == 7) tiles[k][i]->neighbours.push_back(tiles[k-1][i+1]);
				}
				else if(i!=0 && i!=7)
				{
					if(k == 0)
					{
						tiles[k][i]->neighbours.push_back(tiles[k+1][i+1]);
						tiles[k][i]->neighbours.push_back(tiles[k+1][i-1]);
					}
					else if(k!=0 && k!=7)
					{
						tiles[k][i]->neighbours.push_back(tiles[k-1][i-1]);
						tiles[k][i]->neighbours.push_back(tiles[k+1][i-1]);
						tiles[k][i]->neighbours.push_back(tiles[k+1][i+1]);
						tiles[k][i]->neighbours.push_back(tiles[k-1][i+1]);
					}
					else if(k == 7)
					{
						tiles[k][i]->neighbours.push_back(tiles[k-1][i+1]);
						tiles[k][i]->neighbours.push_back(tiles[k-1][i-1]);
					}
				}
				else if(i == 7)
				{
					if(k == 0) tiles[k][i]->neighbours.push_back(tiles[k+1][i-1]);
					else if(k!=0 && k!=7)
					{
						tiles[k][i]->neighbours.push_back(tiles[k+1][i-1]);
						tiles[k][i]->neighbours.push_back(tiles[k-1][i-1]);
					}
					else if(k == 7) tiles[k][i]->neighbours.push_back(tiles[k-1][i-1]);
				}
			}
		}
	}

}

void Game::initPlayers()
{
	for(unsigned int i = 0 ; i < 8; ++i)
	{
		QList<CorePlayer*> currentListCorePlayer;
		for(unsigned int k = 0; k < 8; ++k)
		{
			currentListCorePlayer.push_back(NULL);
		}
		players.push_back(currentListCorePlayer);
	}

	for(unsigned int i = 0 ; i < 8; ++i)
	{
		//if(i!=3 && i!=4)
		//{
			QList<CorePlayer*> currentListCorePlayer;
			for(unsigned int k = 0; k < 8; ++k)
			{
				if(i!=3 && i!=4)
				{
					if((i+k)%2 == 0)
					{
						bool isPlayersA;
						if(i < 4) isPlayersA = true;
						else isPlayersA = false;
						GuiPlayer* currentGuiPlayer = mainWindow->initGuiPlayer(Position(k,i), isPlayersA);
						CorePlayer* currentCorePlayer = new CorePlayer(k,i,currentGuiPlayer, isPlayersA);
						//players[k][i] = currentCorePlayer;
						players[i][k] = currentCorePlayer;
						//players.push_back(currentCorePlayer);
					}
				}


			}
	}
}

void Game::playerWasPressed(Position position)
{
	currentState->playerWasPressed(position);

	/*
	int x = position.x;
	int y = position.y;

	if(!players[y][x]->getIsPlayersA())
	{
		qDebug() << "It is not your turn!";
		return;
	}

	bool isMarked = tiles[y][x]->getIsMarked();

	tiles[y][x]->setIsMarked(!isMarked);
	//mark every neighbour
	for(int i = 0; i < tiles[y][x]->neighbours.length(); ++i)
	{
		tiles[y][x]->neighbours[i]->setIsMarked(!isMarked);
	}
	*/

}

void Game::tileWasPressed(Position position)
{
	currentState->tileWasPressed(position);
	//qDebug() << "tile was pressed!";
	//players[0][0]->setPosition(position);
}

void Game::addCoreTile(CoreTile *coreTile)
{
	tiles[coreTile->position.x][coreTile->position.y] = coreTile;
}

void Game::addCorePlayer(CorePlayer *corePlayer)
{
//	players.push_back(corePlayer);
}

MainWindow *Game::getMainWindow() const
{
	return mainWindow;
}
