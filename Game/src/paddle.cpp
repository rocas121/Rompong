#include "paddle.h"


Paddle::Paddle() :
	mPosX{ screenWidth/2 - paddleWidth/2 },
	mPosY{ screenHeight / 2 - paddleHeight / 2 },
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

void Paddle::render()
{
	paddleRect.x = mPosX;
	paddleRect.y = mPosY;
	paddleRect.w = paddleWidth;
	paddleRect.h = paddleHeight;
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); //is red
	//SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); //is white
	SDL_RenderFillRect(renderer, &paddleRect);
}