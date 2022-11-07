#pragma once
#include <string>
#include "SDL_ttf.h"
#include <queue>

#include "Window.h"
#include "Control.h"

enum class Movement
{
	UP,
	DOWN,
	STOP,
};

class Player
{
public:
	Player();

	void setPosition(const int& x, const int& y);
	void setPosition(const int& y);

	int getPosX();
	int getPosY();
	int getWidth();
	int getHeight();
	int getTop();
	int getBottom();
	int getScore();
	Movement getMovement();

	void addScore();
	void addPositionNextBall(const int& y);

	void subscribeToArrows(Control& control);
	void subscribeToWASD(Control& control);

	virtual void changePosition() = 0;

protected:
	bool checkTopBorder();
	bool checkBottomBorder();

	std::queue<int> positionNextBall;

	int score = 0;
	int speed = 0;
	int posX = 0;
	int posY = 0;
	int platformWidth = 0;
	int platformHeight = 0;
	int windowWidth = 0;
	int windowHeight = 0;

	Movement movement = Movement::STOP;
};