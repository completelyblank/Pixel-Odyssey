#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "Character.hpp"
#include <SFML/Graphics.hpp>
using namespace sf;

class GameState {
public:
    virtual void handleInput(RenderWindow& window, View& view) = 0;
    virtual void update(sf::RenderWindow& window, float deltaTime, Clock& track, Event& event, Clock& clock) = 0;
    virtual void render(RenderWindow& window) = 0;
    virtual ~GameState() = default;
    virtual Character& getCharacter() = 0;
    virtual Tiling& getTile() = 0;
};

#endif // GAME_STATE_H
