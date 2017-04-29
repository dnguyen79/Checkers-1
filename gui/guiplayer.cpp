#include "guiplayer.h"

#include "QDebug"
GuiPlayer::GuiPlayer(int x, int y, int w, int h, QGraphicsItem *parent)
{
	setRect(x-0.5*w, y-0.5*h, w, h);
}

Position GuiPlayer::getPosition() const
{
	return position;
}

void GuiPlayer::setPosition(const Position &value)
{
	position = value;
}

QColor GuiPlayer::getColor() const
{
	return color;
}

void GuiPlayer::setColor(const QColor &value)
{
	color = value;
}

void GuiPlayer::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
	qDebug() << "Player was pressed!";
	//todo: calling game method that this player was pressed.
}
