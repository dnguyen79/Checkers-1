#ifndef GUIPLAYER_H
#define GUIPLAYER_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include "../core/position.h"
#include "../core/realposition.h"
#include "../core/game.h"

class Game;
class MainWindow;

class GuiPlayer : public QObject, public QGraphicsEllipseItem
{
public:
	GuiPlayer(/*int x, int y, int w, int h */Position position,Game* game, MainWindow *mainWindow);

	Position getPosition() const;
	void setPosition(int x, int y);

	QColor getColor() const;
	void setColor(const QColor &value);

protected:
	void mousePressEvent(QGraphicsSceneMouseEvent *event);

private:
	QColor color;
	Position position; //this is also an id

	void updateColor();

	Game* game;
};

#endif // GUIPLAYER_H
