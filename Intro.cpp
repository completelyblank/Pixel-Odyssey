#include "Intro.hpp"

Intro::Intro(StateManager& sm, View& view, int num, float x, float y) : stateManager(sm), renderC(false), numCoins(num), view(view), hasTransitioned(false), interval(seconds(0.17f)), flag(2), flag2(1) {
	background.setTexture("Assets/Characters/Intro1.jpg");
	background.setPosition(0.f, 0.f);
    play.setFillColor(Color::Blue);
    controlWindow.setTexture("Assets/Characters/controls1.png");
    controlWindow.setPosition(380.f, 50.f);
    controls.setFillColor(Color::Blue);
    play.setSize(Vector2f(340.f, 100.f));
    controls.setSize(Vector2f(340.f, 100.f));
    play.setPosition(270.f, 500.f);
    controls.setPosition(720.f, 500.f);
    backs.resize(3);
    backs[0].loadFromFile("Assets/Characters/controls1.png");
    backs[1].loadFromFile("Assets/Characters/controls2.png");
    backs[2].loadFromFile("Assets/Characters/controls3.png");
    soundtrack.openFromFile("Assets/Music/Wind.wav");
    soundtrack.setLoop(true);
    soundtrack.play();

    if (!ctext.loadFromFile("Assets/Characters/mouse.png")) {
        cout << "Failed to load cursor";
    }
    cursor.loadFromPixels(ctext.copyToImage().getPixelsPtr(), ctext.getSize(), { 0, 0 });
}

void Intro::fade(RenderWindow& window, View& view, Clock& track) {
    RectangleShape fadeShape(Vector2f(3250.f, 3250.f));
    for (int alpha = 0; alpha <= 255; alpha += 5) {
        fadeShape.setFillColor(Color(0, 0, 0, alpha));
        window.clear();
        render(window, track);
        window.draw(fadeShape);
        window.display();
    }
}

void Intro::handleInput(RenderWindow& window, View& view, Clock& track) {
    p = Cursor::Arrow;
    window.setMouseCursor(cursor);
    if (hasTransitioned) {
        fade(window, view, track);
        stateManager.changeState(std::make_unique<Play>(stateManager, view, numCoins, 0, 0));
        hasTransitioned = false;

    }
}

void Intro::update(RenderWindow& window, float deltaTime, Clock& track, Event& event, Clock& clock) {
    Vector2i mousePosition = sf::Mouse::getPosition(window);
    FloatRect cursorBounds(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y), 1, 1);
    if (track.getElapsedTime() >= interval) {
        track.restart();
        flag++;
        if (flag > 5) {
            flag = 1;
        }
    }
    if (flag == 1) {
        if (cursorBounds.intersects(play.getGlobalBounds())) {
            background.setTexture("Assets/Characters/Intro1gp.jpg");
            if (Mouse::isButtonPressed(Mouse::Left)) {
                hasTransitioned = true;
            }
        }
        else if (cursorBounds.intersects(controls.getGlobalBounds())) {
            background.setTexture("Assets/Characters/Intro1gc.jpg");
            if (Mouse::isButtonPressed(Mouse::Left)) {
                renderC = true;
            }
        }
        else {
            background.setTexture("Assets/Characters/Intro1.jpg");
        }
        if (Keyboard::isKeyPressed(Keyboard::A) && renderC) {
            renderC = false;
        }
    }
    else if (flag == 2) {
        if (cursorBounds.intersects(play.getGlobalBounds())) {
            background.setTexture("Assets/Characters/Intro2gp.jpg");
            if (event.type == sf::Event::MouseButtonPressed) {
                hasTransitioned = true;
            }
        }
        else if (cursorBounds.intersects(controls.getGlobalBounds())) {
            background.setTexture("Assets/Characters/Intro2gc.jpg");
            if (Mouse::isButtonPressed(Mouse::Left)) {
                renderC = true;
            }
        }
        else {
            background.setTexture("Assets/Characters/Intro2.jpg");
        }
        if (Keyboard::isKeyPressed(Keyboard::A) && renderC) {
            renderC = false;
        }
    }
    else if (flag == 3) {
        if (cursorBounds.intersects(play.getGlobalBounds())) {
            background.setTexture("Assets/Characters/Intro3gp.jpg");
            if (event.type == sf::Event::MouseButtonPressed) {
                hasTransitioned = true;
            }
        }
        else if (cursorBounds.intersects(controls.getGlobalBounds())) {
            background.setTexture("Assets/Characters/Intro3gc.jpg");
            if (Mouse::isButtonPressed(Mouse::Left)) {
                renderC = true;
            }
        }
        else {
            background.setTexture("Assets/Characters/Intro3.jpg");
        }
        if (Keyboard::isKeyPressed(Keyboard::A) && renderC) {
            renderC = false;
        }
    }
    else if (flag == 4) {
        if (cursorBounds.intersects(play.getGlobalBounds())) {
            background.setTexture("Assets/Characters/Intro4gp.jpg");
            if (event.type == sf::Event::MouseButtonPressed) {
                hasTransitioned = true;
            }
        }
        else if (cursorBounds.intersects(controls.getGlobalBounds())) {
            background.setTexture("Assets/Characters/Intro4gc.jpg");
            if (Mouse::isButtonPressed(Mouse::Left)) {
                renderC = true;
            }
        }
        else {
            background.setTexture("Assets/Characters/Intro4.jpg");
        }
        if (Keyboard::isKeyPressed(Keyboard::A) && renderC) {
            renderC = false;
        }
    }
    else if (flag == 5) {
        if (cursorBounds.intersects(play.getGlobalBounds())) {
            background.setTexture("Assets/Characters/Intro5gp.jpg");
            if (event.type == sf::Event::MouseButtonPressed) {
                hasTransitioned = true;
            }
        }
        else if (cursorBounds.intersects(controls.getGlobalBounds())) {
            background.setTexture("Assets/Characters/Intro5gc.jpg");
            if (Mouse::isButtonPressed(Mouse::Left)) {
                renderC = true;
            }
        }
        else {
            background.setTexture("Assets/Characters/Intro5.jpg");
        }
        if (Keyboard::isKeyPressed(Keyboard::A) && renderC) {
            renderC = false;
        }
    }
}

void Intro::render(RenderWindow& window, Clock& track) {
    if (track.getElapsedTime() >= interval) {
        track.restart();
        controlWindow.character.setTexture(backs[flag2 - 1]);
        flag2++;
        if (flag2 > 2) {
            flag2 = 1;
        }
    }
    window.draw(play);
    window.draw(controls);
    background.draw(window);
    if (renderC) {
        window.setView(window.getDefaultView());
        controlWindow.draw(window);
        window.setView(view);
    }
}

Character& Intro::getCharacter() {
    return character;
}

Tiling& Intro::getTile() {
    return tile;
}