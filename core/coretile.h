#ifndef CORETILE_H
#define CORETILE_H
#include "coreplayer.h"
#include <QList>
#include "position.h"
#include "../gui/guitile.h"

//MemoryLicki!!! jezeli nie zrobisz klasy Qt!
class CoreTile
{
public:
	CoreTile(bool isActive, int x, int y, GuiTile* guiTile = NULL);

	QList<CoreTile *> getNeighbours() const;
	void setNeighbours(const QList<CoreTile *> &value);

	bool getIsActive() const;
	void setIsActive(bool value);

	bool getIsMarked() const;
	void setIsMarked(bool value);

	GuiTile *getGuiTile() const;
	void setGuiTile(GuiTile *value);

	Position position;

private:
	void markGuiTile();
	void unMarkGuiTile();

	bool isActive; // remember that you cannot inherite from GraphicsItem!
	bool isMarked;
	GuiTile* guiTile;
	QList<CoreTile*> neighbours;
	};

#endif // CORETILE_H
