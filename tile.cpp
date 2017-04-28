#include "tile.h"

#include <QDebug>
Tile::Tile(int x, int y, int w, int h , bool isActiveField, QGraphicsItem* parent)
{
	setRect(x-0.5*w, y-0.5*h, w, h);
	this->activeField = isActiveField;
	init();
}

void Tile::setActiveField(bool activeField)
{
	this->activeField = activeField;
}

bool Tile::isActiveField()
{
	return activeField;
}

void Tile::setPlayer(Player *player)
{
	this->player = player;
}

Player *Tile::getPlayer()
{
	return player;
}

void Tile::init()
{
	if(isActiveField())
	{
		setColor(QColor(100,100,200,255));
	}
	else
	{
		setColor(QColor(50,50,100,255));
	}

	marked = false;
}

void Tile::setColor(QColor color)
{
	setBrush(QBrush(color));
}

void Tile::changeState()
{
	if(activeField)
	{
		if(marked)
		{
			qDebug() << "unmarked";
			marked = false;
		}
		else
		{
			qDebug() << "marked";
			marked = true;
		}
	}
}


void Tile::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
	qDebug() << "Attemt to mark Field!";
	if(isActiveField())
	{
		setColor(QColor(200,100,100,255));
	}
	else
	{
		qDebug("Cannot to mark this field!");
	}
}

void Tile::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
	//? cos tu trzeba?
}

