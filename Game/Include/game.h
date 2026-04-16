#include <iostream>
#include <SDL3/SDL.h>
#include <string>
#include <cmath>
#include <algorithm>
#include "timer.h"

class Game 
{
	private:
		static constexpr int screenWidth_{ 640 };
		static constexpr int screenHeight_{ 480 };
		static constexpr int screenFps_{ 60 };
	
		SDL_Window* window_{ nullptr };
		SDL_Surface* screenSurface_{ nullptr };

		SDL_Surface* helloWorld_{ nullptr };

		SDL_Rect backgroundRect_; 

		float hue_ = 0.0f;

	public:
		//Base
		Game();
		int run();
		void EventHandler(bool& quit);
		bool init();
		bool loadMedia();
		void close();
	
		//Logics
		void restoreOriginalSize();
		void rainbow();

		//Get
		int getScreenWidth();
		int getScreenHeight();
		SDL_Window* getWindow();

		void frameRate(Uint64& renderingNS, Timer& capTimer);
		void displayFps(Uint64 renderingNS);

};