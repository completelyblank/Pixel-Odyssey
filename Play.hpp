#ifndef PLAY_H
#define PLAY_H
#include "GameState.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "StateManager.hpp"

class Play : public GameState {
public:
    Play(StateManager& sm, View& view, int num, float x, float y);
    void fade(RenderWindow& window, View& view, Clock& track);
    void handleInput(RenderWindow& window, View& view, Clock& track) override;
    void update(RenderWindow& window, float deltaTime, Clock& track, Event& event, Clock& clock) override;
    void render(RenderWindow& window, Clock& track) override;
    Character& getCharacter() override;
    Tiling& getTile() override;
  
private:
    Music soundtrack;
    int numCoins;
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