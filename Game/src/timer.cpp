#include "timer.h"



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