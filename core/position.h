#ifndef POSITION_H
#define POSITION_H

//positions on board 0-7 in each dimension
struct Position
{
	int x;
	int y;

	Position()
	{

	}

	Position(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
};

#endif // POSITION_H
