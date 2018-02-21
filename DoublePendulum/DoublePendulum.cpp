#include <SDL.h>
#include <iostream>
#include <memory>

int main(int argc, char* args[])
{
	if (SDL_Init(SDL_INIT_VIDEO) >= 0)
	{

	}
	else
	{
		std::cout << "SDL_ERROR: " << SDL_GetError() << std::endl;
	}
	SDL_Quit();
	return 0;
}
