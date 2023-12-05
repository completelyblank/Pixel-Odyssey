#include "City.hpp"

#ifdef _WIN32
#define EXECUTABLE_DIRECTORY ""
#else
#define EXECUTABLE_DIRECTORY "./"
#endif

City::City(StateManager& sm, View& view, int num, float x, float y) : stateManager(sm), numCoins(num), insufficient(false), startMove(false), view(view), andreasDirection(1), dakotaDirectionY(1), dakotaDirectionX(0), hasTransitioned(false), interval(seconds(0.5f)), interval2(seconds(0.5f)), flag(1), flag2(1), move(seconds(4.8f)), fountain(false), talkD(false), pressed(false), wasPressed(false) {
    character.setTexture("Assets/Characters/Character.png");
    npcA.loadFromFile("Assets/Characters/andreasdown1.png");
    npcD.loadFromFile("Assets/Characters/dakotadown1.png");
    pressA.setPosition(30.f, 600.f);
    box.setPosition(80.f, 260.f);
    path.setTexture("Assets/Characters/path.png");
    path.setPosition(0.f, 0.f);
    andreas.setTexture(npcA);
    dakota.setTexture(npcD);
    andreas.setPosition(270.f, 700.f);
    dakota.setPosition(1080.f, 2160.f);
    character.setPosition(x, y);
    sprites.resize(2);
    tile.setTexture("Assets/Characters/grass.jpg");
    backs.resize(4);
    backs[0].loadFromFile("Assets/Characters/map1.png");
    backs[1].loadFromFile("Assets/Characters/map2.png");
    backs[2].loadFromFile("Assets/Characters/map3.png");
    backs[3].loadFromFile("Assets/Characters/map4.png");
    open.openFromFile("Assets/Music/Open.wav");
    close.openFromFile("Assets/Music/Close.wav");
    open.setVolume(50);
    close.setVolume(50);
    close.play();
    soundtrack.openFromFile("Assets/Music/City.wav");
    soundtrack.setLoop(true);
    soundtrack.play();
    coin.setTexture("Assets/Characters/coins.png");
    coin.setPosition(30.f, 30.f);
    font.loadFromFile("Assets/Fonts/Minecraft.ttf");
    coinText.setFont(font);
    coinText.setStyle(Text::Bold);
    coinText.setCharacterSize(60);
    coinText.setPosition(150, 30);
    coinText.setFillColor(Color::White);
    coinText.setOutlineColor(Color::Black);
    coinText.setOutlineThickness(5);
}


bool City::houseDoor1() {
    if (character.character.getPosition().x > 800 && character.character.getPosition().x < 860 && character.character.getPosition().y < 420) {
        return true;
    }
    return false;
}

bool City::houseDoor2() {
    if (character.character.getPosition().x > 1665 && character.character.getPosition().x < 1845 && character.character.getPosition().y < 420) {
        return true;
    }
    return false;
}

