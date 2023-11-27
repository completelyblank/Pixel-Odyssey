#ifndef BEACH_H
#define BEACH_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "StateManager.hpp"
#include "City.hpp"
#include "GameState.hpp"
#include <queue>

using namespace std;
using namespace sf;

class Beach : public GameState {
public:
    Beach(StateManager& sm, View& view);
    void fade(RenderWindow& window, View& view, Clock& track);
    void handleInput(RenderWindow& window, View& view, Clock& track) override;
    void update(RenderWindow& window, float deltaTime, Clock& track, Event& event, Clock& clock) override;
    void render(RenderWindow& window, Clock& track) override;
    Character& getCharacter() override;
    Tiling& getTile() override;
    bool door();
    void cleanUp();
private:
    int flag;
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
    Sprite trash1;
    Sprite trash2;
    Sprite trash3;
    Sprite trash4;
    Sprite trash5;
    queue <Sprite> trashbag;
    Texture prompt;
    Sprite promptBox;
    bool displayPrompt;
};


#endif BEACH_H
