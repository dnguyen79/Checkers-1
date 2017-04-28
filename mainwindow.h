#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include "boardgame.h"
#include "gui/guitile.h"
#include "core/coretile.h"

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
};

#endif // MAINWINDOW_H
