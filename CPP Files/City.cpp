#include "City.hpp"

#ifdef _WIN32
#define EXECUTABLE_DIRECTORY ""
#else
#define EXECUTABLE_DIRECTORY "./"
#endif

City::City(StateManager& sm, View& view) : stateManager(sm), view(view), hasTransitioned(false), interval(seconds(0.5f)), flag(1) {
    background.setTexture("Assets/Characters/map.png");
    background.setPosition(0.f, 0.f);
    character.setTexture("Assets/Characters/Character.png");
    character.setPosition(840.f, 500.f);
    tile.setTexture("Assets/Characters/grass.jpg");
    background1.loadFromFile("Assets/Characters/map1.png");
    background2.loadFromFile("Assets/Characters/map2.png");
    background3.loadFromFile("Assets/Characters/map3.png");
    background4.loadFromFile("Assets/Characters/map4.png");
    soundtrack.openFromFile("Assets/Music/Arcade.wav");
    soundtrack.setLoop(true);
    soundtrack.play();
}


bool City::door() {
    if (character.character.getPosition().x > 140 && character.character.getPosition().x < 250 && character.character.getPosition().y < 300) {
        return true;
    }
    return false;
}

void City::fade(RenderWindow& window, View& view, Clock& track) {
    RectangleShape fadeShape(Vector2f(3250.f, 3250.f));
    for (int alpha = 0; alpha <= 255; alpha += 5) {
        fadeShape.setFillColor(Color(0, 0, 0, alpha));
        window.clear();
        render(window, track);
        window.draw(fadeShape);
        window.display();
    }
}

void City::handleInput(RenderWindow& window, View& view, Clock& track) {
    tile.updatevals(view.getCenter().x, view.getCenter().y);
    tile.check();
    bound.set(city);

    if (door() && !hasTransitioned) {
        Vector2f newViewCenter = character.getPosition();
        view.setCenter(newViewCenter);
        fade(window, view, track);
        stateManager.changeState(std::make_unique<House>(stateManager, view));
        hasTransitioned = true;
    }
}

void City::update(RenderWindow& window, float deltaTime, Clock& track, Event& event, Clock& clock) {
    character.handlemovement(event, deltaTime, track, tile, bound, clock);
}


void City::render(RenderWindow& window, Clock& track) {
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

    if (track.getElapsedTime() >= interval) {
        track.restart();
        flag++;
        if (flag > 4) {
            flag = 1;
        }
        if (flag == 1) {
            background.character.setTexture(background1);
        }
        else if (flag == 2) {
            background.character.setTexture(background2);
        }
        else if (flag == 3) {
            background.character.setTexture(background3);
        }
        else if (flag == 4) {
            background.character.setTexture(background4);
        }
    }

    background.draw(window);
    character.draw(window);
}

Character& City::getCharacter() {
    return character;
}

Tiling& City::getTile() {
    return tile;
}

City::~City() {
}