#ifndef GAME_H
#define GAME_H
#include "City.hpp"
#include "StateManager.hpp"
#include "GameState.hpp"
#include <vector>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

class Game {
public: 
	Game();
	void processMouseEvents(Tiling& tile);
	void run();
	void viewBounds(Character& sprite, Tiling& tile);

private:
	RenderWindow window;
	Clock clock;
	Clock track;
	View view;
	Vector2i mousePosition;
	float dt;
	float playerspeed;
	float viewspeed;
	StateManager stateManager;
};

#endif GAME_H