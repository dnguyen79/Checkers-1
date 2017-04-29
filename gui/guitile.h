#ifndef GUI_TILE_H
#define GUI_TILE_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent> //Do we need this?
#include "../core/position.h"
#include "../core/game.h"

class Game;

class GuiTile : public QObject, public QGraphicsRectItem
{
	Q_OBJECT
public:
	GuiTile(int x, int y, int w, int h , bool isActiveField, Game* game);

	bool isActiveField();
	void mark();
	void unMark();

	Position getPosition() const;
	void setPosition(const int x, const int y);

protected:
	void mousePressEvent(QGraphicsSceneMouseEvent *event);

private:
	//moze pozniej trzeba dodac jakies metody do zmiany kolorow? w trakcie gry
	QColor standardColor;
	QColor markedColor;
	void init();

	bool activeField; // czy tych 2 potrzebujemy?
	bool marked;
	Position position; //logical coordinates

	Game* game;
};

#endif // GUI_TILE_H

