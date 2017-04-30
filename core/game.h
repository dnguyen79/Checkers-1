#ifndef GAME_H
#define GAME_H
#include "coreplayer.h"
#include "coretile.h"
#include "position.h"
#include "state.h"
#include <QList>
#include "playerastate.h"
#include "markedastate.h"
#include "playerbstate.h"
#include "markedbstate.h"
#include "mainwindow.h"

class CoreTile;
class State;
class MainWindow;
class CorePlayer;

class Game
{
	friend class PlayerAState;
	friend class MarkedAState;
	friend class PlayerBState;
	friend class MarkedBState;

public:
	Game(MainWindow* mainWindow);
	void initTiles();
	void initPlayers();

	void playerWasPressed(Position position);
	void tileWasPressed(Position position);

	void addCoreTile(CoreTile * coreTile);
	void addCorePlayer(CorePlayer* corePlayer);
	MainWindow *getMainWindow() const;


private:
	QList<QList<CorePlayer *>> players;
	CorePlayer* pressedPlayer;
	QList<QList<CoreTile*> > tiles;
	State* currentState;

	MainWindow* mainWindow;
};

#endif // GAME_H
