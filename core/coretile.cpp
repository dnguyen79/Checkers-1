#include "coretile.h"

CoreTile::CoreTile(bool isActive, int x, int y, GuiTile *guiTile)
{
	this->isActive = isActive;
	position.x = x;
	position.y = y;
	this->guiTile = guiTile;
	this->isMarked = false;
}

QList<CoreTile *> CoreTile::getNeighbours() const
{
	return neighbours;
}

void CoreTile::setNeighbours(const QList<CoreTile *> &value)
{
	neighbours = value;
}

bool CoreTile::getIsActive() const
{
	return isActive;
}

void CoreTile::setIsActive(bool value)
{
	isActive = value;
}

bool CoreTile::getIsMarked() const
{
	qDebug("chuj");
	return isMarked;
}

void CoreTile::setIsMarked(bool value)
{
	isMarked = value;
	if(value) markGuiTile();
	else unMarkGuiTile();
}

void CoreTile::markGuiTile()
{
	guiTile->mark();
}

void CoreTile::unMarkGuiTile()
{
	guiTile->unMark();
}

GuiTile *CoreTile::getGuiTile() const
{
	return guiTile;
}

void CoreTile::setGuiTile(GuiTile *value)
{
	guiTile = value;
}
