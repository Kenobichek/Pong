#include "RenderSystemSDL.h"
#include "ConfigurationHelper.h"
#include <SDL.h>
#include <SDL_image.h>

int RenderSystemSDL::init(Window* window)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        return 1;
    }

    this->window = window;

    IMG_Init(IMG_INIT_JPG);

    SDL_Surface* surface = IMG_Load("images/ball.png");
    ballTexture = SDL_CreateTextureFromSurface(window->getRender(), surface);
    
    surface = IMG_Load("images/platform.png");
    platformTexture = SDL_CreateTextureFromSurface(window->getRender(), surface);

    SDL_FreeSurface(surface);

    auto jsonHelper = ConfigurationHelper::getInstance();
    textSize = jsonHelper->get("textSize");

    return 0;
}

void RenderSystemSDL::renderClear()
{
    SDL_RenderClear(window->getRender());
}

void RenderSystemSDL::renderPresent()
{
    SDL_RenderPresent(window->getRender());
}

void RenderSystemSDL::renderBall(std::shared_ptr<Ball> ball)
{
    ballRect.x = ball->getPosX();
    ballRect.y = ball->getPosY();
    ballRect.w = ball->getSize();
    ballRect.h = ball->getSize();

    SDL_RenderSetViewport(window->getRender(), &ballRect);
    SDL_RenderCopy(window->getRender(), ballTexture, NULL, NULL);
}

void RenderSystemSDL::renderPlayer1(const std::shared_ptr<Player> player)
{
    platformRectPlayer1.x = player->getPosX();
    platformRectPlayer1.y = player->getPosY();
    platformRectPlayer1.h = player->getHeight();
    platformRectPlayer1.w = player->getWidth();

    SDL_RenderSetViewport(window->getRender(), &platformRectPlayer1);
    SDL_RenderCopy(window->getRender(), platformTexture, NULL, NULL);
}

void RenderSystemSDL::renderPlayer2(const std::shared_ptr<Player> player)
{
    platformRectPlayer2.x = player->getPosX();
    platformRectPlayer2.y = player->getPosY();
    platformRectPlayer2.h = player->getHeight();
    platformRectPlayer2.w = player->getWidth();

    SDL_RenderSetViewport(window->getRender(), &platformRectPlayer2);
    SDL_RenderCopy(window->getRender(), platformTexture, NULL, NULL);
}

void RenderSystemSDL::renderScore(const int& player1Score, const int& player2Score)
{
    TTF_Init();

    TTF_Font* Quart = TTF_OpenFont("fonts/VT323.ttf", 24);
    SDL_Color White = { 255, 255, 255 };
    SDL_Surface* surfaceMessage = TTF_RenderText_Solid(Quart, std::to_string(player1Score).c_str(), White);
    SDL_Texture* Message = SDL_CreateTextureFromSurface(window->getRender(), surfaceMessage);

    SDL_RenderSetViewport(window->getRender(), &scoreRectPlayer1);
    SDL_RenderCopy(window->getRender(), Message, NULL, NULL);

    surfaceMessage = TTF_RenderText_Solid(Quart, std::to_string(player2Score).c_str(), White);
    Message = SDL_CreateTextureFromSurface(window->getRender(), surfaceMessage);

    SDL_RenderSetViewport(window->getRender(), &scoreRectPlayer2);
    SDL_RenderCopy(window->getRender(), Message, NULL, NULL);

    scoreRectPlayer1.x = window->getWidth() * 0.25 - (textSize / 2);
    scoreRectPlayer2.x = window->getWidth() * 0.75 - (textSize / 2);

    scoreRectPlayer1.y = window->getHeight() * 0.1;
    scoreRectPlayer2.y = window->getHeight() * 0.1;

    scoreRectPlayer1.h = textSize;
    scoreRectPlayer1.w = textSize;

    scoreRectPlayer2.h = textSize;
    scoreRectPlayer2.w = textSize;

    SDL_FreeSurface(surfaceMessage);
    SDL_DestroyTexture(Message);
}