#include "Chess.h"

Chess::Chess(Point p, COLORREF color): p(p), color(color) { }

void Chess::render() {
	// 绘制棋子
	setfillcolor(color);
	setlinestyle(PS_SOLID, 1);
	fillcircle(p.x, p.y, 13);
}