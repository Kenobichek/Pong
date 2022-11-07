#pragma once
#include <vector>
#include <memory>

#include "Window.h"
#include "Player.h"
#include "Ball.h"
#include "Control.h"
#include "RenderSystem.h"
#include "Event.h"

class Game
{
public:
	Game(std::shared_ptr<RenderSystem> rs);
	void start();

	std::vector<std::shared_ptr<Player>> getPlayers();
	std::vector<std::shared_ptr<Ball>> getBalls();

private:
	void setting(Control& control, const int& numberUsers, const int& numberPlayers, const int& numberBalls);
	void update(Control& control);

	int numberUsers = 0;
	int numberBots = 0;
	int nubmberBalls = 0;
	int windowWidth = 0;
	int windowHeight = 0;

	std::vector<std::shared_ptr<Player>> players;
	std::vector<std::shared_ptr<Ball>> balls;
	std::shared_ptr<RenderSystem> rs;
	
	Window* window = nullptr;
};