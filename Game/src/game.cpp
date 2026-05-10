#include "game.h"


Game::Game() : 
paddle(true),
npcPaddle(false)
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
			
			//temp hoshino
			//SDL_Rect tempRect = { 0, 0, screenWidth, screenHeight };

			//sets texture to current image
			//pngTexture.setWidth(screenWidth);
			//pngTexture.setHeight(screenHeight);

			//ball
			Ball ball(screenWidth / 2 - Ball::ballWidth / 2, screenHeight / 2 - Ball::ballHeight / 2);


			//main loop
			while (quit == false)
			{
				capTimer.start();

				//Event Handling
				EventHandler(quit);

				//Ur logic here
				capTimer.displayFps();


				paddle.move();
				npcPaddle.move();
				ball.move();

				////background
				SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
				SDL_RenderClear(renderer);

				//Rendering surface for hoshino, UpdateWindowSurface and RenderPresents overwrite each others, must convert surface into texture then remove surface

				//pngTexture.render(0.f, 0.f);

				SDL_FRect PaddleRect;
				paddle.render();
				npcPaddle.render();

				//ball
				ball.render();

				SDL_RenderPresent(renderer);

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

			case SDL_EVENT_KEY_DOWN:
				switch (e.key.key)
					case SDLK_ESCAPE:
						quit = true;
						break;
		}

		paddle.handleEvent(e);
		npcPaddle.handleEvent(e);
	}

}