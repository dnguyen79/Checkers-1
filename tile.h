#ifndef TILE_H
#define TILE_H

#include <QGraphicsItem>
#include "player.h"
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

class Tile : public QObject, public QGraphicsRectItem
{
public:
	Tile(int x, int y, int w, int h , bool isActiveField, QGraphicsItem* parent = NULL);
	void setActiveField(bool activeField);
	bool isActiveField();
	void setPlayer(Player* player);
	Player* getPlayer();

protected:
	//chyba jakis slot dla sygnalu generowanego dla playera ktory na nim stoi
	void mousePressEvent(QGraphicsSceneMouseEvent* event);
	void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

private:
	//pointer to the player or null if there is no players on the tile
	Player * player;
	bool activeField;
	bool marked;
	void init();

	void setColor(QColor color);

public slots:
	void changeState(); // marked or unmarked


};

#endif // TILE_H
