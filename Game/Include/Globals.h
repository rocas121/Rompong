#pragma once
#ifndef GLOBALS_H
#define GLOBALS_H

#include <SDL3/SDL.h>
#include "Texture.h"

extern SDL_Window* window;

extern SDL_Rect backgroundRect;

extern SDL_Renderer* renderer;

extern Texture pngTexture;


extern Texture ballTexture;

#endif