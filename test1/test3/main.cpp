#include "SDL.h"
#include "SDL_image.h"
#include <string>
#include <stdexcept>

using namespace std;

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

SDL_Window *window = nullptr;
SDL_Renderer *renderer = nullptr;


//int filter(void *userdata, SDL_Event * event)
//{
//	throw runtime_error("Failed");
//}

int initSDL()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		return 1;
	}

	window = SDL_CreateWindow("test2",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN);
	if (nullptr == window)
	{
		return 2;
	}

	renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (nullptr == renderer)
	{
		return 3;
	}
	
	return 0;
}

SDL_Texture* LoadImage(string filePath)
{
	return IMG_LoadTexture(renderer,filePath.c_str());
}

void ApplySurface(int x, int y, SDL_Texture *tex)
{
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	SDL_QueryTexture(tex,NULL,NULL,&rect.w,&rect.h);
	SDL_RenderCopy(renderer,tex,NULL,&rect);
}

void QuitSDL()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
int main(int argv, char** argc)
{
	if(initSDL() != 0)
	{
		return 1;
	}

	SDL_Texture *texBackground = LoadImage("../res/background.png");
	
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer,texBackground,NULL,NULL);
	SDL_RenderPresent(renderer);

	//SDL_AddEventWatch(filter,NULL);
		
		SDL_Event e;
	bool quit = false;
	while(!quit)
	{
		while(SDL_PollEvent(&e))
		{
			if(SDL_QUIT == e.type)
			{
				quit = true;
			}
			if(SDL_KEYDOWN == e.type)
			{
				quit = true;
			}
			if(SDL_MOUSEBUTTONDOWN == e.type)
			{
				quit = true;
			}
		}
	}
		
		
	SDL_DestroyTexture(texBackground);
	
	QuitSDL();

	return 0;
}