#pragma once
#include "ChessBoard.h"

class Game
{
public:
	Game();
	~Game();

	void handleInput();
	void update();
	void render();

	void toggleColor();

private:
	ChessBoard* chessBoard;
	COLORREF color;
};

