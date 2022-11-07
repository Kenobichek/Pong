#pragma once
#include "Window.h"
#include "Ball.h"
#include "Player.h"
#include <memory>

class RenderSystem
{
public:
	virtual int init(Window* window) = 0;
	virtual void renderClear() = 0;
	virtual void renderPresent() = 0;
	virtual void renderBall(const std::shared_ptr<Ball> ball) = 0;
	virtual void renderPlayer1(const std::shared_ptr<Player> player) = 0;
	virtual void renderPlayer2(const std::shared_ptr<Player> player) = 0;
	virtual void renderScore(const int& player1Score, const int& player2Score) = 0;

};