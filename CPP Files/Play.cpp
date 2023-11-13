#include "Play.hpp"
#include "City.hpp"

#ifdef _WIN32
#define EXECUTABLE_DIRECTORY ""
#else
#define EXECUTABLE_DIRECTORY "./"
#endif

Play::Play(StateManager& sm, View& view) : stateManager(sm), view(view), hasTransitioned(false) , flag(true), interval(seconds(5.f))
{
    background.setTexture("Assets/Characters/wakeup.jpg");
}

void Play::fade(RenderWindow& window, View& view, Clock& track)
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

void Play::handleInput(RenderWindow& window, View& view, Clock& track)
{
    

    if (hasTransitioned) 
    {
        fade(window, view, track);
        stateManager.changeState(std::make_unique<City>(stateManager, view));
        hasTransitioned = true;
    }
}


void Play::update(RenderWindow& window, float deltaTime, Clock& track, Event& event, Clock& clock) 
{
    if (track.getElapsedTime() >= interval)
    {
        track.restart();
        hasTransitioned = true;
    }
}


void Play::render(RenderWindow& window, Clock& track)
{
    background.draw(window);
}

Character& Play::getCharacter() 
{
    return character;
}

Tiling& Play::getTile() 
{
    return tile;
}

