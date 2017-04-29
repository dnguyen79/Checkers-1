#ifndef GAME_H
#define GAME_H
#include "coreplayer.h"
#include "coretile.h"
#include "position.h"

#include <QList>

class Game
{
public:
	Game();
	void init();

	void playerWasPressed(Position position);
	//void addCorePlayer(CorePlayer* corePlayer);
	void addCoreTile(CoreTile * coreTile);

private:
	QList<CorePlayer* > players;
	QList<QList<CoreTile*> > tiles; // table 8x8 [x][y]

};

#endif // GAME_H
