#include "mainwindow.h"
#include "ui_mainwindow.h"

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

	game = new Game();

	coreTile = new CoreTile(true, 0,0);
	guiTile = new GuiTile(100,100,50,50,true);
	guiPlayer = new GuiPlayer(100,100,50,50,game);
	guiPlayer->setColor(QColor(100,100,20,255));
	guiPlayer->setPosition(0,0);
	coreTile->setGuiTile(guiTile);
	game->addCoreTile(coreTile);

	scene->addItem(guiTile);
	scene->addItem(guiPlayer);
	//coreTile->setIsMarked(true);
	//coreTile->setIsMarked(false);


}

MainWindow::~MainWindow()
{
	delete ui;
	delete coreTile;
	delete guiTile;
}
