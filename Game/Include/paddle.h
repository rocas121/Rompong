#pragma once
#include "Const.h"
#include "Globals.h"
class Paddle
{
private:
	static constexpr int paddleWidth = 20;
	static constexpr int paddleHeight = 20;

	static constexpr int paddleVel = 10;

	int mPosX, mPosY;
	int mVelX, mVelY;

	SDL_FRect paddleRect;

public:

	Paddle();

	void handleEvent(SDL_Event& e);

	void move();

	void render();

};