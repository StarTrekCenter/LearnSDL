#include "Window.h"
#include <stdexcept>

using namespace std;

Window::Window(void): mWindow(nullptr), mRenderer(nullptr)
{
}


Window::~Window(void)
{
}

void Window::Init(string tittle)
{
	if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		throw runtime_error("SDL Init Failed");
	}

}

//Quit SDL and TTF
void Window::Quit()
{
}

//Draw an SDL_Texture
void Window::Draw(SDL_Texture*)
{
}

//Load an image
SDL_Texture* Window::LoadImage(std::string file)
{
}

//Render some text
SDL_Texture* Window::RenderText(std::string, std::string, SDL_Color, int)
{
}

//Clear window
void Window::Clear()
{
}

//Present renderer
void Window::Present()
{
}

//Get the window's box
SDL_Rect Window::Box()
{
}
