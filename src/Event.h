#pragma once

enum class Keys
{
	UNKNOWN = -1,
	W,
	S,
	SPACE,
	UP,
	DOWN,
};

enum class Action
{
	UNKNOWN = -1,
	RELEASE,
	PRESS,
	QUIT,
};

class Event
{
public:
	virtual Keys getKey() const = 0;
	virtual Action getAction() const = 0;
	virtual bool pollEvent() = 0;
};