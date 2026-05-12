#include "paddle.h"


Paddle::Paddle(bool isPlayer):
	mPosX{ (isPlayer) ? (padding) : (screenWidth - paddleWidth - padding) },
	mPosY{ screenHeight / 2 - paddleHeight / 2 },
	mVelX{ 0 },
	mVelY{ 0 }
{
	SDL_Log("Paddle created at X: %d, Y: %d", mPosX, mPosY);
}

void Paddle::handleEvent(SDL_Event& e, bool isPlayer)
{
	if (e.type == SDL_EVENT_KEY_DOWN && e.key.repeat == 0)
	{

		if (isPlayer)
		{
			switch (e.key.key)
			{
				case SDLK_W:
					mVelY -= paddleVel;
					break;
				case SDLK_S:
					mVelY += paddleVel;
					break;
					/*			case SDLK_LEFT:
									mVelX -= paddleVel;
									break;
								case SDLK_RIGHT:
									mVelX += paddleVel;
								break;			*/
			}
		}
		else
		{
			switch (e.key.key)
			{
				case SDLK_UP:
					mVelY -= paddleVel;
					break;
				case SDLK_DOWN:
					mVelY += paddleVel;
					break;
					/*			case SDLK_LEFT:
									mVelX -= paddleVel;
									break;
								case SDLK_RIGHT:
									mVelX += paddleVel;
									break;			*/
			}
		}


	}
	else if (e.type == SDL_EVENT_KEY_UP && e.key.repeat == 0)
	{
		if (isPlayer)
		{
			switch (e.key.key)
			{
			case SDLK_W:
				mVelY += paddleVel;
				break;
			case SDLK_S:
				mVelY -= paddleVel;
				break;
				//case SDLK_LEFT:
				//	mVelX += paddleVel;
				//	break;
				//case SDLK_RIGHT:
				//	mVelX -= paddleVel;
				//	break;
			}
		}
		else
		{
			switch (e.key.key)
			{
			case SDLK_UP:
				mVelY += paddleVel;
				break;
			case SDLK_DOWN:
				mVelY -= paddleVel;
				break;
				//case SDLK_LEFT:
				//	mVelX += paddleVel;
				//	break;
				//case SDLK_RIGHT:
				//	mVelX -= paddleVel;
				//	break;
			}
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
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); //is white
	SDL_RenderFillRect(renderer, &paddleRect);
}