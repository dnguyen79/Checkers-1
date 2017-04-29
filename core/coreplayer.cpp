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
