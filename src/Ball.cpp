#include "Ball.h"
#include "ConfigurationHelper.h"

Ball::Ball()
{
    auto jsonHelper = ConfigurationHelper::getInstance();

    windowWidth = jsonHelper->get("windowWidth");
    windowHeight = jsonHelper->get("windowHeight");

    posX = windowWidth / 2;
    posY = windowHeight / 2;

    speed = jsonHelper->get("ballSpeed");
    size = jsonHelper->get("ballSize");

    platformWidth = jsonHelper->get("platformWidth");
    platformHeight = jsonHelper->get("platformHeight");
}

int Ball::getPosX()
{
    return posX;
}

int Ball::getPosY()
{
    return posY;
}

int Ball::getSize()
{
    return size;
}

void Ball::startMovement()
{
    direction.randomizeDirection();
    direction.setX(-1);
}

void Ball::changePosition(std::vector<std::shared_ptr<Player>> players)
{
    if (checkPlayer1Collision(players[0]))
    {
        bounceOffPlatform(players[0]);
        int positionNextBall = findPositionNextBall();
        addPositionNextBall(players, positionNextBall);
    }
    if (checkPlayer2Collision(players[1]))
    {
        bounceOffPlatform(players[1]);
        int positionNextBall = findPositionNextBall();
        addPositionNextBall(players, positionNextBall);
    }
    if (checkWallCollision())
    {
        direction.setY(-direction.getY());
        int positionNextBall = findPositionNextBall();
        addPositionNextBall(players, positionNextBall);
    }
    if (checkOutBounds())
    {
        if (checkOutBoundsForFlayer1())
        {
            players[1]->addScore();
        }
        if (checkOutBoundsForFlayer2())
        {
            players[0]->addScore();
        }

        direction.setX(0);
        direction.setY(0);
        posX = windowWidth / 2;
        posY = windowHeight / 2;
    }

    posX += int(speed * direction.getX());
    posY += int(speed * direction.getY());
}

bool Ball::checkWallCollision()
{
    return posY <= 0 || posY + size >= windowHeight;
}

bool Ball::checkPlayer1Collision(std::shared_ptr<Player> player1)
{
    return player1->getTop() <= posY &&
           player1->getBottom() >= posY &&
           posX <= platformWidth;
}

bool Ball::checkPlayer2Collision(std::shared_ptr<Player> player2)
{
    return player2->getTop() <= posY &&
           player2->getBottom() >= posY &&
           posX + platformWidth >= windowWidth - platformWidth;
}

bool Ball::checkOutBounds()
{
    return posX <= 0 || posX >= windowWidth;
}

bool Ball::checkOutBoundsForFlayer1()
{
    return posX <= 0;
}

bool Ball::checkOutBoundsForFlayer2()
{
    return posX >= windowWidth;
}

int Ball::findPositionNextBall()
{
    int positionNextBallX = posX;
    int positionNextBallY = posY;

    while (positionNextBallX > 0 && positionNextBallX <= windowWidth)
    {
        positionNextBallX += int(speed * direction.getX());
        positionNextBallY += int(speed * direction.getY());
    }
    return positionNextBallY;
}

void Ball::subscribeToSpace(Control& control)
{
    control.addEventListener("SPACE", [&](std::shared_ptr<Event> e)
        {
            if(direction.getX() == 0 && direction.getY() == 0)
            {
                startMovement();
            }
        }
    );
}

void Ball::addPositionNextBall(std::vector<std::shared_ptr<Player>> players, const int& positionNextBall)
{
    for (int i = 0; i < players.size(); i++)
    {
        players[i]->addPositionNextBall(positionNextBall);
    }
}

void Ball::bounceOffPlatform(std::shared_ptr<Player> player)
{
    direction.setX(-direction.getX());
    Movement movement = player->getMovement();
    if (movement == Movement::DOWN)
    {
        double y = abs(direction.getY());
        direction.setY(y + collisionFactor);
    }

    if (movement == Movement::UP)
    {
        double y = abs(direction.getY());
        direction.setY(y - collisionFactor);
    }
}
