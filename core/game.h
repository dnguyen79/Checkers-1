#ifndef GAME_H
#define GAME_H
#include "coreplayer.h"
#include "coretile.h"
#include "position.h"
#include "state.h"
#include <QList>

class CoreTile;
class State;

class Game
{
public:
	Game();
	void init();

	void playerWasPressed(Position position);
	void tileWasPressed(Position position);

	void addCoreTile(CoreTile * coreTile);
	void addCorePlayer(CorePlayer* corePlayer);
private:
	QList<CorePlayer* > players;
	QList<QList<CoreTile*> > tiles; // table 8x8 [x][y]
	State* currentState;
};

#endif // GAME_H
