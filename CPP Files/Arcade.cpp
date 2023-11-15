#include "Arcade.hpp"

Arcade::Arcade(StateManager& sm, View& view) : stateManager(sm), view(view), hasTransitioned(false), interval(seconds(1.2f)), flag(2) {
    character.setTexture("Assets/Characters/charup1.png");
    character.setPosition(1300.f, 915.f);
    tile.setTexture("Assets/Characters/arcadetile.png");
    backs.resize(3);  // Resize backs vector to store 4 textures

    backs[0].loadFromFile("Assets/Characters/arcade1.png");
    backs[1].loadFromFile("Assets/Characters/arcade2.png");
    backs[2].loadFromFile("Assets/Characters/arcade3.png");
    soundtrack.openFromFile("Assets/Music/Arcade.wav");
    soundtrack.setLoop(true);
    soundtrack.play();
}

bool Arcade::door() {
    if (character.character.getPosition().x > 1280 && character.character.getPosition().x < 1320 && character.character.getPosition().y > 940) {
        return true;
    }
    return false;
}

void Arcade::fade(RenderWindow& window, View& view, Clock& track) 
{
    RectangleShape fadeShape(Vector2f(3250.f, 3250.f));
    for (int alpha = 0; alpha <= 255; alpha += 5) 
    {
        fadeShape.setFillColor(Color(0, 0, 0, alpha));
        window.clear();
        render(window, track);
        window.draw(fadeShape);
        window.display();
    }
}

void Arcade::handleInput(RenderWindow& window, View& view, Clock& track) {
    
    //bound.set(arcade);
    if (door() && !hasTransitioned) {
        Vector2f newViewCenter = character.getPosition();
        view.setCenter(newViewCenter);
        fade(window, view, track);
        stateManager.changeState(make_unique<City>(stateManager, view));
        hasTransitioned = true;
    }
}

void Arcade::update(RenderWindow& window, float deltaTime, Clock& track, Event& event, Clock& clock) {
    character.handlemovement(event, deltaTime, track, tile, bound, clock);
}

void Arcade::render(RenderWindow& window, Clock& track) {
    window.clear();
    for (auto& i : bound.bound)
    {
        window.draw(i);
    }
    
    if (track.getElapsedTime() >= interval) {
        track.restart();
        background.character.setTexture(backs[flag - 1]);
        flag++;
        if (flag > 3) {
            flag = 1;
        }
    }

    background.draw(window);
    character.draw(window);
}

Character& Arcade::getCharacter() {
    return character;
}

Tiling& Arcade::getTile() {
    return tile;
}