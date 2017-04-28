#include "state.h"

#include <QDebug>
State::State()
{

}

void State::testSlot()
{
	qDebug() << "testSlot";
}
