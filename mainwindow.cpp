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

	coreTile = new CoreTile(true, 0,0);
	guiTile = new GuiTile(100,100,50,50,true);
	coreTile->setGuiTile(guiTile);

	scene->addItem(guiTile);
	coreTile->setIsMarked(true);
	coreTile->setIsMarked(false);
}

MainWindow::~MainWindow()
{
	delete ui;
}
