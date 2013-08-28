#pragma once
#include "SDL.h"
#include <map>

class Event
{
public:
	Event(void);
	~Event(void);

	// add event callback function
	void AddCallback(SDL_EventType evtType, SDL_EventType(*)(SDL_Event));

	// remove event callback function
	void RemoveCallback(SDL_EventType evtType);
		
	// clean event callback map
	void CleanCallback();

	// start polling event and do the callback fuction
	void StartEvent();

private:
	// poll next event
	SDL_Event PollEvent();

private:
	SDL_Event mEvent;
	std::map<SDL_EventType, SDL_EventType(*)(SDL_Event)> mEventCallbackMap;
};

