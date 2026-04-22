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

		if (SDL_CreateWindowAndRenderer("Hoshino", screenWidth, screenHeight, SDL_WINDOW_RESIZABLE, &window, &renderer) == false)
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

	//Load splash image
	if (pngTexture.loadFromFile("Assets/HoshinoPlush.bmp") == false)
	{
		SDL_Log("Unable to load png image!\n");
		success = false;
	}

	if (ballTexture.loadFromFile("Assets/dot.bmp") == false)
	{
		SDL_Log("Unable to load png image!\n");
		success = false;
	}

	return success; //always put at end
}

void close()
{
	pngTexture.destroy();
	ballTexture.destroy();

	SDL_DestroyRenderer(renderer);
	renderer = nullptr;
	SDL_DestroyWindow(window);
	window = nullptr;

	SDL_Quit();
}