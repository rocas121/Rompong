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
		//else 
		//{
		//	screenSurface = SDL_GetWindowSurface(window);
		//}
	}
	return success;
}

bool loadMedia()
{
	bool success{ true };
	//std::string imagePath{ "Assets/HoshinoPlush.bmp" };
	//if (surfaceHoshino = SDL_LoadBMP(imagePath.c_str()); surfaceHoshino == nullptr)
	//{
	//	SDL_Log("Unable to load image %s,  SDL error : %s\n", imagePath.c_str(), SDL_GetError());
	//	success = false;
	//}
		//File loading flag

	//Load splash image
	if (pngTexture.loadFromFile("Assets/HoshinoPlush.bmp") == false)
	{
		SDL_Log("Unable to load png image!\n");
		success = false;
	}
	return success;
}

void close()
{
	SDL_DestroySurface(surfaceHoshino);
	surfaceHoshino = nullptr;

	pngTexture.destroy();

	SDL_DestroyRenderer(renderer);
	renderer = nullptr;
	SDL_DestroyWindow(window);
	window = nullptr;

	screenSurface = nullptr;
	

	SDL_Quit();
}