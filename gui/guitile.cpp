#include "guitile.h"

#include <QDebug>
GuiTile::GuiTile(int x, int y, int w, int h , bool isActiveField, QGraphicsItem* parent)
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
		standardColor = QColor(100,100,200,255);
	}
	else
	{
		standardColor = QColor(50,50,100,255);
	}

	markedColor = QColor(200,200,40, 255);

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
