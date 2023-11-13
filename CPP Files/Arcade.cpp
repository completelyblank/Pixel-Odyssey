#include "Arcade.hpp"

Arcade::Arcade(StateManager& sm, View& view) : stateManager(sm), view(view), hasTransitioned(false), interval(seconds(0.17f)), flag(2) 
{
    
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

void Arcade::handleInput(RenderWindow& window, View& view, Clock& track) 
{
    if (hasTransitioned) {
        fade(window, view, track);
        stateManager.changeState(std::make_unique<Play>(stateManager, view));
        hasTransitioned = false;

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
    for (int x = tile.left; x < tile.right; x++)
    {
        for (int y = tile.up; y < tile.down; y++)
        {
            window.draw(tile.tilemap[x][y]);
        }
    }
    window.draw(play);
    window.draw(controls);
    background.draw(window);
}

Character& Arcade::getCharacter() {
    return character;
}

Tiling& Arcade::getTile() {
    return tile;
}