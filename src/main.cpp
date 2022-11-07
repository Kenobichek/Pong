#include <iostream>
#include <fstream>

#include "Window.h"
#include "RenderSystemSDL.h"
#include "Game.h"
#include "ConfigurationHelper.h"

int main(int argc, char** args) 
{
    try
    {
        auto jsonHelper = ConfigurationHelper::getInstance();
        int windowWidth = jsonHelper->get("windowWidth");
        int windowHeight = jsonHelper->get("windowHeight");

        Window window("Pong", windowWidth, windowHeight);

        std::shared_ptr<RenderSystem> rs = std::make_shared<RenderSystemSDL>();
        rs->init(&window);

        Game game(rs);
        game.start();
    }
    catch (const char* str)
    {
        std::cout << "Exception: " << str << "\n";
    }

    return 0;
};
