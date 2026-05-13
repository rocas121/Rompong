#ifndef BALL_H
#define BALL_H

#include "Globals.h"
#include "paddle.h"

struct Circle
{
	int x, y;
	int r;
};

class Ball
{
	private:

		int mPosX, mPosY;

		int mVelX, mVelY;

		float velMultiplier; 

		Circle mCollider;

		void shiftColliders();

		bool isStarted = false;
		bool firstBounce = true;

	public:
		static constexpr int ballWidth = 20;
		static constexpr int ballHeight = 20;
		static constexpr int ballVel = 10;

		Ball( int x , int y);

		void move(Paddle& paddle1, Paddle& paddle2);
		void render();

		Circle& getCollider();


		bool checkCollision(Circle& a, SDL_FRect& b);
		double distanceSquared(int x1, int y1, int x2, int y2);
		
		bool start();
};

#endif