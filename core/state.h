#ifndef STATE_H
#define STATE_H
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QObject>
#include <QMainWindow>


class State : public QObject
{
	Q_OBJECT
public:
	State();

signals: // sygnal wysylany do view
void signalOn();

public slots:
void testSlot();

};

#endif // STATE_H
