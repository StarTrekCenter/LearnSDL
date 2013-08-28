#include "SDL.h"
#include "SDL_image.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argv, char** argc)
{
	if(0 > SDL_Init(SDL_INIT_EVERYTHING))
	{
		return 1;
	}

	SDL_Window *win = nullptr;
	win = SDL_CreateWindow("test1",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN);
	if (nullptr == win)
	{
		return 2;
	}

	SDL_Renderer *ren = nullptr;
	ren = SDL_CreateRenderer(win,-1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (nullptr == ren)
	{
		return 3;
	}

	SDL_Surface *bmp = nullptr;
	bmp = SDL_LoadBMP("../res/background.bmp");
	if(nullptr == bmp)
	{
		return 4;
	}

	SDL_Texture *tex = nullptr;
	tex = SDL_CreateTextureFromSurface(ren,bmp);
	if (nullptr == tex)
	{
		return 5;
	}
	SDL_free(bmp);

	SDL_RenderClear(ren);
	SDL_RenderCopy(ren,tex,NULL,NULL);
	SDL_RenderPresent(ren);

	SDL_Delay(4000);

	SDL_DestroyRenderer(ren);
	SDL_DestroyTexture(tex);
	SDL_DestroyWindow(win);
	SDL_Quit();

	return 0;
}