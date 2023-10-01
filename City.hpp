#ifndef CITY_H
#define CITY_H
#include "StateManager.hpp"
#include "Character.hpp"
#include "House.hpp"
#include "Game.hpp"
using namespace std;
using namespace sf;

class City : public GameState {
public:
    City(StateManager& sm, View& view);
    ~City();
    void fade(RenderWindow& window, View& view);
    void handleInput(RenderWindow& window, View& view) override;
    void update(RenderWindow& window, float deltaTime, Clock& track, Event& event, Clock& clock) override;
    void render(RenderWindow& window) override;
    Character& getCharacter() override;
    Tiling& getTile() override;
    bool door();
private:
    View view;
    bool hasTransitioned;
    Character character;
    Tiling tile;
    Character test;
    Character houses;
    Character fence;
    Bounds bound;
    Coordinates city;
    StateManager& stateManager;
};

#endif CITY_H