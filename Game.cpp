#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "Game.hpp"
#include "Arcade.hpp"
#include "House2.hpp"
#include "Intro.hpp"
#include "Beach.hpp"
#include "Fountain.hpp"
#include <filesystem>

#ifdef _WIN32
#define EXECUTABLE_DIRECTORY ""
#else
#define EXECUTABLE_DIRECTORY "./"
#endif


Game::Game() : window(VideoMode(1360, 750), "DS Project"), view(FloatRect(0, 0, 1360, 750)), viewspeed(100.f), playerspeed(200.0f), dt(0) {
    window.setFramerateLimit(60);
    stateManager.pushState(make_unique<Intro>(stateManager, view, 5, 2180.f, 1690.f));
    view.setSize(view.getSize() * 1.5f);
}

void Game::processMouseEvents(Tiling& tile) {
    if (Mouse::isButtonPressed(Mouse::Left)) {
        Vector2f mousePositionWorld = window.mapPixelToCoords(Mouse::getPosition(window), view);
        int tileX = static_cast<int>(mousePositionWorld.x / tile.getgridsize());
        int tileY = static_cast<int>(mousePositionWorld.y / tile.getgridsize());
        cout << "Clicked on tile coordinates: (" << tileX * tile.getgridsize() << ", " << tileY * tile.getgridsize() << ")" << endl;
    }
}


void Game::viewBounds(Character& sprite, Tiling& tile) {
    // adjusting
    view.setCenter(stateManager.getCharacter().getPosition());
    Vector2f viewSize = view.getSize();
    Vector2f mapSize(3600.f, 3600.f);
    Vector2f viewCenter = view.getCenter();
    if (viewCenter.x - viewSize.x / 2.f < 0.f) {
        viewCenter.x = viewSize.x / 2.f;
    }
    if (viewCenter.x + viewSize.x / 2.f > mapSize.x) {
        viewCenter.x = mapSize.x - viewSize.x / 2.f;
    }
    if (viewCenter.y - viewSize.y / 2.f < 0.f) {
        viewCenter.y = viewSize.y / 2.f;
    }
    if (viewCenter.y + viewSize.y / 2.f > mapSize.y) {
        viewCenter.y = mapSize.y - viewSize.y / 2.f;
    }
    view.setCenter(viewCenter);

    // scrolling
    viewspeed = playerspeed * dt;
    float originalview = viewspeed;

    if (Keyboard::isKeyPressed(Keyboard::Space)) {
        viewspeed *= 2;
    }
    else {
        viewspeed = originalview;
    }

    if (sprite.character.getGlobalBounds().top < view.getCenter().y - view.getSize().y / 4)
    {
        if (view.getCenter().y - view.getSize().y / 2 <= 0)
        {
            viewspeed = 0.f;
        }
        view.move(0.f, -viewspeed);
    }

    if (sprite.character.getGlobalBounds().top + sprite.character.getGlobalBounds().height > view.getCenter().y + view.getSize().y / 4)
    {
        if (view.getCenter().y + view.getSize().y / 2 >= tile.getmapsize() * tile.getgridsize())
        {
            viewspeed = 0.f;
        }
        view.move(0.f, viewspeed);
    }

    if (sprite.character.getGlobalBounds().left < view.getCenter().x - view.getSize().x / 4)
    {
        if (view.getCenter().x - view.getSize().x / 2 <= 0)
        {
            viewspeed = 0.f;
        }
        view.move(-viewspeed, 0.f);
    }

    if (sprite.character.getGlobalBounds().left + sprite.character.getGlobalBounds().width > view.getCenter().x + view.getSize().x / 4)
    {
        if (view.getCenter().x + view.getSize().x / 2 >= tile.getgridsize() * tile.getmapsize())
        {
            viewspeed = 0.f;
        }
        view.move(viewspeed, 0.f);
    }
    window.setView(view);
}

void Game::run() {
    while (window.isOpen()) {
        Event event;
        dt = clock.restart().asSeconds();
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
            else if (event.type == Event::MouseMoved) {
                mousePosition = Mouse::getPosition(window);
            }
            
        }

        stateManager.update(window, dt, track1, event, clock);

        window.clear(Color::Black);
        window.setView(view);

        viewBounds(stateManager.getCharacter(), stateManager.getTile());
        processMouseEvents(stateManager.getTile());
        stateManager.handleInput(window, view, track2);
        stateManager.render(window, track2);

        window.display();
    }
}