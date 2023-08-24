#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
	int window_w = 1460;
	int window_h = 960;

	const int FPS = 80;
	const int frameDelay = 1000 / FPS;
	Uint32 frameStart;
	Uint32 frameTime;

	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* window = SDL_CreateWindow("TITLE", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, window_w, window_h, false);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
	if (renderer)
	{
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	}

	bool isRunning = true;
	SDL_Event event;
	SDL_Surface* tmpSurface;

	// background
	tmpSurface = IMG_Load("assets/background.png");
	SDL_Texture* backgroundTex = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);

	SDL_Rect backgroundRect{};
	backgroundRect.w = window_w;
	backgroundRect.h = window_h;
	backgroundRect.x = 0;
	backgroundRect.y = 0;

	// flappy bird 
	tmpSurface = IMG_Load("assets/flappy_bird.png");
	SDL_Texture* birdTex = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);

	SDL_Rect birdRect{};
	birdRect.w = 64;
	birdRect.h = 64;
	birdRect.x = 70;
	birdRect.y = 100;

	// pipe
	tmpSurface = IMG_Load("assets/pipe");
	SDL_Texture* pipeTex = SDL_CreateTextureFromSurface(renderer, tmpSurface);

	SDL_Rect pipeRect{};
	pipeRect.w = 64;
	pipeRect.h = 256;
	pipeRect.x = 70;
	pipeRect.y = 100;

	// main loop
	while (isRunning)
	{
		frameStart = (Uint32)SDL_GetTicks64();

		// event
		SDL_PollEvent(&event);
		switch (event.type)
		{
		case SDL_QUIT:
			isRunning = false;
			break;
		case SDL_KEYDOWN:
			/* keyboard event */
			switch (event.key.keysym.sym)
			{
			case SDLK_x:
				isRunning = false;
				break;
			default:
				break;
			}
			break;
		case SDL_KEYUP:
			//switch (event.key.keysym.sym)
			//{
			//default:
			//	break;
			//}
			break;
		default:
			break;
		}

		// update

		

		// collision


		// render
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, backgroundTex, NULL, &backgroundRect);
		SDL_RenderCopy(renderer, birdTex, NULL, &birdRect);
		SDL_RenderCopy(renderer, pipeTex, NULL, &pipeRect);
		SDL_RenderPresent(renderer);



		// FPS
		frameTime = (Uint32)SDL_GetTicks64() - frameStart;
		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}
	}

	// game end
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();

	return 0;
}
