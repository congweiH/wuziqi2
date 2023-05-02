#pragma once
#include <easyx.h>

struct Point {
	int x;
	int y;
};

class Chess
{
public:
	Chess(Point p, COLORREF color);

	void render();

private:
	Point p;
	COLORREF color;
};

