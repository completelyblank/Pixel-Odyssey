#include "House2.hpp"

#ifdef _WIN32
#define EXECUTABLE_DIRECTORY ""
#else
#define EXECUTABLE_DIRECTORY "./"
#endif

House2::House2(StateManager& sm, View& view, int num, float x, float y) : stateManager(sm), numCoins(num), view(view), hasTransitioned(false), startMove(false), move(seconds(2.5f)) {
    background.setTexture("Assets/Characters/house2Inside.png");
    character.setTexture( "Assets/Characters/charup1.png");
    character.setPosition(x, y);
    open.openFromFile("Assets/Music/Open.wav");
    close.openFromFile("Assets/Music/Close.wav");
    open.setVolume(50);
    close.setVolume(50);
    close.play();
    soundtrack.openFromFile("Assets/Music/House.wav");
    soundtrack.setLoop(true);
    soundtrack.play();
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
        open.play();
        fade(window, view, track);
        hasTransitioned = true;
        stateManager.changeState(std::make_unique<City>(stateManager, view, numCoins, 1700.f, 500.f));
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
    if (track.getElapsedTime() >= move) {
        startMove = true;
    }
    if (startMove) {
        character.handlemovement(event, deltaTime, track, tile, bound, clock);
    }
}

void House2::render(RenderWindow& window, Clock& track) {
    window.clear();
    for (auto& i : bound.bound)
    {
        window.draw(i);
    }
    
    background.draw(window);
    character.draw(window);
}

Character& House2::getCharacter() {
	return character;
}

Tiling& House2::getTile() {
	return tile;
}
