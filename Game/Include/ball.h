#pragma once
#include "Globals.h"


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

		Circle mCollider;

		void shiftColliders();


	public:
		static constexpr int ballWidth = 20;
		static constexpr int ballHeight = 20;
		static constexpr int ballVel = 10;

		Ball( int x , int y);

		void move(SDL_Rect& square, Ball& ball);
		void render();

		Circle& getCollider();

		bool checkCollision(Circle& a, SDL_Rect& b);


		double distanceSquared(int x1, int y1, int x2, int y2);
};