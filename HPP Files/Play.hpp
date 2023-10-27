#ifndef PLAY_H
#define PLAY_H
#include "GameState.hpp"
#include "StateManager.hpp"

class Play : public GameState {
public:
    Play(StateManager& sm, View& view);
    void fade(RenderWindow& window, View& view, Clock& track);
    void handleInput(RenderWindow& window, View& view, Clock& track) override;
    void update(RenderWindow& window, float deltaTime, Clock& track, Event& event, Clock& clock) override;
    void render(RenderWindow& window, Clock& track) override;
    Character& getCharacter() override;
    Tiling& getTile() override;
  
private:
    View view;
    bool flag;
    Time interval;
    bool hasTransitioned;
    Character character;
    Tiling tile;
    StateManager& stateManager;
    Character background;
};



#endif PLAY_H