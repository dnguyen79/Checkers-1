#ifndef GAME_H
#define GAME_H
#include "coreplayer.h"
#include "coretile.h"
#include "position.h"
#include "state.h"
#include <QList>
#include "playerastate.h"
#include "mainwindow.h"

class CoreTile;
class State;
class MainWindow;
class CorePlayer;

class Game
{
public:
	Game(MainWindow* mainWindow);
	void initTiles();
	void initPlayers();

	void playerWasPressed(Position position);
	void tileWasPressed(Position position);

	void addCoreTile(CoreTile * coreTile);
	void addCorePlayer(CorePlayer* corePlayer);
	MainWindow *getMainWindow() const;

	//CorePlayer* getPlayer

private:
	QList<CorePlayer* > players;
	int k;

	QList<QList<CoreTile*> > tiles;
	State* currentState;

	MainWindow* mainWindow;
};

#endif // GAME_H
