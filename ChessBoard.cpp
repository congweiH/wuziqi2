#include "ChessBoard.h"

ChessBoard::ChessBoard() {
	
}

bool ChessBoard::canPut(ExMessage mouse) {
	return true;
}

void ChessBoard::putChess(Point p, COLORREF color) {
	Chess* chess = new Chess(p, color);
	chesses.push_back(chess);
}

void ChessBoard::render() {
	// 填充棋盘背景色
	int a = CHESS_SIZE * (CHESS_NUM + 2);	// 总的棋盘的边长大小
	setfillcolor(BG_COLOR);
	solidrectangle(TOP_LEFT.x, TOP_LEFT.y, TOP_LEFT.x + a, TOP_LEFT.y + a);

	// 绘制 x 坐标和 y 坐标
	settextcolor(BLACK);
	for (int i = 0; i < xStr.size(); i++) {
		outtextxy(TOP_LEFT.x + i * CHESS_SIZE, TOP_LEFT.y, xStr[i]);
		outtextxy(TOP_LEFT.x, TOP_LEFT.y + i * CHESS_SIZE, yStr[i]);
	}

	// 绘制棋盘线条
	Point topLeft = { TOP_LEFT.x + CHESS_SIZE,  TOP_LEFT.y + CHESS_SIZE };	// 内部棋盘的左上角
	int b = CHESS_SIZE * CHESS_NUM;		// 内部棋盘的边长大小
	setlinecolor(BLACK);
	for (int i = 0; i < 13; i++) {
		if (i == 0 || i == 12) {
			// 粗线
			setlinestyle(PS_SOLID, 3);
		} else {
			// 细线
			setlinestyle(PS_SOLID, 1);
		}
		line(topLeft.x, topLeft.y + i * CHESS_SIZE, topLeft.x + b, topLeft.y + i * CHESS_SIZE);
		line(topLeft.x + i * CHESS_SIZE, topLeft.y, topLeft.x + i * CHESS_SIZE, topLeft.y + b);
	}

	// 绘制点

	// 绘制棋子
	for (int i = 0; i < chesses.size(); i++) {
		chesses[i]->render();
	}
}