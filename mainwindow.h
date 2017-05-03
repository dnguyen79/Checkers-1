#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include "gui/guitile.h"
#include "core/coretile.h"
#include "gui/guiplayer.h"
#include "core/game.h"
#include <QList>
#include "core/realposition.h"
#include <QGraphicsSceneMouseEvent>

class GuiTile;
class GuiPlayer;
//class CorePlayer;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();
	QGraphicsScene * scene;

	void initScene();
	GuiTile* initGuiTile(int x, int y, bool isActive);
	GuiPlayer *initGuiPlayer(Position position, bool isPlayersA);
	void removePlayer(GuiPlayer* guiPlayer);
	void clearScreen();

	RealPosition LogicalToReal(Position position);

protected:
	void resizeEvent(QResizeEvent* e);
	void showEvent(QShowEvent* e);
	void mousePressEvent(QMouseEvent* e);


private:
	Ui::MainWindow *ui;

	QList<GuiTile*> guiTiles;
	QList<GuiPlayer*> guiPlayers;
	Game* game;
};

#endif // MAINWINDOW_H
