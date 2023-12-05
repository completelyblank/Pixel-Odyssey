#ifndef BEACH_H
#define BEACH_H
#include <SFML/Graphics.hpp>
#include <queue>
#include <SFML/Audio.hpp>
#include "StateManager.hpp"
#include "City.hpp"
#include "GameState.hpp"
#include "BeachCoordinates.hpp"

using namespace std;
using namespace sf;

class Beach : public GameState {
public:
    Beach(StateManager& sm, View& view, int num, float x, float y);
    void fade(RenderWindow& window, View& view, Clock& track);
    void handleInput(RenderWindow& window, View& view, Clock& track) override;
    void update(RenderWindow& window, float deltaTime, Clock& track, Event& event, Clock& clock) override;
    void render(RenderWindow& window, Clock& track) override;
    Character& getCharacter() override;
    Tiling& getTile() override;
    bool door();
private:
    bool startMove;
    Time move;
    int numCoins;
    Character trash1;
    Character trash2;
    Character trash3;
    Character trash4;
    Character trash5;
    int flag;
    bool hasTransitioned;
    Time interval;
    Texture text;
    View view;
    bool t1;
    bool t2;
    bool t3;
    bool t4;
    bool t5;
    int i, j, k, a, b;
    int index;
    bool pick;
    Character prompt;
    bool talk;
    bool pressed;
    bool wasPressed;
    Character dialogue;
    Character pressA;
    Character francis;
    bool empty;
    vector <Sprite> garbage;
    queue <String> trashQueue;
    int space;
    queue <String> copy;
    Character background;
    Text names;
    Font font;
    vector <Texture> backs;
    StateManager& stateManager;
    Character character;
    Tiling tile;
    Bounds bound;
    Texture ctext;
    Music soundtrack;
    Music waves;
    BeachCoordinates beach;
    Texture can;
    Sprite trashCan;
};


#endif BEACH_H