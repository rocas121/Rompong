#ifndef TEXTURE_H
#define TEXTURE_H

#include <SDL3/SDL.h>
#include <string>
class Texture
{
	private:
		SDL_Texture* mTexture;

		//Texture dimensions
		int mWidth;
		int mHeight;

	public:
		Texture();

		~Texture();

		bool loadFromFile(std::string path);

		//Cleans up texture
		void destroy();

		//Draws texture
		void render(float x, float y);

		//Gets texture attributes
		int getWidth();
		void setWidth(int w);
		int getHeight();
		void setHeight(int h);
		bool isLoaded();
};


#endif