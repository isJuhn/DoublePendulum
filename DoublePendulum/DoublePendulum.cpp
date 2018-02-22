#include <SDL.h>
#include <iostream>
#include <memory>
#include "pendulum.h"

int init(std::shared_ptr<SDL_Window>& gWindow, std::shared_ptr<SDL_Renderer>& gRenderer, const int SCREEN_WIDTH, const int SCREEN_HEIGHT);

class doublePendulum 
{
public:
	pendulum p1;
	pendulum p2;
	void update()
	{
		p1.calculateNewPos();
		p2.moveCenter(p1.getX(), p1.getY());
		p2.calculateNewPos();
	}
};

int main(int argc, char* args[])
{
	std::shared_ptr<SDL_Window> gWindow = nullptr;
	std::shared_ptr<SDL_Renderer> gRenderer = nullptr;
	const int SCREEN_WIDTH = 1280;
	const int SCREEN_HEIGHT = 720;

	doublePendulum p;
	p.p1 = pendulum(SCREEN_WIDTH / 2., 300., 200, 10, SCREEN_WIDTH / 2. + 200, 300);
	p.p2 = pendulum(SCREEN_WIDTH / 2., 300., 200, 10, SCREEN_WIDTH / 2. + 200, 300);

	if (init(gWindow, gRenderer, SCREEN_WIDTH, SCREEN_HEIGHT) >= 0)
	{
		SDL_Event e;
		bool quit = false;
		Uint64 last_time = SDL_GetPerformanceCounter();
		float freq = SDL_GetPerformanceFrequency();
		Uint64 now;
		float diff;
		float delay;
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

			now = SDL_GetPerformanceCounter();
			diff = ((now - last_time) / freq) * 1000;
			delay = 1000 / 300. - diff;
			delay = delay > 0 ? delay : 0;
			SDL_Delay(delay);
			last_time = SDL_GetPerformanceCounter();

			p.update();

			SDL_SetRenderDrawColor(gRenderer.get(), 0xFF, 0xFF, 0xFF, 0xFF);
			SDL_RenderClear(gRenderer.get());

			SDL_SetRenderDrawColor(gRenderer.get(), 0xFF, 0x00, 0x00, 0xFF);
			SDL_RenderDrawLine(gRenderer.get(), p.p1.getCenterX(), p.p1.getCenterY(), p.p1.getX(), p.p1.getY());
			SDL_RenderDrawLine(gRenderer.get(), p.p2.getCenterX(), p.p2.getCenterY(), p.p2.getX(), p.p2.getY());

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