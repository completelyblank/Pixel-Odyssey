#ifndef MAZE_H
#define MAZE_H
#include <SFML/Graphics.hpp>
#include "StateManager.hpp"
#include "Play.hpp"
#include "GameState.hpp"

using namespace std;
using namespace sf;

class Maze : public GameState {
public:
    Maze(StateManager& sm, View& view);
    void fade(RenderWindow& window, View& view, Clock& track);
    void handleInput(RenderWindow& window, View& view, Clock& track) override;
    void update(RenderWindow& window, float deltaTime, Clock& track, Event& event, Clock& clock) override;
    void render(RenderWindow& window, Clock& track) override;
    Character& getCharacter() override;
    Tiling& getTile() override;
private:
    int flag;
    RectangleShape play;
    RectangleShape controls;
    bool hasTransitioned;
    Time interval;
    Texture text;
    View view;
    Character background;
    StateManager& stateManager;
    Character character;
    Tiling tile;
    Bounds bound;
    Texture ctext;
};


#endif MAZE_H