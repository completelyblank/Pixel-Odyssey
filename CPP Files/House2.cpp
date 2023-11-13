#include "House2.hpp"

#ifdef _WIN32
#define EXECUTABLE_DIRECTORY ""
#else
#define EXECUTABLE_DIRECTORY "./"
#endif

House2::House2(StateManager& sm, View& view) : stateManager(sm), view(view), hasTransitioned(false) {
    background.setTexture("Assets/Characters/houseInside.png");
    character.setTexture( "Assets/Characters/charup1.png");
    character.setPosition(2180.f, 1690.f);
}

bool House2::door() {
    if (character.character.getPosition().x > 2170 && character.character.getPosition().x < 2210 && character.character.getPosition().y > 1700) {
        return true;
    }
    return false;
}

void House2::handleInput(RenderWindow& window, View& view, Clock& track) {
    bound.set(house);

    if (door() && !hasTransitioned) {
        fade(window, view, track);
        hasTransitioned = true;
        stateManager.changeState(std::make_unique<City>(stateManager, view));
    }
}

void House2::fade(RenderWindow& window, View& view, Clock& track) {
    RectangleShape fadeShape(Vector2f(3250.f, 3250.f));
    for (int alpha = 0; alpha <= 255; alpha += 5) {
        fadeShape.setFillColor(Color(0, 0, 0, alpha));
        window.clear();
        render(window, track);
        window.draw(fadeShape);
        window.display();
    }
}

void House2::update(RenderWindow& window, float deltaTime, Clock& track, Event& event, Clock& clock) {
    character.handlemovement(event, deltaTime, track, tile, bound, clock);
}

void House2::render(RenderWindow& window, Clock& track) {
    window.clear();
    /*for (auto& i : bound.bound)
    {
        window.draw(i);
    }*/
    
    background.draw(window);
    character.draw(window);
}

Character& House2::getCharacter() {
	return character;
}

Tiling& House2::getTile() {
	return tile;
}
