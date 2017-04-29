#include "guiplayer.h"

#include "QDebug"
GuiPlayer::GuiPlayer(int x, int y, int w, int h, Game *parent)
{
	setRect(x-0.5*w, y-0.5*h, w, h);
	this->game = parent;
}

Position GuiPlayer::getPosition() const
{
	return position;
}

void GuiPlayer::setPosition(int x, int y)
{
	position.x = x;
	position.y = y;
}

QColor GuiPlayer::getColor() const
{
	return color;
}

void GuiPlayer::setColor(const QColor &value)
{
	color = value;
	updateColor();
}

void GuiPlayer::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
	if(position.x == 0 && position.y ==0) qDebug() <<"!!!!!!!!!!!!!!!!!!!!";
	game->playerWasPressed(position);
}

void GuiPlayer::updateColor()
{
	setBrush(QBrush(color));
}
