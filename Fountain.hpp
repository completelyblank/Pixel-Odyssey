#ifndef FOUNTAIN_H
#define FOUNTAIN_H
#include "StateManager.hpp"
#include "SFML/Audio.hpp"
#include "Character.hpp"
#include "House.hpp"
#include "Arcade.hpp"
#include "List.hpp"
using namespace std;
using namespace sf;

class Fountain : public GameState {
public:
    Fountain(StateManager& sm, View& view, int num, float x, float y);
    void fade(RenderWindow& window, View& view, Clock& track);
    void handleInput(RenderWindow& window, View& view, Clock& track) override;
    void update(RenderWindow& window, float deltaTime, Clock& track, Event& event, Clock& clock) override;
    void render(RenderWindow& window, Clock& track) override;
    Character& getCharacter() override;
    Tiling& getTile() override;
private:
    bool wasPressed;
    int numCoins;
    Text joke;
    Text fact;
    Text press;
    int flag;
    Time interval;
    Texture text;
    View view;
    Character coin;
    Text coinText;
    Font font;
    bool hasTransitioned;
    Character background;
    Character character;
    Tiling tile;
    vector <Texture> backs;
    Sprite sprite;
    Character fence;
    Bounds bound;
    StateManager& stateManager;
    Music soundtrack;
    Music select;
    bool j, f;
    bool pressed;
    Text display;

    // tree
    DecisionTreeNode* root;
};

#endif FOUNTAIN_H