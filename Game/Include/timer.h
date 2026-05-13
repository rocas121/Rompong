#pragma once
#include <SDL3/SDL_timer.h>

//Contains timer for FPS
class Timer
{
	private:
		Uint64 mStartTicks_{ 0 };

		//Time spent rendering
		Uint64 renderingNS_{ 0 };

	public:

		void start();
		Uint64 getTicksNS();

		void frameRate();
		void displayFps();
		void reset();

};