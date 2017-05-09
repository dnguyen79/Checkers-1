#include "game.h"

#include <QDebug>
Game::Game(MainWindow *mainWindow)
{
	this->mainWindow = mainWindow;
	//currentState = new PlayerAState(this);
	scoreA = scoreB = 0;
}

Game::~Game()
{
	for(unsigned int i = 0; i < tiles.length(); ++i)
	{
		for(unsigned int k = 0; k < tiles[i].length(); ++k)
		{
			delete tiles[i][k];
		}
	}

	for(unsigned int i = 0; i < players.length(); ++i)
	{
		for(unsigned int k = 0; k < players[i].length(); ++k)
		{
			if(players[i][k] != NULL)delete players[i][k];
		}
	}

	delete currentState;
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
						players[i][k] = currentCorePlayer;
					}
				}


			}
	}

	currentState = new PlayerAState(this);
}

void Game::playerWasPressed(Position position)
{
	currentState->playerWasPressed(position);

}

void Game::tileWasPressed(Position position)
{
	currentState->tileWasPressed(position);
}

MainWindow *Game::getMainWindow() const
{
	return mainWindow;
}

void Game::removePlayer(Position position)
{
	CorePlayer* player = players[position.y][position.x];
	mainWindow->removePlayer(player->getGuiPlayer());
	delete players[position.y][position.x];
	players[position.y][position.x] = NULL;
}
