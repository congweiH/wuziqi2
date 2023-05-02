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

private:
	ChessBoard* chessBoard;
};

