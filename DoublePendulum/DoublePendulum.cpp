#include <SDL.h>
#include <iostream>
#include <memory>

int init(std::shared_ptr<SDL_Window>& gWindow, std::shared_ptr<SDL_Renderer>& gRenderer, const int SCREEN_WIDTH, const int SCREEN_HEIGHT);

int main(int argc, char* args[])
{
	std::shared_ptr<SDL_Window> gWindow = nullptr;
	std::shared_ptr<SDL_Renderer> gRenderer = nullptr;
	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 480;

	if (init(gWindow, gRenderer, SCREEN_WIDTH, SCREEN_HEIGHT) >= 0)
	{
		SDL_Event e;
		bool quit = false;
		
		while (!quit)
		{
			//events
			while (SDL_PollEvent(&e) != 0)
			{
				if (e.type == SDL_QUIT)
				{
					quit = true;
				}
			}

			SDL_SetRenderDrawColor(gRenderer.get(), 0xFF, 0xFF, 0xFF, 0xFF);
			SDL_RenderClear(gRenderer.get());

			

			SDL_RenderPresent(gRenderer.get());
		}
	}
	SDL_Quit();
	return 0;
}

int init(std::shared_ptr<SDL_Window>& gWindow, std::shared_ptr<SDL_Renderer>& gRenderer, const int SCREEN_WIDTH, const int SCREEN_HEIGHT)
{
	if (SDL_Init(SDL_INIT_VIDEO) >= 0)
	{
		SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
		gWindow = std::shared_ptr<SDL_Window>(SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN), SDL_DestroyWindow);
		gRenderer = std::shared_ptr<SDL_Renderer>(SDL_CreateRenderer(gWindow.get(), -1, SDL_RENDERER_ACCELERATED), SDL_DestroyRenderer);
		SDL_SetRenderDrawColor(gRenderer.get(), 0xFF, 0xFF, 0xFF, 0xFF);
	}
	else
	{
		std::cout << "SDL_ERROR: " << SDL_GetError() << std::endl;
		return -1;
	}
	return 0;
}