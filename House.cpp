#include "House.hpp"

#ifdef _WIN32
#define EXECUTABLE_DIRECTORY ""
#else
#define EXECUTABLE_DIRECTORY "./"
#endif

House::House(StateManager& sm, View& view) : stateManager(sm), view(view), hasTransitionedToCity(false) {
    background.setTexture("Assets/Characters/test.png");
    //character.setTexture( "Assets/Characters/eupone.png");
    character.setPosition(1250.f, 890.f);
}



bool House::door() {
    if (character.character.getPosition().x > 1200 && character.character.getPosition().x < 1300 && character.character.getPosition().y > 940) {
        return true;
    }
    return false;
}

void House::handleInput(RenderWindow& window, View& view) {
	tile.updatevals(view.getCenter().x, view.getCenter().y);
	tile.check();
    bound.set(house);
}

void House::fade(RenderWindow& window) {
    sf::RectangleShape fadeShape(Vector2f(3250, 3250));
    for (int alpha = 0; alpha <= 255; alpha += 5) {
        fadeShape.setFillColor(Color(0, 0, 0, alpha));
        window.clear();
        render(window);
        window.draw(fadeShape);
        window.display();
    }
}

void House::update(RenderWindow& window, float deltaTime, Clock& track, Event& event, Clock& clock) {
    character.handlemovement(event, deltaTime, track, tile, bound, clock);
    
    
    if (door() && !hasTransitionedToCity) {
        fade(window);
        hasTransitionedToCity = true;
        stateManager.changeState(std::make_unique<City>(stateManager, view));
    }
}

void House::render(RenderWindow& window) {
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
    background.draw(window);
    character.draw(window);
}

Character& House::getCharacter() {
	return character;
}

Tiling& House::getTile() {
	return tile;
}