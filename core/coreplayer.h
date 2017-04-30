#ifndef COREPLAYER_H
#define COREPLAYER_H
#include "position.h"
#include "../gui/guiplayer.h"

class GuiPlayer;

class CorePlayer
{
public:
	CorePlayer(int x, int y, GuiPlayer *guiPlayer, bool isPlayersA);

	Position getPosition() const;
	void setPosition(const Position &value);

	bool getIsPlayersA() const;

	GuiPlayer *getGuiPlayer() const;

private:
	bool isPlayersA;
	Position position;

	GuiPlayer* guiPlayer;
};

#endif // COREPLAYER_H
