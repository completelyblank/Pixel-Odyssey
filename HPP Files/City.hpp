#ifndef CITY_H
#define CITY_H
#include "StateManager.hpp"
#include "SFML/Audio.hpp"
#include "Character.hpp"
#include "House.hpp"
#include "Game.hpp"
using namespace std;
using namespace sf;

class City : public GameState {
public:
    City(StateManager& sm, View& view);
    ~City();
    void fade(RenderWindow& window, View& view, Clock& track);
    void handleInput(RenderWindow& window, View& view, Clock& track) override;
    void update(RenderWindow& window, float deltaTime, Clock& track, Event& event, Clock& clock) override;
    void render(RenderWindow& window, Clock& track) override;
    Character& getCharacter() override;
    Tiling& getTile() override;
    bool door();
private:
    int flag;
    Time interval;
    Texture text;
    View view;
    bool hasTransitioned;
    Character character;
    Tiling tile;
    Character test;
    Texture background1;
    Texture sheetText;
    vector <Texture> backs;
    IntRect rectSourceSprite;
    Character background;
    Sprite sprite;
    Character fence;
    Bounds bound;
    Coordinates city;
    StateManager& stateManager;
    Music soundtrack;
};

#endif CITY_H