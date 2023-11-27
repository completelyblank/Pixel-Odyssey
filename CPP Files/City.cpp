#include "City.hpp"

#ifdef _WIN32
#define EXECUTABLE_DIRECTORY ""
#else
#define EXECUTABLE_DIRECTORY "./"
#endif

City::City(StateManager& sm, View& view) : stateManager(sm), view(view), andreasDirection(1), dakotaDirectionY(1), dakotaDirectionX(0), hasTransitioned(false), interval(seconds(0.5f)), flag(1) {
    character.setTexture("Assets/Characters/Character.png");
    npcA.loadFromFile("Assets/Characters/andreasdown1.png");
    npcD.loadFromFile("Assets/Characters/dakotadown1.png");
    path.setTexture("Assets/Characters/path.png");
    path.setPosition(0.f, 0.f);
    andreas.setTexture(npcA);
    dakota.setTexture(npcD);
    andreas.setPosition(270.f, 700.f);
    dakota.setPosition(2250.f, 1170.f);
    character.setPosition(840.f, 500.f);

    tile.setTexture("Assets/Characters/grass.jpg");
    backs.resize(4);

    backs[0].loadFromFile("Assets/Characters/map1.png");
    backs[1].loadFromFile("Assets/Characters/map2.png");
    backs[2].loadFromFile("Assets/Characters/map3.png");
    backs[3].loadFromFile("Assets/Characters/map4.png");
    soundtrack.openFromFile("Assets/Music/City.wav");
    soundtrack.setLoop(true);
    soundtrack.play();
}


bool City::houseDoor1() {
    if (character.character.getPosition().x > 800 && character.character.getPosition().x < 860 && character.character.getPosition().y < 420) {
        return true;
    }
    return false;
}

bool City::arcadeDoor() {
    if (character.character.getPosition().x > 480 && character.character.getPosition().x < 550 && character.character.getPosition().y < 3300 && character.character.getPosition().y > 3000) {
        return true;
    }
    return false;
}

void City::fade(RenderWindow& window, View& view, Clock& track) {
    RectangleShape fadeShape(Vector2f(3250.f, 3950.f));
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

    if (houseDoor1() && !hasTransitioned) {
        Vector2f newViewCenter = character.getPosition();
        view.setCenter(newViewCenter);
        fade(window, view, track);
        stateManager.changeState(std::make_unique<House>(stateManager, view));
        hasTransitioned = true;
    }

    if (arcadeDoor() && !hasTransitioned) {
        Vector2f newViewCenter = character.getPosition();
        view.setCenter(newViewCenter);
        fade(window, view, track);
        stateManager.changeState(std::make_unique<Arcade>(stateManager, view));
        hasTransitioned = true;
    }
}

void City::update(RenderWindow& window, float deltaTime, Clock& track, Event& event, Clock& clock) {
    character.handlemovement(event, deltaTime, track, tile, bound, clock);
    if ((andreas.getGlobalBounds().top + andreas.getGlobalBounds().height) >= 1500.f) {
        andreasDirection = -1;
        npcA.loadFromFile("Assets/Characters/andreasup1.png");
    }
    if (andreas.getGlobalBounds().top <= 750.f) {
        andreasDirection = 1;
        npcA.loadFromFile("Assets/Characters/andreasdown1.png");
    }
    andreas.move(Vector2f(0.f, 150.f * deltaTime * andreasDirection));
    if ((dakota.getGlobalBounds().top + dakota.getGlobalBounds().height) >= 2300.f && dakotaDirectionY == 1) {
        dakotaDirectionX = -1;
        dakotaDirectionY = 0;
        npcD.loadFromFile("Assets/Characters/dakotaleft1.png");
    }
    if ((dakota.getGlobalBounds().left + dakota.getGlobalBounds().width) <= 1200.f && dakotaDirectionX == -1) {
        dakotaDirectionY = -1;
        dakotaDirectionX = 0;
        npcD.loadFromFile("Assets/Characters/dakotaup1.png");
    }
    if (dakota.getGlobalBounds().top <= 1170.f && dakotaDirectionY == -1) {
        dakotaDirectionX = 1;
        dakotaDirectionY = 0;
        npcD.loadFromFile("Assets/Characters/dakotaright1.png");
    }
    if (dakota.getGlobalBounds().left >= 2250.f && dakotaDirectionX == 1) {
        dakotaDirectionY = 1;
        dakotaDirectionX = 0;
        npcD.loadFromFile("Assets/Characters/dakotadown1.png");
    }
    dakota.move(Vector2f(150.f * deltaTime * dakotaDirectionX, 150.f * deltaTime * dakotaDirectionY));
}


void City::render(RenderWindow& window, Clock& track) {
    window.clear();
    
    for (int x = tile.left; x < tile.right; x++)
    {
        for (int y = tile.up; y < tile.down; y++)
        {
            window.draw(tile.tilemap[x][y]);
        }
    }
    if (track.getElapsedTime() >= interval) {
        track.restart();
        background.character.setTexture(backs[flag - 1]);
        flag++;
        if (flag > 4) {
            flag = 1;
        }
        if (flag % 2 == 0) {
            if (andreasDirection == 1) {
                npcA.loadFromFile("Assets/Characters/andreasdown1.png");
            }
            else if (andreasDirection == -1) {
                npcA.loadFromFile("Assets/Characters/andreasup1.png");
            }
        }
        else {
            if (andreasDirection == 1) {
                npcA.loadFromFile("Assets/Characters/andreasdown2.png");
            }
            else if (andreasDirection == -1) {
                npcA.loadFromFile("Assets/Characters/andreasup2.png");
            }
        }
        andreas.setTexture(npcA);
        if (flag % 2 == 0) {
            if (dakotaDirectionY == 1) {
                npcD.loadFromFile("Assets/Characters/dakotadown1.png");
            }
            else if (dakotaDirectionY == -1) {
                npcD.loadFromFile("Assets/Characters/dakotaup1.png");
            }
            else if (dakotaDirectionX == -1) {
                npcD.loadFromFile("Assets/Characters/dakotaleft1.png");
            }
            else if (dakotaDirectionX == 1) {
                npcD.loadFromFile("Assets/Characters/dakotaright1.png");
            }
        }
        else {
            if (dakotaDirectionY == 1) {
                npcD.loadFromFile("Assets/Characters/dakotadown2.png");
            }
            else if (dakotaDirectionY == -1) {
                npcD.loadFromFile("Assets/Characters/dakotaup2.png");
            }
            else if (dakotaDirectionX == -1) {
                npcD.loadFromFile("Assets/Characters/dakotaleft2.png");
            }
            else if (dakotaDirectionX == 1) {
                npcD.loadFromFile("Assets/Characters/dakotaright2.png");
            }
        }
        dakota.setTexture(npcD);
    }
    background.draw(window);
    character.draw(window);
    window.draw(dakota);
    window.draw(andreas);
    path.draw(window);
    for (auto& i : bound.bound)
    {
        window.draw(i);
    }
}

Character& City::getCharacter() {
    return character;
}

Tiling& City::getTile() {
    return tile;
}

City::~City() {
}