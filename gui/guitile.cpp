#include "guitile.h"

#include <QDebug>
GuiTile::GuiTile(int x, int y, int w, int h , bool isActiveField, Game *game)
{
	setRect(x-0.5*w, y-0.5*h, w, h);
	this->activeField = isActiveField;
	init();
}

bool GuiTile::isActiveField()
{
	return activeField;
}

void GuiTile::mark()
{
	setBrush(QBrush(markedColor));
}

void GuiTile::unMark()
{
	setBrush(standardColor);
}


void GuiTile::init()
{
	if(isActiveField())
	{
		standardColor = QColor(150,75,0,255);
	}
	else
	{
		standardColor = QColor(200,150,50,255);
	}

	markedColor = QColor(40,40,200, 255);

	setBrush(QBrush(standardColor));

	marked = false;
}

Position GuiTile::getPosition() const
{
	return position;
}

void GuiTile::setPosition(const int x, const int y)
{
	position.x = x;
	position.y = y;
}

void GuiTile::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
	game->tileWasPressed(position);
}
