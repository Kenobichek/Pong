#pragma once
#include "Event.h"
#include <SDL.h>

class EventSDLAdapter : public Event
{
public:
	Keys getKey() const override;
	Action getAction() const override;
	bool pollEvent() override;

private:
	SDL_Event e;
};