#pragma once
#include <SDL.h>
#include <string>

class Window {
public:
	Window(const std::string& title, uint32_t width, uint32_t height);
	~Window();
	SDL_Window* getWindow();
	SDL_Surface* getSurface();
	SDL_Renderer* getRender();
	uint32_t getWidth();
	uint32_t getHeight();

private:
	SDL_Window* window = nullptr;
	SDL_Surface* surface = nullptr;
	SDL_Renderer* render = nullptr;
	int width = 0;
	int height = 0;
};