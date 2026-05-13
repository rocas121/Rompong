#ifndef  PADDLE_H
#define PADDLE_H

#include "Const.h"
#include "Globals.h"
class Paddle
{
private:
	static constexpr int paddleWidth = 20;
	static constexpr int paddleHeight = 80;
	static constexpr int padding = 20;
	static constexpr int paddleVel = 10;

	int mPosX, mPosY;
	int mVelX, mVelY;



public:

	SDL_FRect paddleRect;

	Paddle(bool isPlayer);

	void handleEvent(SDL_Event& e, bool isPlayer);

	void move();

	void render();

	void setPosY(int y);

	int getHeight();
};

#endif