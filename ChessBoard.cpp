#include "ChessBoard.h"

ChessBoard::ChessBoard() {
	
}

bool ChessBoard::canPut(ExMessage mouse) {
	return true;
}

void ChessBoard::putChess(Point p, COLORREF color) {
	Chess* chess = new Chess(p, color);
	chessList.push_back(chess);
}

void ChessBoard::render() {
	// 填充棋盘背景色
	int a = CHESS_SIZE * (CHESS_NUM + 2);	// 总的棋盘的边长大小
	setfillcolor(BG_COLOR);
	solidrectangle(TOP_LEFT.x, TOP_LEFT.y, TOP_LEFT.x + a, TOP_LEFT.y + a);

	// 绘制 x 坐标和 y 坐标, 下面的2和8是调整不断尝试得来的数字
	settextcolor(BLACK);
	for (int i = 0; i < xStr.size(); i++) {
		outtextxy(TOP_LEFT.x + i * CHESS_SIZE - 8, TOP_LEFT.y + 2, xStr[i]);
		outtextxy(TOP_LEFT.x + 2, TOP_LEFT.y + i * CHESS_SIZE - 8, yStr[i]);
	}

	// -----------------------     绘制棋盘线条    -------------------------
	setlinecolor(BLACK);
	for (int i = 0; i < 13; i++) {
		if (i == 0 || i == 12) {
			setlinestyle(PS_SOLID, 3); // 粗线
		} else { 
			setlinestyle(PS_SOLID, 1); // 细线
		}
		line(topLeft.x, topLeft.y + i * CHESS_SIZE, topLeft.x + INNER_SIZE, topLeft.y + i * CHESS_SIZE);
		line(topLeft.x + i * CHESS_SIZE, topLeft.y, topLeft.x + i * CHESS_SIZE, topLeft.y + INNER_SIZE);
	}

	// 绘制点

	// -----------------------     绘制棋子    -------------------------
 	for (int i = 0; i < chessList.size(); i++) {
		chessList[i]->render();
	}

	// ------------------   绘制鼠标悬浮和点击的虚线框  --------------------
	drawFrame(hoverPoint);
	if (clickPoint.x != -1) {
		drawFrame(clickPoint);
	}
}

// 辅助函数
Point ChessBoard::transXY(Point p) {
	p.x = max(p.x, topLeft.x);
	p.x = min(p.x, topLeft.x + INNER_SIZE);
	p.y = max(p.y, topLeft.y);
	p.y = min(p.y, topLeft.y + INNER_SIZE);
	int x = ((p.x - topLeft.x + CHESS_SIZE / 2) / CHESS_SIZE) * CHESS_SIZE + topLeft.x;
	int y = ((p.y - topLeft.y + CHESS_SIZE / 2) / CHESS_SIZE) * CHESS_SIZE + topLeft.y;
	return { x, y };
}

void ChessBoard::drawFrame(Point p) {
	setlinecolor(LIGHTGRAY);
	setlinestyle(PS_SOLID, 2);
	// 设置逻辑坐标原点，方便绘制
	setorigin(p.x, p.y);
	// 左上角
	line(-14, -14, -7, -14);
	line(-14, -14, -14, -7);
	// 右上角
	line(14, -14, 7, -14);
	line(14, -14, 14, -7);
	// 左下角
	line(-14, 14, -7, 14);
	line(-14, 14, -14, 7);
	// 右下角
	line(14, 14, 7, 14);
	line(14, 14, 14, 7);
	// 恢复逻辑坐标原点
	setorigin(0, 0);
}

// getter and setter
void ChessBoard::setHoverPoint(Point p) {
	hoverPoint = transXY(p);
}

void ChessBoard::setClickPoint(Point p) {
	clickPoint = transXY(p);
}