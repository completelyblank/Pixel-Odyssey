#include "City.hpp"

#ifdef _WIN32
#define EXECUTABLE_DIRECTORY ""
#else
#define EXECUTABLE_DIRECTORY "./"
#endif

City::City(StateManager& sm, View& view) : stateManager(sm), view(view), hasTransitioned(false) {
   // houses.setTexture("Assets/Characters/house.png");
    houses.setPosition(0.f, 0.f);
    //fence.setTexture("Assets/Characters/fence.png");
    fence.setPosition(0.f, 550.f);
    character.setTexture("Assets/Characters/detectivedown.png");
    character.setPosition(190.f, 300.f);
    tile.setTexture("Assets/Characters/tile.png");
    test.setTexture("Assets/Characters/main.png");
}


bool City::door() {
    if (character.character.getPosition().x > 140 && character.character.getPosition().x < 250 && character.character.getPosition().y < 300) {
        return true;
    }
    return false;
}

void City::fade(RenderWindow& window, View& view) {
    RectangleShape fadeShape(Vector2f(3250.f, 3250.f));
    for (int alpha = 0; alpha <= 255; alpha += 5) {
        fadeShape.setFillColor(Color(0, 0, 0, alpha));
        window.clear();
        render(window);
        window.draw(fadeShape);
        window.display();
    }
}

void City::handleInput(RenderWindow& window, View& view) {
    tile.updatevals(view.getCenter().x, view.getCenter().y);
    tile.check();
    bound.set(city);

    if (door() && !hasTransitioned) {
        Vector2f newViewCenter = character.getPosition();
        view.setCenter(newViewCenter);
        fade(window, view);
        stateManager.changeState(std::make_unique<House>(stateManager, view));
        hasTransitioned = true;
    }
}


void City::update(RenderWindow& window, float deltaTime, Clock& track, Event& event, Clock& clock) {
    character.handlemovement(event, deltaTime, track, tile, bound, clock);
}


void City::render(RenderWindow& window) {
    window.clear();
    for (auto& i : bound.bound)
    {
        window.draw(i);
    }
    for (int x = tile.left; x < tile.right; x++)
    {
        for (int y = tile.up; y < tile.down; y++)
        {
            window.draw(tile.tilemap[x][y]);
        }
    }
    houses.draw(window);
    test.draw(window);
    character.draw(window);
    fence.draw(window);
}

Character& City::getCharacter() {
    return character;
}

Tiling& City::getTile() {
    return tile;
}

City::~City() {
}