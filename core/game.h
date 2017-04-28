#ifndef GAME_H
#define GAME_H
#include "coreplayer.h"
#include "coretile.h"

#include <QList>

class Game
{
public:
	Game();
	void init();

private:
	QList<CorePlayer* > players;
	QList<QList<CoreTile*> > tiles; // table 8x8 [x][y]

};

#endif // GAME_H
