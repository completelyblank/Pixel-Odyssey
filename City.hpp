#ifndef CITY_H
#define CITY_H
#include "StateManager.hpp"
#include "SFML/Audio.hpp"
#include "Character.hpp"
#include "House.hpp"
#include "Arcade.hpp"
#include "Game.hpp"
#include "CityCoordinates.hpp"
#include "Fountain.hpp"
#include "Park.hpp"
#include "Beach.hpp"
using namespace std;
using namespace sf;

class City : public GameState {
public:
    City(StateManager& sm, View& view, int num, float x, float y);
    ~City();
    void fade(RenderWindow& window, View& view, Clock& track);
    void handleInput(RenderWindow& window, View& view, Clock& track) override;
    void update(RenderWindow& window, float deltaTime, Clock& track, Event& event, Clock& clock) override;
    void render(RenderWindow& window, Clock& track) override;
    Character& getCharacter() override;
    Tiling& getTile() override;
    bool houseDoor1();
    bool arcadeDoor();
    bool beachdoor();
    bool fount();
    bool parkdoor();
    bool houseDoor2();
    bool houseDoor3();
private:
    Character box;
    bool insufficient;
    Character pressA;
    Time move;
    bool startMove;
    bool wasPressed;
    bool fountain;
    bool talkD;
    bool pressed;
    Time interval2;
    bool flag2;
    int numCoins;
    int flag;
    Time interval;
    Texture text;
    View view;
    Character coin;
    Text coinText;
    Font font;
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
    vector <Sprite> sprites;
    Music open;
    Music close;
};

#endif CITY_H