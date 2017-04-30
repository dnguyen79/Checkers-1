#ifndef CORETILE_H
#define CORETILE_H
#include "coreplayer.h"
#include <QList>
#include "position.h"
#include "../gui/guitile.h"

class GuiTile;

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
	void removeGuiTile();

	Position position;
	QList<CoreTile*> neighbours;

private:
	void markGuiTile();
	void unMarkGuiTile();

	bool isActive; // remember that you cannot inherite from GraphicsItem!
	bool isMarked;
	GuiTile* guiTile;

	};

#endif // CORETILE_H
