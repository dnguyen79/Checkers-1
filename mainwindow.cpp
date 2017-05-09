#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsGridLayout>

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
	//ui->graphicsView->setFixedHeight();
	//ui->graphicsView->setFixedSize(800,600); // how to scale?
	initScene();
	//ui->graphicsView->fitInView(scene->sceneRect() ,Qt::KeepAspectRatio);


	//connect(this->centralWidget()-);
	connect(ui->startButton,SIGNAL(clicked(bool)),this,SLOT(on_newgame_button_clicked()));
}

MainWindow::~MainWindow()
{
	delete ui;
	delete game;
}

void MainWindow::initScene()
{qDebug("asd");
	game = new Game(this);
	game->initTiles();
	game->initPlayers();
	ui->label->setText("Wynik A: 0");
	ui->label_2->setText("Wynik B: 0");

}

GuiTile *MainWindow::initGuiTile(int x, int y, bool isActive) //zwraca do coreTile wskaznik na guiTile
{
	GuiTile* result;

	int w = 800/*ui->graphicsView->width()*/ * 0.9 * 0.125;
	int h = 600/*ui->graphicsView->height()*/ * 0.9 * 0.125;
	int startX = 800/*ui->graphicsView->width()*/ * 0.05 + 0.5*w;
	int startY = 600/*ui->graphicsView->height()*/ * 0.05 + 0.5*h;

	result = new GuiTile(startX + w*x, startY + h*y,w,h,isActive, game);
	result->setPosition(x,y);
	scene->addItem(result);
	//guiTiles.push_back(result);

	return result;
}

GuiPlayer *MainWindow::initGuiPlayer(Position position, bool isPlayersA) //-||- do GuiPlayer
{
	GuiPlayer* result;

	result = new GuiPlayer(position, game, this);

	if(isPlayersA)result->setColor("red");
	else result->setColor("green");
	scene->addItem(result);
	//guiPlayers.push_back(result);

	return result;
}

void MainWindow::removePlayer(GuiPlayer *guiPlayer)
{
	qDebug() << "Removing gui Player!";
	guiPlayer->hide();
	scene->removeItem(guiPlayer);
	delete guiPlayer;
}

void MainWindow::clearScreen()
{
	scene->clear();
	//wyczysc core
}

RealPosition MainWindow::LogicalToReal(Position position)
{
	int w = 800/*ui->graphicsView->width()*/ * 0.9 * 0.125;
	int h = 600/*ui->graphicsView->height()*/ * 0.9 * 0.125;
	int startX = 800/*ui->graphicsView->width()*/ * 0.05 + 0.5*w;
	int startY = 600/*ui->graphicsView->height()*/ * 0.05 + 0.5*h;

	return RealPosition(
				startX + position.x*w,
				startY + position.y*h,
				w,
				h
				);
}

void MainWindow::SetAScore(int score)
{
	ui->label->setText("Wynik A: " + QString::number(score));
}

void MainWindow::SetBScore(int score)
{
	ui->label_2->setText("Wynik B: " + QString::number(score));
}

void MainWindow::resizeEvent(QResizeEvent *e)
{
	QRectF bounds = scene->itemsBoundingRect();
		//bounds.setWidth(bounds.width()*0.9);         // to tighten-up margins
		//bounds.setHeight(bounds.height()*0.9 + 1);       // same as above
		ui->graphicsView->fitInView(bounds, Qt::KeepAspectRatio);
		//ui->gameBoard->centerOn(0, 0);
}

void MainWindow::showEvent(QShowEvent *e)
{
	ui->graphicsView->fitInView(scene->itemsBoundingRect(),Qt::KeepAspectRatio);
}

void MainWindow::mousePressEvent(QMouseEvent *e)
{
	//scene->addEllipse(0,0,100,100);
	//scene->addEllipse(100,0,100,100);
}

void MainWindow::on_newgame_button_clicked()
{
	qDebug() << "new game!";
	delete game;
	scene->clear();
	initScene();
}
