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
    Arcade(StateManager& sm, View& view, int num, float x, float y);
    void fade(RenderWindow& window, View& view, Clock& track);
    void handleInput(RenderWindow& window, View& view, Clock& track) override;
    void update(RenderWindow& window, float deltaTime, Clock& track, Event& event, Clock& clock) override;
    void render(RenderWindow& window, Clock& track) override;
    Character& getCharacter() override;
    Tiling& getTile() override;
    bool door();
    void Sort();
private:
    bool insufficient;
    bool startMove;
    Time move;
    Music open;
    Music close;
    Text coinText;
    Character coin;
    bool sub;
    bool fin;
    int flag;
    bool hasTransitioned;
    Time interval;
    Time interval2;
    Time interval3;
    Time scoreInterval;
    int score;
    bool win;
    Texture scoreboard;
    vector <Text> scores;
    Font font;
    int arrS[5];
    string arrN[5];
    Character pac;
    Texture npcB;
    Sprite byron;
    Texture prompt;
    Sprite pressA;
    Texture dialogueB;
    Texture dialogueA;
    bool wasPressed;
    Sprite gameChar;
    vector <Texture> pacman;
    Sprite box;
    bool talkB;
    bool talkA;
    bool pressed;
    float playerspeed;
    View view;
    Character background;
    vector <Texture> backs;
    vector <Texture> maze;
    StateManager& stateManager;
    Character character;
    vector <Sprite> sprites;
    Sprite mazebox;
    bool play;
    Tiling tile;
    Bounds bound;
    Bounds bound2;
    Maze mazeBounds;
    Coordinates arcade;
    Sprite boi;
    Texture boiText;
    Music soundtrack;
    int numCoins;
};


#endif ARCADE_H