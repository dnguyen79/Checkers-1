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
{
	game = new Game();
	initBoard();
	initPlayers();
}

void MainWindow::initBoard()
{
	int w = ui->graphicsView->width() * 0.9 * 0.125;
	int h = ui->graphicsView->height() * 0.9 * 0.125;
	int startX = ui->graphicsView->width() * 0.05 + 0.5*w;
	int startY = ui->graphicsView->height() * 0.05 + 0.5*h;

	for(unsigned int i = 0 ; i < 8; ++i)
	{
		for(unsigned int k = 0; k < 8; ++k)
		{
			bool isActive;

			if((i+k)%2 == 0) isActive = true;
			else isActive = false;
			CoreTile* coreTile = new CoreTile(isActive, i,k);
			GuiTile* guiTile = new GuiTile(startX + w*k, startY + h*i,w,h,isActive, game);
			coreTile->setGuiTile(guiTile);
			game->addCoreTile(coreTile);

			scene->addItem(guiTile);

			guiTiles.push_back(guiTile);
		}
	}
}

void MainWindow::initPlayers()
{
	int w = ui->graphicsView->width() * 0.9 * 0.125;
	int h = ui->graphicsView->height() * 0.9 * 0.125;
	int startX = ui->graphicsView->width() * 0.05 + 0.5*w;
	int startY = ui->graphicsView->height() * 0.05 + 0.5*h;

	for(unsigned int i = 0 ; i < 8; ++i)
	{
		if(i!=3 && i!=4)
		{
			for(unsigned int k = 0; k < 8; ++k)
			{
				if((i+k)%2 == 0)
				{
					GuiPlayer* guiPlayer = new GuiPlayer(startX + w*k, startY + h*i,w,h, game);
					guiPlayer->setPosition(i,k);
					if(i<4) guiPlayer->setColor(QColor("red"));
					else guiPlayer->setColor(QColor("green"));
					scene->addItem(guiPlayer);

					game->addCorePlayer(new CorePlayer(i,k));

					guiPlayers.push_back(guiPlayer);
				}
			}
		}
	}
}
