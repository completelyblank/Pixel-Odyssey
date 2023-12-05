#include "House.hpp"

#ifdef _WIN32
#define EXECUTABLE_DIRECTORY ""
#else
#define EXECUTABLE_DIRECTORY "./"
#endif

House::House(StateManager& sm, View& view, int num, float x, float y) : stateManager(sm), talk(false), pressed(false), wasPressed(false), numCoins(num), view(view), hasTransitioned(false), startMove(false), move(seconds(5.f)) {
    background.setTexture("Assets/Characters/houseInside.png");
    lisa.setTexture("Assets/Characters/lisa.png");
    lisa.setPosition(1870.f, 1040.f);
    box.setTexture("Assets/Characters/lisadialogue.png");
    box.setPosition(80.f, 260.f);
    pressA.setTexture("Assets/Characters/pressA.png");
    pressA.setPosition(30.f, 600.f);
    character.setTexture("Assets/Characters/charup1.png");
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

bool House::door() {
    if (character.character.getPosition().x > 2170 && character.character.getPosition().x < 2210 && character.character.getPosition().y > 1700) {
        return true;
    }
    return false;
}

void House::handleInput(RenderWindow& window, View& view, Clock& track) {
    bound.set(house);

    if (door() && !hasTransitioned) {
        open.play();
        fade(window, view, track);
        hasTransitioned = true;
        stateManager.changeState(std::make_unique<City>(stateManager, view, numCoins, 840.f, 500.f));
    }

    if (Keyboard::isKeyPressed(Keyboard::A) && talk && !wasPressed) {
        pressed = !pressed;
    }
    wasPressed = Keyboard::isKeyPressed(Keyboard::A);
}

void House::fade(RenderWindow& window, View& view, Clock& track) {
    RectangleShape fadeShape(Vector2f(3250.f, 3250.f));
    for (int alpha = 0; alpha <= 255; alpha += 5) {
        fadeShape.setFillColor(Color(0, 0, 0, alpha));
        window.clear();
        render(window, track);
        window.draw(fadeShape);
        window.display();
    }
}

void House::update(RenderWindow& window, float deltaTime, Clock& track, Event& event, Clock& clock) {
    if (track.getElapsedTime() >= move) {
        startMove = true;
    }
    if (startMove) {
        character.handlemovement(event, deltaTime, track, tile, bound, clock);
    }
    if (character.character.getGlobalBounds().intersects(lisa.character.getGlobalBounds())) {
        talk = true;
    }
    else {
        talk = false;
    }
}

void House::render(RenderWindow& window, Clock& track) {
    window.clear();
    for (auto& i : bound.bound)
    {
        window.draw(i);
    }
    background.draw(window);
    lisa.draw(window);
    character.draw(window);
    View view = window.getView();
    window.setView(window.getDefaultView());
    if (talk && pressed) {
        box.draw(window);
    }
    if (talk && !pressed) {
        pressA.draw(window);
    }
    window.setView(view);
}

Character& House::getCharacter() {
	return character;
}

Tiling& House::getTile() {
	return tile;
}