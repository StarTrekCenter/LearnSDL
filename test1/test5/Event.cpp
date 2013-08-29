#include "Event.h"
using namespace std;

Event::Event(void)
{
	mEvent.type = SDL_FIRSTEVENT;
}


Event::~Event(void)
{
}

// add event callback function
void Event::AddCallback(SDL_EventType evtType, SDL_EventType(*foo)(SDL_Event))
{
	mEventCallbackMap[evtType] = foo;
}

// remove event callback function
void Event::RemoveCallback(SDL_EventType evtType)
{
	mEventCallbackMap.erase(evtType);
}

// clean event callback map
void Event::CleanCallback()
{
	mEventCallbackMap.clear();
}

// start polling event and do the callback fuction
void Event::StartEvent()
{
	map<SDL_EventType, SDL_EventType(*)(SDL_Event)>::iterator it;
	SDL_EventType typeEvent = SDL_FIRSTEVENT;
	SDL_EventType typeReturn = SDL_FIRSTEVENT;

	PollEvent();
	typeEvent = (SDL_EventType)mEvent.type;
	while(SDL_QUIT != typeEvent && SDL_QUIT != typeReturn)
	{
		it = mEventCallbackMap.find(typeEvent);
		if (it != mEventCallbackMap.end())
		{
			typeReturn = it->second(mEvent);
		}
		PollEvent();
		typeEvent = (SDL_EventType)mEvent.type;
	}
}


// poll next event
SDL_Event Event::PollEvent()
{
	SDL_PollEvent(&mEvent);
	return mEvent;
}