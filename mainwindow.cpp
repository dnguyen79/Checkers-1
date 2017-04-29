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
//	delete coreTile;
//	delete guiTile;
	delete game;
}

void MainWindow::initScene()
{
	initBoard();
}

void MainWindow::initBoard()
{
	game = new Game();

	int w = ui->graphicsView->width() * 0.9 * 0.125;
	int h = ui->graphicsView->height() * 0.9 * 0.125;
	int startX = ui->graphicsView->width() * 0.05 + 0.5*w;
	int startY = ui->graphicsView->height() * 0.05 + 0.5*h;

	for(unsigned int i = 0 ; i < 8; ++i)
	{
		for(unsigned int k = 0; k < 8; ++k)
		{
			bool isActive;

			if((i+k)%2) isActive = true;
			else isActive = false;
			CoreTile* coreTile = new CoreTile(isActive, i,k);
			GuiTile* guiTile = new GuiTile(startX + w*k, startY + h*i,w,h,isActive);
			coreTile->setGuiTile(guiTile);
			game->addCoreTile(coreTile);

			scene->addItem(guiTile);
		}
	}
}

void MainWindow::initPlayers()
{
	//todo
}
