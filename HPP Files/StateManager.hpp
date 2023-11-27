#ifndef STATE_H
#define STATE_H
#include "GameState.hpp"
#include <stack>
#include <memory>
using namespace std;
using namespace sf;

class StateManager {
public:
    StateManager();
    void pushState(unique_ptr<GameState> state);
    void popState();
    void changeState(unique_ptr<GameState> state);
    void updateView(RenderWindow& window);
    void handleInput(RenderWindow& window, View& view, Clock& track);
    void update(RenderWindow& window, float deltaTime, Clock& track, Event& event, Clock& clock);
    void render(RenderWindow& window, Clock& track);
    Character& getCharacter();
    Tiling& getTile();
private:
    stack<unique_ptr<GameState>> states;
};

#endif STATE_H
