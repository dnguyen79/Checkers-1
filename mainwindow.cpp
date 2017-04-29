#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	scene = new QGraphicsScene(this);
	scene -> setSceneRect(0,0,800,600);

	ui->graphicsView->setScene(scene);
	ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	ui->graphicsView->setFixedSize(800,600); // how to scale?

	initScene();

}

MainWindow::~MainWindow()
{
	delete ui;
	delete game;
}

void MainWindow::initScene()
{qDebug("asd");
	game = new Game(this);
	game->init();

}

GuiTile *MainWindow::initGuiTile(int x, int y, bool isActive) //zwraca do coreTile wskaznik na guiTile
{
	GuiTile* result;

	int w = ui->graphicsView->width() * 0.9 * 0.125;
	int h = ui->graphicsView->height() * 0.9 * 0.125;
	int startX = ui->graphicsView->width() * 0.05 + 0.5*w;
	int startY = ui->graphicsView->height() * 0.05 + 0.5*h;

	result = new GuiTile(startX + w*x, startY + h*y,w,h,isActive, game);
	result->setPosition(x,y);
	scene->addItem(result);
	guiTiles.push_back(result);

	return result;
}

GuiPlayer *MainWindow::initGuiPlayer(Position position, bool isPlayersA) //-||- do GuiPlayer
{
	GuiPlayer* result;

	int w = ui->graphicsView->width() * 0.9 * 0.125;
	int h = ui->graphicsView->height() * 0.9 * 0.125;
	int startX = ui->graphicsView->width() * 0.05 + 0.5*w;
	int startY = ui->graphicsView->height() * 0.05 + 0.5*h;

	result = new GuiPlayer(startX + w*position.x, startY + h*position.y,w,h, game);
	result->setPosition(position.x, position.y);
	if(isPlayersA)result->setColor("red");
	else result->setColor("green");
	scene->addItem(result);
	guiPlayers.push_back(result);

	return result;
}
