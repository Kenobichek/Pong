#include "Window.h"
#include <SDL_image.h>
#include <iostream>

Window::Window(const std::string& title, uint32_t width, uint32_t height)
{
    this->width = width;
    this->height = height;

    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);

    surface = SDL_GetWindowSurface(window);

    render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (render == nullptr) {
        throw "Can't create renderer";
    }

    SDL_SetRenderDrawColor(render, 0x00, 0x00, 0x00, 0x00);
}

Window::~Window()
{
    SDL_FreeSurface(surface);
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(render);
    SDL_Quit();
}

SDL_Window* Window::getWindow()
{
    return window;
}

SDL_Surface* Window::getSurface()
{
    return surface;
}

SDL_Renderer* Window::getRender()
{
    return render;
}

uint32_t Window::getWidth()
{
    return width;
}

uint32_t Window::getHeight()
{
    return height;
}
