#pragma once
#include <string>
class Texture
{
	private:

	public:
		Texture();

		~Texture();

		bool loadFromFile(std::string path);
};