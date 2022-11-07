#include "Game.h"
#include "User.h"
#include "Bot.h"
#include "ConfigurationHelper.h"
#include "EventSDLAdapter.h"

Game::Game(std::shared_ptr<RenderSystem> rs)
{
    this->rs = rs;

    auto jsonHelper = ConfigurationHelper::getInstance();

    windowWidth = jsonHelper->get("windowWidth");
    windowHeight = jsonHelper->get("windowHeight");

    numberUsers = jsonHelper->get("numberUsers");
    numberBots = jsonHelper->get("numberBots");
    nubmberBalls = jsonHelper->get("numberBalls");
}

void Game::start()
{
    Control control;
    setting(control, numberUsers, numberBots, nubmberBalls);
    update(control);
}

void Game::setting(Control& control, const int& numberUsers, const int& numberBots, const int& numberBalls)
{
    if (numberUsers + numberBots > 2)
    {
        throw "More than two players";
    }
    if (numberUsers + numberBots < 2)
    {
        throw "Less than two players";
    }
    if (numberBalls < 1)
    {
        throw "Not enough balls";
    }
    if (numberBalls > 5)
    {
        throw "A lot of balls";
    }

    for (int i = 0; i < numberUsers; i++)
    {
        players.push_back(std::make_shared<User>());
    }
    for (int i = 0; i < numberBots; i++)
    {
        players.push_back(std::make_shared<Bot>());
    }
    for (int i = 0; i < numberBalls; i++)
    {
        balls.push_back(std::make_shared<Ball>());
        balls[i]->subscribeToSpace(control);
    }


    players[0]->setPosition(0, windowHeight / 2);
    players[0]->subscribeToArrows(control);

    players[1]->setPosition(windowWidth - players[1]->getWidth(), windowHeight / 2);
    players[1]->subscribeToWASD(control);
}

void Game::update(Control& control)
{
    std::shared_ptr<Event> e = std::make_shared<EventSDLAdapter>();

    bool run = true;
    control.addEventListener("QUIT", [&](std::shared_ptr<Event> e) {run = false; });

    while (run) 
    {
        if (e->pollEvent())
        {
            control.processEvent(e);
        }

        rs->renderClear();

        for (int i = 0; i < numberBots + numberUsers; i++) {
            players[i]->changePosition();
        }

        rs->renderPlayer1(players[0]);
        rs->renderPlayer2(players[1]);
        rs->renderScore(players[0]->getScore(), players[1]->getScore());

        for (int i = 0; i < nubmberBalls; i++) {
            balls[i]->changePosition(players);
            rs->renderBall(balls[i]);
        }

        rs->renderPresent();
    }
}

std::vector<std::shared_ptr<Player>> Game::getPlayers()
{
    return players;
}

std::vector<std::shared_ptr<Ball>> Game::getBalls()
{
    return balls;
}
