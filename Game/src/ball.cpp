#include "ball.h"
#include "Const.h"

Ball::Ball(int x, int y)
{
	mPosX = x;
	mPosY = y;

	mCollider.r = ballWidth / 2;

	mVelX = 0;
	mVelY = 0;

	shiftColliders();
}

void Ball::move(SDL_Rect& square, Ball& ball)
{
	mPosX += mVelX;
	shiftColliders();

	if ( (mPosX - mCollider.r < 0) || (mPosX + mCollider.r > screenWidth) || checkCollision(mCollider, square) )
	{
		mPosX -= mVelX;
		shiftColliders();
	}

	mPosY += mVelY;
	shiftColliders();

	//If the dot collided or went too far up or down
	if ((mPosY - mCollider.r < 0) || (mPosY + mCollider.r > screenHeight) || checkCollision(mCollider, square))
	{
		//Move back
		mPosY -= mVelY;
		shiftColliders();
	}

}

void Ball::render()
{
	ballTexture.render(mPosX - mCollider.r, mPosY - mCollider.r);
}

bool Ball ::checkCollision(Circle& a, SDL_Rect& b)
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