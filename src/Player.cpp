#include "Player.h"
#include "ConfigurationHelper.h"

Player::Player()
{
    auto jsonHelper = ConfigurationHelper::getInstance();

    windowWidth = jsonHelper->get("windowWidth");
    windowHeight = jsonHelper->get("windowHeight");

    platformWidth = jsonHelper->get("platformWidth");
    platformHeight = jsonHelper->get("platformHeight");

    posX = 0;
    posY = windowHeight / 2;

    speed = jsonHelper->get("platformSpeed");
}


void Player::setPosition(const int& x, const int& y)
{
    posX = x;
    posY = y;
}

void Player::setPosition(const int& y)
{
    posY = y;
}

int Player::getPosX()
{
    return posX;
}

int Player::getPosY()
{
    return posY;
}

int Player::getTop()
{
    return posY;
}

int Player::getWidth()
{
    return platformWidth;
}

int Player::getHeight()
{
    return platformHeight;
}

int Player::getBottom()
{
    return posY + platformHeight;
}

int Player::getScore()
{
    return score;
}

Movement Player::getMovement()
{
    return movement;
}

void Player::addScore()
{
    score += 1;
}

void Player::addPositionNextBall(const int& y)
{
    positionNextBall.push(y);
}

void Player::subscribeToArrows(Control& control)
{
    control.addEventListener("UP", [&](std::shared_ptr<Event> e)
        {
            posY -= speed;
            movement = Movement::UP;
        }
    );
    control.addEventListener("DOWN", [&](std::shared_ptr<Event> e)
        {
            posY += speed;
            movement = Movement::DOWN;
        }
    );
}

void Player::subscribeToWASD(Control& control)
{
    control.addEventListener("W", [&](std::shared_ptr<Event> e)
        {
            posY -= speed;
            movement = Movement::UP;
        }
    );
    control.addEventListener("S", [&](std::shared_ptr<Event> e)
        {
            posY += speed;
            movement = Movement::DOWN;
        }
    );
}

bool Player::checkTopBorder()
{
    return posY <= 0;
}

bool Player::checkBottomBorder() 
{
    return posY >= windowHeight - platformHeight;
}
