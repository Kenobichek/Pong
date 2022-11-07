#include "EventSDLAdapter.h"

Keys EventSDLAdapter::getKey() const
{
	switch (e.key.keysym.sym)
	{
	case SDLK_w:
		return Keys::W;
	case SDLK_s:
		return Keys::S;
	case SDLK_SPACE:
		return Keys::SPACE;
	case SDLK_UP:
		return Keys::UP;
	case SDLK_DOWN:
		return Keys::DOWN;
	default:
		return Keys::UNKNOWN;
	}
}

Action EventSDLAdapter::getAction() const
{
	switch (e.type)
	{
	case SDL_KEYUP:
		return Action::RELEASE;
	case SDL_KEYDOWN:
		return Action::PRESS;
	case SDL_QUIT:
		return Action::QUIT;
	default:
		return Action::UNKNOWN;
	}
}

bool EventSDLAdapter::pollEvent()
{
	return SDL_PollEvent(&e);
}
