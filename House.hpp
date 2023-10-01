#ifndef HOUSE
#define HOUSE
#include "GameState.hpp"
#include "City.hpp"
#include "Inside.hpp"
using namespace std;
using namespace sf;

class House : public GameState{
public:
    House(StateManager& sm, View& view);
    void handleInput(RenderWindow& window, View& view) override;
    void update(RenderWindow& window, float deltaTime, Clock& track, Event& event, Clock& clock) override;
    void render(RenderWindow& window) override;
    Character& getCharacter() override;
    Tiling& getTile() override;
    bool door();
    void fade(RenderWindow& window);
private:
    View& view;
    StateManager& stateManager;
    bool hasTransitionedToCity;
    Character character;
    Tiling tile;
    Character background;
    Bounds bound;
    Inside house;
};

#endif SARAH_H