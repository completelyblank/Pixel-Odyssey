#ifndef CITY_H
#define CITY_H
#include "StateManager.hpp"
#include "SFML/Audio.hpp"
#include "Character.hpp"
#include "House.hpp"
#include "Arcade.hpp"
#include "Game.hpp"
#include "CityCoordinates.hpp"
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
    bool houseDoor1();
    bool arcadeDoor();
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
    vector <Texture> backs;
    Character background;
    Character path;
    Sprite sprite;
    Texture npcD;
    Texture npcA;
    int andreasDirection;
    int dakotaDirectionX;
    int dakotaDirectionY;
    Character fence;
    Bounds bound;
    CityCoordinates city;
    StateManager& stateManager;
    Music soundtrack;
    Sprite andreas;
    Sprite dakota;
};

#endif CITY_H