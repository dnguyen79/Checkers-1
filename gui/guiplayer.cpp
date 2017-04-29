#include "guiplayer.h"

#include "QDebug"
GuiPlayer::GuiPlayer(Position position, Game *parent, MainWindow* mainWindow)
{
	this->game = parent;
	this->position = position;
	RealPosition realPosition = mainWindow->LogicalToReal(position);
	setRect(realPosition.x - 0.5*realPosition.w, realPosition.y-0.5*realPosition.h, realPosition.w, realPosition.h);
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
	game->playerWasPressed(position);
}

void GuiPlayer::updateColor()
{
	setBrush(QBrush(color));
}
