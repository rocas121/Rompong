#include "ball.h"
#include "Const.h"
#include <cstdlib>;
#include <ctime>

Ball::Ball(int x, int y)
{
	mPosX = x;
	mPosY = y;

	mCollider.r = ballWidth / 2;

	//Init vel
	mVelX = 0;
	mVelY = 0; // was 5
	
	velMultiplier = 1.0;
	shiftColliders();
}

void Ball::move(Paddle& paddle1, Paddle& paddle2)
{
	start();

	mPosX += mVelX * velMultiplier; 
    shiftColliders();
	if ( checkCollision(mCollider, paddle1.paddleRect) || checkCollision(mCollider, paddle2.paddleRect))
	{
		mVelX = -mVelX;  
		mPosX += mVelX;

		velMultiplier += 0.1f;
		shiftColliders();
	}

	mPosY += mVelY;
	shiftColliders();

	
	if ((mPosY - mCollider.r < 0) || (mPosY + mCollider.r > screenHeight))
	{
		//Move back
		mVelY = -mVelY;  
		mPosY += mVelY;

		velMultiplier += 0.1f;
		shiftColliders();
	}

	if ((mPosX - mCollider.r < 0) || (mPosX + mCollider.r > screenWidth))
	{
		mPosX = screenWidth / 2 - ballWidth / 2;
		mPosY = screenHeight / 2 - ballHeight / 2;
		mVelX = 0;
		mVelY = 0;

		paddle1.setPosY(screenHeight / 2 - paddle1.getHeight() / 2);
		paddle2.setPosY(screenHeight / 2 - paddle2.getHeight() / 2);
		isStarted = false;
	}
}

void Ball::render()
{
	ballTexture.render(mPosX - mCollider.r, mPosY - mCollider.r);
}

/// <summary>
/// Toss coin to decide which side starts
/// </summary>
/// <returns></returns>
bool Ball::start()
{
	if (isStarted)
	{
		return false;
	}

	std::srand(std::time(0));
	int coin = std::rand() % 2 + 1;

	velMultiplier = 1.0f;
	switch (coin)
	{
	//goes to left
	case 1:

		mVelX = -3;
		break;

	//goes to right
	case 2:

		mVelX = 3;
		break;
		
	}

	isStarted = true;
	return true;
}

bool Ball ::checkCollision(Circle& a, SDL_FRect& b)
{
	int cX, cY;

	// closest x offset

	if (a.x < b.x)
	{
		cX = b.x;
	}
	else if (a.x > b.x + b.w)
	{
		cX = b.x + b.w;
	}
	
	else
	{
		cX = a.x;
	}


	// closest y offset
	if (a.y < b.y)
	{
		cY = b.y;
	}
	else if (a.y > b.y + b.h)
	{
		cY = b.y + b.h;
	}

	else
	{
		cY = a.y;
	}

	if (distanceSquared(a.x, a.y, cX, cY) < a.r * a.r)
	{
		return true;
	}
	return false;
}
	
double Ball::distanceSquared(int x1, int y1, int x2, int y2)
{
	int deltaX = x2 - x1;
	int deltaY = y2 - y1;
	return deltaX * deltaX + deltaY * deltaY;
}

void Ball::shiftColliders()
{
	//Align collider to center of dot
	mCollider.x = mPosX;
	mCollider.y = mPosY;
}

Circle& Ball::getCollider()
{
	return mCollider;
}