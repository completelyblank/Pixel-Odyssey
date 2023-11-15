#ifndef ARCADE_H
#define ARCADE_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "StateManager.hpp"
#include "City.hpp"
#include "GameState.hpp"

using namespace std;
using namespace sf;

class Arcade : public GameState {
public:
    Arcade(StateManager& sm, View& view);
    void fade(RenderWindow& window, View& view, Clock& track);
    void handleInput(RenderWindow& window, View& view, Clock& track) override;
    void update(RenderWindow& window, float deltaTime, Clock& track, Event& event, Clock& clock) override;
    void render(RenderWindow& window, Clock& track) override;
    Character& getCharacter() override;
    Tiling& getTile() override;
    bool door();
private:
    int flag;
    RectangleShape play;
    RectangleShape controls;
    bool hasTransitioned;
    Time interval;
    Texture text;
    View view;
    Character background;
    vector <Texture> backs;
    StateManager& stateManager;
    Character character;
    Tiling tile;
    Bounds bound;
    Texture ctext;
    Music soundtrack;
};


#endif INTRO_H