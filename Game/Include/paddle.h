#pragma once
#include <SDL3/SDL.h>
#include "Const.h"

class Paddle
{
private:
	static constexpr int paddleWidth = 20;
	static constexpr int paddleHeight = 20;

	static constexpr int paddleVel = 10;

	int mPosX, mPosY;
	int mVelX, mVelY;

public:

	Paddle();

	void handleEvent(SDL_Event& e);

	void move();

	void render(SDL_FRect& paddle);

};