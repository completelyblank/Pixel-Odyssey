#ifndef PARK_H
#define PARK_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "StateManager.hpp"
#include "City.hpp"
#include "GameState.hpp"

using namespace std;
using namespace sf;

class Park : public GameState {
public:
    Park(StateManager& sm, View& view, int num, float x, float y);
    void fade(RenderWindow& window, View& view, Clock& track);
    void handleInput(RenderWindow& window, View& view, Clock& track) override;
    void update(RenderWindow& window, float deltaTime, Clock& track, Event& event, Clock& clock) override;
    void render(RenderWindow& window, Clock& track) override;
    Character& getCharacter() override;
    Tiling& getTile() override;
    bool door();
private:
    Character top;
    bool startMove;
    Time move;
    int numCoins;
    int add;
    Character coin;
    Text coinText;
    Font font;
    int flag;
    bool hasTransitioned;
    Time interval;
    Texture grave;
    Sprite stoneA;
    Sprite stoneB;
    Sprite stoneC;
    Texture prompt;
    Sprite pressA;
    Texture dialogueA;
    Texture dialogueB;
    Texture dialogueC;
    bool talkM;
    Texture dialogueM;
    bool wasPressed;
    Sprite box;
    bool talkA;
    bool talkB;
    bool talkC;
    bool pressed;
    View view;
    Character background;
    vector <Texture> backs;
    StateManager& stateManager;
    Character character;
    Bounds bound;
    ParkCoordinates park;
    Music soundtrack;
    Tiling tile;
};


#endif PARK_H