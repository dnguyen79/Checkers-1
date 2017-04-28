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
	ui->graphicsView->setFixedSize(800,600); // jak to skalowac?

	rect = new Tile(100,100, 40, 40, false);

	//rect->init();
	rect->setPos(scene->width()/2,scene->height()/2);

	//boardGame = new BoardGame();
	//scene->addItem(boardGame);
	scene->addItem(rect);



}

MainWindow::~MainWindow()
{
	delete ui;
}
