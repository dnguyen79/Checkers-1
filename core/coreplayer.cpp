#include "coreplayer.h"

CorePlayer::CorePlayer(int x, int y, GuiPlayer* guiPlayer)
{
	position.x = x;
	position.y = y;
	this->guiPlayer = guiPlayer;
}

Position CorePlayer::getPosition() const
{
	return position;
}

void CorePlayer::setPosition(const Position &value)
{
    position = value;
	//calling gui method:
	guiPlayer->setPosition(value);
}
