#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

class Player
{
public:
	Player();

protected:
	//chyba jakis slot dla sygnalu generowanego dla playera ktory na nim stoi
	void mousePressEvent(QGraphicsSceneMouseEvent* event);
	void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

signals:
	void markTiles();

};

#endif // PLAYER_H
