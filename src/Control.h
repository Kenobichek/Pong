#pragma once
#include <unordered_map>
#include <functional>
#include <memory>
#include "Event.h"

class Control
{
public:
	using EventListener = std::function<void(std::shared_ptr<Event>)>;
	using EventFunction = std::function<bool(std::shared_ptr<Event>)>;

	void processEvent(std::shared_ptr<Event> e);
	void registerEvent(std::string eventName, EventFunction eventFunction);
	void addEventListener(std::string eventName, EventListener eventListener);

private:
	std::unordered_map<std::string, EventFunction> determineEventMap
	{
		{"W", [](std::shared_ptr<Event> e) { return e->getKey() == Keys::W; }},
		{"S", [](std::shared_ptr<Event> e) { return e->getKey() == Keys::S; }},
		{"UP", [](std::shared_ptr<Event> e) { return e->getKey() == Keys::UP; }},
		{"DOWN", [](std::shared_ptr<Event> e) { return e->getKey() == Keys::DOWN; }},
		{"SPACE", [](std::shared_ptr<Event> e) { return e->getAction() == Action::RELEASE && e->getKey() == Keys::SPACE; }},
		{"QUIT", [](std::shared_ptr<Event> e) { return e->getAction() == Action::QUIT; }},
	};
	std::unordered_map<std::string, std::vector<EventListener>> eventListeners;
};