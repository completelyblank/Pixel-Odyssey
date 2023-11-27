#include "Beach.hpp"

Beach::Beach(StateManager& sm, View& view) : stateManager(sm), view(view), hasTransitioned(false), interval(seconds(1.2f)), flag(2), displayPrompt(false) {
    character.setTexture("Assets/Characters/charright1.png");
    character.setPosition(855.f, 520.f);
    tile.setTexture("Assets/Characters/grass.jpg");
    backs.resize(3);

    backs[0].loadFromFile("Assets/Characters/beach1.png");
    backs[1].loadFromFile("Assets/Characters/beach1.png");
    backs[2].loadFromFile("Assets/Characters/beach1.png");
    soundtrack.openFromFile("Assets/Music/Beach.wav");
    soundtrack.setLoop(true);
    soundtrack.play();
}

bool Beach::door() {
    if (character.character.getPosition().x > 1280 && character.character.getPosition().x < 1320 && character.character.getPosition().y > 940) {
        return true;
    }
    return false;
}

void Beach::fade(RenderWindow& window, View& view, Clock& track)
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

void Beach::handleInput(RenderWindow& window, View& view, Clock& track) {
    tile.updatevals(view.getCenter().x, view.getCenter().y);
    tile.check();
    //bound.set(arcade);
    if (door() && !hasTransitioned) {
        Vector2f newViewCenter = character.getPosition();
        view.setCenter(newViewCenter);
        fade(window, view, track);
        stateManager.changeState(make_unique<City>(stateManager, view));
        hasTransitioned = true;
    }
}

void Beach::update(RenderWindow& window, float deltaTime, Clock& track, Event& event, Clock& clock) {
    character.handlemovement(event, deltaTime, track, tile, bound, clock);
}

void Beach::render(RenderWindow& window, Clock& track) {
    window.clear();
    for (auto& i : bound.bound)
    {
        window.draw(i);
    }
    for (int x = tile.left; x < tile.right; x++) {
        for (int y = tile.up; y < tile.down; y++)
        {
            window.draw(tile.tilemap[x][y]);
        }
    }
    if (track.getElapsedTime() >= interval) {
        track.restart();
        background.character.setTexture(backs[flag - 1]);
        flag++;
        if (flag > 3) {
            flag = 1;
        }
    }
    background.setPosition(100.f, 0.f);
    background.draw(window);
    character.draw(window);
    if (displayPrompt)
    {
        window.draw(promptBox);
    }
}

Character& Beach::getCharacter() {
    return character;
}

Tiling& Beach::getTile() {
    return tile;
}

void Beach::cleanUp()
{
    if (character.character.getGlobalBounds().intersects(trash1.getGlobalBounds()))
    {
        displayPrompt = true;
        if (Keyboard::isKeyPressed(Keyboard::A))
        {
            trashbag.push(trash1);
        }
    }
    if (character.character.getGlobalBounds().intersects(trash2.getGlobalBounds()))
    {
        displayPrompt = true;
        if (Keyboard::isKeyPressed(Keyboard::A))
        {
            trashbag.push(trash2);
        }
    }
    if (character.character.getGlobalBounds().intersects(trash3.getGlobalBounds()))
    {
        displayPrompt = true;
        if (Keyboard::isKeyPressed(Keyboard::A))
        {
            trashbag.push(trash3);
        }
    }
    if (character.character.getGlobalBounds().intersects(trash4.getGlobalBounds()))
    {
        displayPrompt = true;
        if (character.character.getGlobalBounds().intersects(trash4.getGlobalBounds()))
        {
            if (Keyboard::isKeyPressed(Keyboard::A))
            {
                trashbag.push(trash4);
            }
        }
    }
    if (character.character.getGlobalBounds().intersects(trash5.getGlobalBounds()))
    {
        displayPrompt = true;
        if (character.character.getGlobalBounds().intersects(trash5.getGlobalBounds()))
        {
            if (Keyboard::isKeyPressed(Keyboard::A))
            {
                trashbag.push(trash5);
            }
        }
    }
    
}