bool City::houseDoor3() {
    if (character.character.getPosition().x > 2520 && character.character.getPosition().x < 2655 && character.character.getPosition().y < 420) {
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
bool City::beachdoor() {
    if (character.character.getPosition().x > 3150 && character.character.getPosition().y < 1485 && character.character.getPosition().y > 1305) {
        return true;
    }
    return false;
}

bool City::parkdoor() {
    if (character.character.getPosition().x > 2790 && character.character.getPosition().y > 3095 && character.character.getPosition().y < 3385) {
        return true;
    }
    return false;
}

bool City::fount() {
    if (character.character.getPosition().x > 1575 && character.character.getPosition().x < 1755 && character.character.getPosition().y < 2030 && character.character.getPosition().y > 1755.f) {
        return true;
    }
    return false;
}


void City::fade(RenderWindow& window, View& view, Clock& track) {
    RectangleShape fadeShape(Vector2f(3950.f, 3950.f));
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
        open.play();
        fade(window, view, track);
        stateManager.changeState(std::make_unique<House>(stateManager, view, numCoins, 2180.f, 1690.f));
        hasTransitioned = true;
    }

    if (houseDoor2() && !hasTransitioned) {
        Vector2f newViewCenter = character.getPosition();
        view.setCenter(newViewCenter);
        open.play();
        fade(window, view, track);
        stateManager.changeState(std::make_unique<House>(stateManager, view, numCoins, 1700.f, 1690.f));
        hasTransitioned = true;
    }

    if (houseDoor3() && !hasTransitioned) {
        Vector2f newViewCenter = character.getPosition();
        view.setCenter(newViewCenter);
        open.play();
        fade(window, view, track);
        stateManager.changeState(std::make_unique<House>(stateManager, view, numCoins, 2600.f, 1690.f));
        hasTransitioned = true;
    }

    if (arcadeDoor() && !hasTransitioned) {
        Vector2f newViewCenter = character.getPosition();
        view.setCenter(newViewCenter);
        open.play();
        fade(window, view, track);
        stateManager.changeState(std::make_unique<Arcade>(stateManager, view, numCoins, 1300.f, 915.f));
        hasTransitioned = true;
    }
    if (fount() && !hasTransitioned) {
        fountain = true;
        if (Keyboard::isKeyPressed(Keyboard::A) && numCoins != 0) {
            insufficient = false;
            numCoins--;
            Vector2f newViewCenter = character.getPosition();
            view.setCenter(newViewCenter);
            fade(window, view, track);
            stateManager.changeState(std::make_unique<Fountain>(stateManager, view, numCoins, 0, 0));
            hasTransitioned = true;
        }
        else if (Keyboard::isKeyPressed(Keyboard::A) && numCoins == 0) {
            insufficient = true;
        } 
    }
    else {
        fountain = false;
    }

    if (parkdoor() && !hasTransitioned) {
        Vector2f newViewCenter = character.getPosition();
        view.setCenter(newViewCenter);
        fade(window, view, track);
        stateManager.changeState(std::make_unique<Park>(stateManager, view, numCoins, 855.f, 495.f));
        hasTransitioned = true;
    }
    if (beachdoor() && !hasTransitioned) {
        Vector2f newViewCenter = character.getPosition();
        view.setCenter(newViewCenter);
        fade(window, view, track);
        stateManager.changeState(std::make_unique<Beach>(stateManager, view, numCoins, 945.f, 630.f));
        hasTransitioned = true;
    }

    if (Keyboard::isKeyPressed(Keyboard::A) && (talkD || fountain) && !wasPressed) {
        pressed = !pressed;
    }
    wasPressed = Keyboard::isKeyPressed(Keyboard::A);

}

void City::update(RenderWindow& window, float deltaTime, Clock& track, Event& event, Clock& clock) {
    coinText.setString(" x " + to_string(numCoins));
    if ((andreas.getGlobalBounds().top + andreas.getGlobalBounds().height) >= 1500.f) {
        andreasDirection = -1;
        npcA.loadFromFile("Assets/Characters/andreasup1.png");
    }
    if (andreas.getGlobalBounds().top <= 750.f) {
        andreasDirection = 1;
        npcA.loadFromFile("Assets/Characters/andreasdown1.png");
    }
    andreas.move(Vector2f(0.f, 150.f * deltaTime * andreasDirection));
    sprites.clear();
    sprites.push_back(andreas);
    sprites.push_back(dakota);
    if (track.getElapsedTime() >= move) {
        startMove = true;
    }
    if (startMove) {
        character.handlemovement(event, deltaTime, track, tile, bound, clock);
    }

    if (character.character.getGlobalBounds().intersects(dakota.getGlobalBounds())) {
        talkD = true;
    }
    else {
        talkD = false;
    }
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
    }
    background.draw(window);
    window.draw(dakota);
    character.draw(window);
    window.draw(andreas);
    path.draw(window);
    View view = window.getView();
    window.setView(window.getDefaultView());
    coin.draw(window);
    window.draw(coinText);
    if (talkD && pressed) {
        box.setTexture("Assets/Characters/dakotadialogue.png");
        box.draw(window);
    }
    if (talkD && !pressed) {
        pressA.setTexture("Assets/Characters/pressA.png");
        pressA.draw(window);
    }
    if (fountain && pressed && insufficient) {
        pressA.setTexture("Assets/Characters/coinprompt.png");
        pressA.draw(window);
    }
    if (fountain && !pressed) {
        pressA.setTexture("Assets/Characters/pressA.png");
        pressA.draw(window);
    }
    window.setView(view);

}

Character& City::getCharacter() {
    return character;
}

Tiling& City::getTile() {
    return tile;
}

City::~City() {
}