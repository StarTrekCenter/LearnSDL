#include "Window.h"
#include "Event.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

SDL_EventType funKeyDown(SDL_Event evt)
{
	return SDL_QUIT;
}

int main(int argv, char** argc)
{
	Window win;
	win.Init("MyWindow");
	
	SDL_Texture *texBackground = win.LoadImage("../res/background.png");
	win.Clear();
	win.Draw(texBackground,win.Box());
	win.Present();

	Event evt;
	evt.AddCallback(SDL_KEYDOWN,funKeyDown);
	evt.StartEvent();

	return 0;
}