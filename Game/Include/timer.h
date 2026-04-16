#pragma once
#include <SDL3/SDL_timer.h>

class Timer
{
	private:
		Uint64 mStartTicks_{ 0 };

	public:

		void start();
		Uint64 getTicksNS();
};