#pragma once
#include <vector>
#include "Chess.h"

class ChessBoard
{
public:
	ChessBoard();
	~ChessBoard();

	bool inChessBoard(Point p);
	bool canPut(Point p);
	void putChess(Point p, COLORREF color);
	void render();

	// getter and setter
	void setHoverPoint(Point p);
	void setClickPoint(Point p);
	void setHaveChess(Point p, bool f);
	bool getHaveChess(Point p);

private:
	Point transXY(Point p);		// 将鼠标点击的位置转换成点的坐标
	void drawFrame(Point p);

private:
	std::vector<Chess*> chessList;
	Point hoverPoint;
	Point clickPoint = { -1, -1 };
	bool haveChess[13][13];

	// 棋盘长和宽度有12个格子
	static const int CHESS_NUM = 12;

	// 每个棋子的大小是30px * 30px
	static const int CHESS_SIZE = 30;

	// 棋盘左上角的坐标
	const Point TOP_LEFT = { 50, 50 };
	Point topLeft = { TOP_LEFT.x + CHESS_SIZE,  TOP_LEFT.y + CHESS_SIZE };	// 内部棋盘的左上角
	const int INNER_SIZE = CHESS_SIZE * CHESS_NUM;		// 内部棋盘的边长大小

	// 背景色
	COLORREF BG_COLOR = RGB(255, 205, 150);

	// x、y坐标
	std::vector<LPCTSTR> xStr { L" ", L"1", L"2", L"3", L"4", L"5", L"6", L"7", L"8", L"9", L"10", L"11", L"12", L"13" };
	std::vector<LPCTSTR> yStr { L" ", L"A", L"B", L"C", L"D", L"E", L"F", L"G", L"H", L"I", L"J", L"K", L"L", L"M" };
};