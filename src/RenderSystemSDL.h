#include "RenderSystem.h"

class RenderSystemSDL : public RenderSystem
{
public:
	int init(Window* window);
	void renderClear();
	void renderPresent();
	void renderBall(const std::shared_ptr<Ball> ball);
	void renderPlayer1(const std::shared_ptr<Player> player);
	void renderPlayer2(const std::shared_ptr<Player> player);
	void renderScore(const int& player1Score, const int& player2Score);

private:
	Window* window = nullptr;

	SDL_Rect ballRect = { 0, 0, 0, 0 };
	SDL_Rect platformRectPlayer1 = { 0, 0, 0, 0 };
	SDL_Rect platformRectPlayer2 = { 0, 0, 0, 0 };
	SDL_Rect scoreRectPlayer1 = { 0, 0, 0, 0 };
	SDL_Rect scoreRectPlayer2 = { 0, 0, 0, 0 };

	SDL_Texture* ballTexture = nullptr;
	SDL_Texture* platformTexture = nullptr;

	int textSize = 0;
};