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

#include <QGraphicsSceneMouseEvent>

class GuiTile;
class GuiPlayer;

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
	GuiTile* initGuiTile(Position position, bool isActive);

private:
	Ui::MainWindow *ui;

	void initBoard();
	void initPlayers();



	QList<GuiTile*> guiTiles;
	QList<GuiPlayer*> guiPlayers;
	Game* game;
};

#endif // MAINWINDOW_H
