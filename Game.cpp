#include "Game.h"
#include <easyx.h>

Game::Game() {
	initgraph(600, 600);
	// 设置当前设备图案填充和文字输出时的背景模式为透明
	setbkmode(TRANSPARENT);

	chessBoard = new ChessBoard();
}

Game::~Game() {
	delete chessBoard;
	EndBatchDraw();
	closegraph();
}

void Game::handleInput() {
	// 获取鼠标信息
	ExMessage m = getmessage(EX_MOUSE);
	// 鼠标在棋盘内
	if (chessBoard->inChessBoard({ m.x, m.y })) {
		chessBoard->setHoverPoint({ m.x, m.y });
		if (m.lbutton && chessBoard->canPut({ m.x, m.y })) {
			chessBoard->putChess({ m.x, m.y }, BLACK);
		}
	}
}

void Game::update() {
	// 判断输赢
}

void Game::render() {
	// 使用白色背景清空屏幕
	setbkcolor(WHITE);
	cleardevice();

	// 开始批量绘画
	BeginBatchDraw();
	chessBoard->render();

	FlushBatchDraw();
}