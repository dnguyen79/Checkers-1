#include "coreplayer.h"

CorePlayer::CorePlayer(int x, int y)
{
	position.x = x;
	position.y = y;
}

Position CorePlayer::getPosition() const
{
	return position;
}
