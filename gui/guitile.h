#ifndef GUI_TILE_H
#define GUI_TILE_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent> //Do we need this?
#include "../core/position.h"

class GuiTile : public QObject, public QGraphicsRectItem
{
	Q_OBJECT
public:
	GuiTile(int x, int y, int w, int h , bool isActiveField, QGraphicsItem* parent = NULL);

	bool isActiveField();
	void mark();
	void unMark();

	Position getPosition() const;
	void setPosition(const int x, const int y);

private:
	//moze pozniej trzeba dodac jakies metody do zmiany kolorow? w trakcie gry
	QColor standardColor;
	QColor markedColor;
	void init();

	bool activeField; // czy tych 2 potrzebujemy?
	bool marked;
	Position position; //logical coordinates
};

#endif // GUI_TILE_H

