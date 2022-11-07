#include "Control.h"

void Control::processEvent(std::shared_ptr<Event> e)
{
    for (auto it = determineEventMap.begin(); it != determineEventMap.end(); it++)
    {
        if (it->second(e))
        {
            auto itEventListeners = eventListeners.find(it->first);
            if (itEventListeners != eventListeners.end())
            {
                for (auto listener : itEventListeners->second)
                {
                    listener(e);
                }
            }
        }
    }
}

void Control::registerEvent(std::string eventName, EventFunction eventFunction)
{
    determineEventMap.insert({ eventName, eventFunction });
}

void Control::addEventListener(std::string eventName, EventListener eventListener)
{
    auto it = eventListeners.find(eventName);
    if (it == eventListeners.end())
    {
        eventListeners.insert({ eventName, { eventListener } });
    }
    else
    {
        it->second.push_back(eventListener);
    }
}
