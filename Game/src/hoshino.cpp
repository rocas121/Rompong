#include "hoshino.h"

//What makes Hoshino.

void rainbow(float& hue, SDL_Surface* surface)
{
	//Hue is reversed btw
	float speed = 15.0f;
	hue -= speed * 0.016f; //somewhere at 60 fps
	if (hue <= 0.0f)hue += 360.0f; //set to 0


	float s = 1.0f; // Saturation 
	float v = 1.0f; // Value
	float c = v * s;

	float x = c * (1 - std::abs(std::fmod(hue / 60.0f, 2) - 1));
	float m = v - c;
	float r, g, b;

	if (hue < 60) { r = c; g = x; b = 0; }
	else if (hue < 120) { r = x; g = c; b = 0; }
	else if (hue < 180) { r = 0; g = c; b = x; }
	else if (hue < 240) { r = 0; g = x; b = c; }
	else if (hue < 300) { r = x; g = 0; b = c; }
	else { r = c; g = 0; b = x; }

	SDL_SetSurfaceColorMod(surface, (Uint8)((r + m) * 255), (Uint8)((g + m) * 255), (Uint8)((b + m) * 255));
}

void restoreOriginalSize()
{
	int originalW = surfaceHoshino->w;
	int originalH = surfaceHoshino->h;

	SDL_SetWindowSize(window, originalW, originalH);

	backgroundRect.w = originalW;
	backgroundRect.h = originalH;
	screenSurface = SDL_GetWindowSurface(window);
}