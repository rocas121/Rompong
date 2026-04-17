#include <iostream>
#include "timer.h"
#include "Const.h"

void Timer::start()
{

	mStartTicks_ = SDL_GetTicksNS();
}


Uint64 Timer::getTicksNS()
{
	Uint64 time{ 0 };

	time = SDL_GetTicksNS() - mStartTicks_;
	return time;
}

void Timer::frameRate()
{
	//get time to render frame
	renderingNS_ = getTicksNS();

	//If time remaining in frame
	constexpr Uint64 nsPerFrame = 1000000000 / screenFps;	

	if (renderingNS_ < nsPerFrame)
	{
		//sleep
		Uint64 sleepTime = nsPerFrame - renderingNS_;
		SDL_DelayNS(nsPerFrame - renderingNS_);

		//get frame time including sleeptime
		renderingNS_ = getTicksNS();
	}

}

void Timer::displayFps()
{
	if (renderingNS_ != 0)
	{
		double framesPerSecond{ 1000000000.0 / static_cast<double>(renderingNS_) };

		std::cout << "FPS: " << framesPerSecond << "  \r" << std::flush;
	}
}