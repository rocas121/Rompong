#include "Util.h"
#include "Const.h"
#include "Globals.h"

bool init()
{
	bool success{ true };

	if (!SDL_Init(SDL_INIT_VIDEO))
	{
		SDL_Log("SDL could not initialize, SDL error : %s\n", SDL_GetError());
		success = false;
	}
	else
	{

		if (SDL_CreateWindowAndRenderer("Rompong", screenWidth, screenHeight, SDL_WINDOW_RESIZABLE, &window, &renderer) == false)
		{
			SDL_Log("Window could not be created,  SDL error : %s\n", SDL_GetError());
			success = false;
		}

	}
	return success;
}

bool loadMedia()
{
	bool success{ true };


	if (ballTexture.loadFromFile("Assets/ball.bmp") == false)
	{
		SDL_Log("Unable to load png image!\n");
		success = false;
	}

	return success; 
}

void close()
{
	ballTexture.destroy();

	SDL_DestroyRenderer(renderer);
	renderer = nullptr;
	SDL_DestroyWindow(window);
	window = nullptr;

	SDL_Quit();
}