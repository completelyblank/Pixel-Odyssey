#ifndef HOUSE2_H
#define HOUSE2_H
#include "GameState.hpp"
#include "City.hpp"
#include "Inside.hpp"
using namespace std;
using namespace sf;

class House2 : public GameState{
public:
    House2(StateManager& sm, View& view);
    void handleInput(RenderWindow& window, View& view, Clock& track) override;
    void update(RenderWindow& window, float deltaTime, Clock& track, Event& event, Clock& clock) override;
    void render(RenderWindow& window, Clock& track) override;
    Character& getCharacter() override;
    Tiling& getTile() override;
    bool door();
    void fade(RenderWindow& window, View& view, Clock& track);
private:
    View& view;
    StateManager& stateManager;
    bool hasTransitioned;
    Character character;
    Tiling tile;
    Character background;
    Bounds bound;
    Inside house;
};

#endif HOUSE2_H