#ifndef INTRO_H
#define INTRO_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "StateManager.hpp"
#include "Play.hpp"
#include "GameState.hpp"

using namespace std;
using namespace sf;

class Intro : public GameState {
public: 
	Intro(StateManager& sm, View& view, int num, float x, float y);
    void fade(RenderWindow& window, View& view, Clock& track);
    void handleInput(RenderWindow& window, View& view, Clock& track) override;
    void update(RenderWindow& window, float deltaTime, Clock& track, Event& event, Clock& clock) override;
    void render(RenderWindow& window, Clock& track) override;
    Character& getCharacter() override;
    Tiling& getTile() override;
private:
    int numCoins;
    int flag;
    RectangleShape play;
    RectangleShape controls;
    bool hasTransitioned;
    Time interval;
    Character controlWindow;
    vector <Texture> backs;
    int flag2;
    Texture text;
    View view;
    Character background;
    StateManager& stateManager;
    Character character;
    Tiling tile;
    Cursor cursor;
    Cursor::Type p;
    Texture ctext;
    Music soundtrack;
    bool renderC;
};


#endif INTRO_H