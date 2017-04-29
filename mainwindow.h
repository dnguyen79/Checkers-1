#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include "gui/guitile.h"
#include "core/coretile.h"
#include "gui/guiplayer.h"
#include "core/game.h"

#include <QGraphicsSceneMouseEvent>
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


private:
	Ui::MainWindow *ui;

	GuiTile* guiTile;
	CoreTile* coreTile;
	GuiPlayer* guiPlayer;
	Game* game;
};

#endif // MAINWINDOW_H
