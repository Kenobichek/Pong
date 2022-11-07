#include "Bot.h"

void Bot::changePosition()
{
	int centerPlatform = platformHeight / 2;
	if (!positionNextBall.empty())
	{
		int rightPlace = positionNextBall.front();
		if (rightPlace > posY + centerPlatform)
		{
			posY += speed;
			movement = Movement::UP;
			if (rightPlace <= posY + centerPlatform)
			{
				positionNextBall.pop();
			}
		}
		else if (rightPlace < posY + centerPlatform)
		{
			posY -= speed;
			movement = Movement::DOWN;
			if (rightPlace >= posY + centerPlatform)
			{
				positionNextBall.pop();
			}
		}
		else
		{
			positionNextBall.pop();
		}
	}
	else
	{
		movement = Movement::STOP;
	}
	if (checkTopBorder())
	{
		posY = 0;
		if (!positionNextBall.empty()) positionNextBall.pop();
	}
	if (checkBottomBorder())
	{
		posY = windowHeight - platformHeight;
		if (!positionNextBall.empty()) positionNextBall.pop();
	}
}
