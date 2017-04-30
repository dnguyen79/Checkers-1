#include "coreplayer.h"

CorePlayer::CorePlayer(int x, int y, GuiPlayer* guiPlayer, bool isPlayersA)
{
	position.x = x;
	position.y = y;
	this->guiPlayer = guiPlayer;
	this->isPlayersA = isPlayersA;
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

bool CorePlayer::getIsPlayersA() const
{
	return isPlayersA;
}

GuiPlayer *CorePlayer::getGuiPlayer() const
{
	return guiPlayer;
}
