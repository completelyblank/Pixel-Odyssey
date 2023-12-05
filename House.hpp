#ifndef HOUSE_H
#define HOUSE_H
#include "GameState.hpp"
#include "City.hpp"
#include "Inside.hpp"
using namespace std;
using namespace sf;

class House : public GameState{
public:
    House(StateManager& sm, View& view, int num, float x, float y);
    void handleInput(RenderWindow& window, View& view, Clock& track) override;
    void update(RenderWindow& window, float deltaTime, Clock& track, Event& event, Clock& clock) override;
    void render(RenderWindow& window, Clock& track) override;
    Character& getCharacter() override;
    Tiling& getTile() override;
    bool door();
    void fade(RenderWindow& window, View& view, Clock& track);
private:
    bool startMove;
    Time move;
    View& view;
    int numCoins;
    StateManager& stateManager;
    bool hasTransitioned;
    Character character;
    Tiling tile;
    Character background;
    Bounds bound;
    Inside house;
    Music soundtrack;
    Character lisa;
    bool pressed;
    bool wasPressed;
    bool talk;
    Character pressA;
    Character box;
    Music open;
    Music close;
};

#endif HOUSE_H