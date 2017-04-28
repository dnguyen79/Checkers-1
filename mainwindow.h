#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include "tile.h"
#include "boardgame.h"

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

	Tile* rect;
	BoardGame* boardGame;

};

#endif // MAINWINDOW_H
