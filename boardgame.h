#ifndef BOARDGAME_H
#define BOARDGAME_H
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QList>
#include "tile.h"

class BoardGame : public QGraphicsRectItem
{
public:
	BoardGame();
	void init();

private:
	QList<Tile*> tiles;

};

#endif // BOARDGAME_H
