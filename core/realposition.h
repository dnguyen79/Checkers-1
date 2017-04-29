#ifndef REALPOSITION_H
#define REALPOSITION_H


struct RealPosition
{
	int x;
	int y;
	int w;
	int h;

	RealPosition(int x, int y, int w, int h)
	{
		this->x = x;
		this->y = y;
		this->w = w;
		this->h = h;
	}
};

#endif // REALPOSITION_H
