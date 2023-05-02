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
	setfillcolor(BG_COLOR);
	solidrectangle(TOP_LEFT.x, TOP_LEFT.y, TOP_LEFT.x + CHESS_SIZE * CHESS_NUM, TOP_LEFT.y + CHESS_SIZE * CHESS_NUM);

	// 绘制 x 坐标和 y 坐标
	for (int i = 0; i < xStr.size(); i++) {
		outtextxy(TOP_LEFT.x + i * CHESS_SIZE, TOP_LEFT.y, xStr[i]);
		outtextxy(TOP_LEFT.x, TOP_LEFT.y + i * CHESS_SIZE, yStr[i]);
	}

	// 绘制外部边框

	// 绘制内部线条

	// 绘制点

	// 绘制棋子
	for (int i = 0; i < chesses.size(); i++) {
		chesses[i]->render();
	}
}