#ifndef COREPLAYER_H
#define COREPLAYER_H
#include "position.h"

class CorePlayer
{
public:
	CorePlayer(int x, int y);

	//changing positions itd

	Position getPosition() const;

private:
	bool isPlayersA;
	Position position;
};

#endif // COREPLAYER_H
