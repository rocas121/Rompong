#include <iostream>
#include <SDL3/SDL.h>
#include <string>
#include <cmath>
#include <algorithm>


class Game {
private:
	static constexpr int screenWidth_{ 640 };
	static constexpr int screenHeight_{ 480 };

	SDL_Window* window_{ nullptr };
	SDL_Surface* screenSurface_{ nullptr };

	SDL_Surface* helloWorld_{ nullptr };

	SDL_Rect backgroundRect_; 

	float hue_ = 0.0f;

public:
	//Base
	Game();
	int run();
	void EventHandler(SDL_Event event, bool& quit);
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
	//SDL_Surface* getScreenSurface();
	//SDL_Surface* getHelloWorld();
};