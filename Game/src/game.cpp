#include "game.h"


Game::Game()
{
	backgroundRect.x = 0;
	backgroundRect.y = 0;
	backgroundRect.w = screenWidth;
	backgroundRect.h = screenHeight;
	run();
}

//MAIN LOOP
int Game::run() {
	int exitCode{ 0 };

	if (init() == false)
	{
		SDL_Log("Unable to initialize Progam.\n");
		exitCode = 1;
	}
	else
	{
		if (loadMedia() == false)
		{
			SDL_Log("unable to load media.\n");
			exitCode = 2;
		}
		else
		{
			bool quit{ false };
			Timer capTimer;

			//main loop
			while (quit == false)
			{
				capTimer.start();

				//Event Handling
				EventHandler(quit);

				//Ur logic here
				capTimer.displayFps();

				rainbow(hue_, surfaceHoshino);

				//Rendering section
				SDL_FillSurfaceRect(screenSurface, nullptr, SDL_MapSurfaceRGB(screenSurface, 0xFF, 0xFF, 0xFF));
				SDL_BlitSurfaceScaled(surfaceHoshino, nullptr, screenSurface, &backgroundRect, SDL_SCALEMODE_LINEAR);
				SDL_UpdateWindowSurface(window);


				capTimer.frameRate();
			}
		}
	}
	close();
	return exitCode;
}

void Game::EventHandler(bool& quit)
{

	SDL_Event e;
	SDL_zero(e);

	while (SDL_PollEvent(&e))
	{
		switch (e.type)
		{
			case SDL_EVENT_QUIT:
				quit = true;
				break;

			case SDL_EVENT_WINDOW_RESIZED:
				backgroundRect.w = e.window.data1;
				backgroundRect.h = e.window.data2;
				screenSurface = SDL_GetWindowSurface(window);
				break;
			case SDL_EVENT_WINDOW_RESTORED:
				restoreOriginalSize();
				break;
			case SDL_EVENT_WINDOW_MINIMIZED:
				restoreOriginalSize();
				break;

			case SDL_EVENT_KEY_DOWN:
				switch (e.key.key)
					case SDLK_ESCAPE:
						quit = true;
						break;
		}
	}

}