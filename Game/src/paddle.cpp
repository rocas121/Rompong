#include "paddle.h"


Paddle::Paddle() :
	mPosX{ 0 },
	mPosY{ 0 },
	mVelX{ 0 },
	mVelY{ 0 }
{
}

void Paddle::handleEvent(SDL_Event& e)
{
	if (e.type == SDL_EVENT_KEY_DOWN && e.key.repeat == 0)
	{
		switch (e.key.key)
		{
			case SDLK_UP: 
				mVelY -= paddleVel;
				break;
			case SDLK_DOWN:
				mVelY += paddleVel;
				break;
			case SDLK_LEFT:
				mVelX -= paddleVel;
				break;
			case SDLK_RIGHT:
				mVelX += paddleVel;
				break;					
		}
	}
	else if (e.type == SDL_EVENT_KEY_UP && e.key.repeat == 0)
	{
		switch (e.key.key)
		{
		case SDLK_UP:
			mVelY += paddleVel;
			break;
		case SDLK_DOWN:
			mVelY -= paddleVel;
			break;
		case SDLK_LEFT:
			mVelX += paddleVel;
			break;
		case SDLK_RIGHT:
			mVelX -= paddleVel;
			break;
		}
	}
}

void Paddle::move()
{
	mPosX += mVelX;
	if ((mPosX < 0) || (mPosX + paddleWidth > screenWidth))
	{
		mPosX -= mVelX;
	}

	mPosY += mVelY;

	if ((mPosY < 0) || (mPosY + paddleHeight > screenHeight))
	{
		mPosY -= mVelY;
	}
}

void Paddle::render(SDL_FRect& paddle)
{
	paddle.x = static_cast<float>(mPosX);
	paddle.y = static_cast<float>(mPosY);
	paddle.w = static_cast<float>(paddleWidth);
	paddle.h = static_cast<float>(paddleHeight);
}