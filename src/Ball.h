#pragma once
#include "Window.h"
#include "Direction.h"
#include "Player.h"

#include <string>
#include <memory>
#include <vector>

class Ball
{
public:
	Ball();
	void startMovement();
	void changePosition(std::vector<std::shared_ptr<Player>> players);
	void subscribeToSpace(Control& control);
	int findPositionNextBall();
	int getPosX();
	int getPosY();
	int getSize();

private:
	bool checkWallCollision();
	bool checkPlayer1Collision(std::shared_ptr<Player> player1);
	bool checkPlayer2Collision(std::shared_ptr<Player> player2);
	bool checkOutBounds();
	bool checkOutBoundsForFlayer1();
	bool checkOutBoundsForFlayer2();
	void addPositionNextBall(std::vector<std::shared_ptr<Player>> players, const int& positionNextBall);
	void bounceOffPlatform(std::shared_ptr<Player>);

	Direction direction;

	int speed = 0;
	int size = 0;
	int posX = 0;
	int posY = 0;
	int windowWidth = 0;
	int windowHeight = 0;
	int platformWidth = 0;
	int platformHeight = 0;
	double collisionFactor = 0.5;
};