#include "game.h"


Game::Game()
{
	backgroundRect_.x = 0;
	backgroundRect_.y = 0;
	backgroundRect_.w = screenWidth_;
	backgroundRect_.h = screenHeight_;
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
			//Time spent rendering
			Uint64 renderingNS{ 0 };
			
			//main loop
			while (quit == false)
			{
				capTimer.start();

				//Event Handling
				EventHandler(quit);

				//Ur logic here
				displayFps(renderingNS);
				rainbow(hue_, helloWorld_);

				//Rendering section
				SDL_FillSurfaceRect(screenSurface_, nullptr, SDL_MapSurfaceRGB(screenSurface_, 0xFF, 0xFF, 0xFF));
				SDL_BlitSurfaceScaled(helloWorld_, nullptr, screenSurface_, &backgroundRect_, SDL_SCALEMODE_LINEAR);
				SDL_UpdateWindowSurface(window_);

				frameRate(renderingNS, capTimer);
			}
		}
		close();
		return exitCode;
	}
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
				backgroundRect_.w = e.window.data1;
				backgroundRect_.h = e.window.data2;
				screenSurface_ = SDL_GetWindowSurface(window_);
				break;
			case SDL_EVENT_WINDOW_RESTORED:
				restoreOriginalSize();
				break;

		}
	}

}
#pragma region logics
void Game::restoreOriginalSize()
{
	int originalW = helloWorld_->w;
	int originalH = helloWorld_->h;

	SDL_SetWindowSize(window_, originalW, originalH);

	backgroundRect_.w = originalW;
	backgroundRect_.h = originalH;
	screenSurface_ = SDL_GetWindowSurface(window_);
	system("cls");
	SDL_Log("Window restored to original BMP size : %dx%d", originalW, originalH);
}

//da rainbow function

void Game::frameRate(Uint64& renderingNS, Timer& capTimer)
{
	//get time to render frame
	renderingNS = capTimer.getTicksNS();

	//If time remaining in frame
	constexpr Uint64 nsPerFrame = 1000000000 / screenFps_;

	if (renderingNS < nsPerFrame)
	{
		//sleep
		Uint64 sleepTime = nsPerFrame - renderingNS;
		SDL_DelayNS(nsPerFrame - renderingNS);

		//get frame time including sleeptime
		renderingNS = capTimer.getTicksNS();
	}

}

void Game::displayFps(Uint64 renderingNS)
{
	if (renderingNS != 0)
	{
		double framesPerSecond{ 1000000000.0 / static_cast<double>(renderingNS) };

		std::cout << "FPS: " << framesPerSecond << "  \r" << std::flush;
	}
}

#pragma endregion

#pragma region Steps
bool Game::init() 
{
	bool success{ true };

	if (!SDL_Init(SDL_INIT_VIDEO))
	{
		SDL_Log("SDL could not initialize, SDL error : %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		if (window_ = SDL_CreateWindow("Hoshino", screenWidth_, screenHeight_, SDL_WINDOW_RESIZABLE); window_ == nullptr)
		{
			SDL_Log("Window could not be created,  SDL error : %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			screenSurface_ = SDL_GetWindowSurface(window_);
		}
	}
	return success;
}

bool Game::loadMedia()
{
	bool success{ true };
	std::string imagePath{"Assets/HoshinoPlush.bmp"};


	if (helloWorld_ = SDL_LoadBMP(imagePath.c_str()); helloWorld_ == nullptr)
	{
		SDL_Log("Unable to load image %s,  SDL error : %s\n", imagePath.c_str(),SDL_GetError());
		success = false;
	}
	else
	{
		int imgW = helloWorld_->w;
		int imgH = helloWorld_->h;

		SDL_SetWindowSize(window_, imgW, imgH);

		backgroundRect_.w = imgW;
		backgroundRect_.h = imgH;

		SDL_SetWindowIcon(window_, helloWorld_);

		screenSurface_ = SDL_GetWindowSurface(window_);

	}

	return success;
}

void  Game::close()
{
	SDL_DestroySurface(helloWorld_);
	helloWorld_ = nullptr;

	SDL_DestroyWindow(window_);
	window_ = nullptr;
	screenSurface_ = nullptr;

	SDL_Quit();
}
#pragma endregion

#pragma region Getter
int Game::getScreenWidth()
{
	return screenWidth_;
}
int Game::getScreenHeight()
{
	return screenHeight_;
}

SDL_Window* Game::getWindow()
{
		return window_;
}
#pragma endregion 