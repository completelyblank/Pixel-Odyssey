#include "Character.hpp"
#include <iostream>

#ifdef _WIN32
#define EXECUTABLE_DIRECTORY ""
#else
#define EXECUTABLE_DIRECTORY "./"
#endif

Character::Character() : playerspeed(300.f), interval(seconds(0.3f)), flag(true), velocity({ 0.f, 0.f }){

}

void Character::setPosition(float x, float y) {
    character.setPosition(x, y);
}

Vector2f Character::getPosition() {
    return character.getPosition();
}

void Character::setTexture(string fp) {
    text.loadFromFile(fp);
    character.setTexture(text);
}

void Character::draw(RenderWindow& window) {
    window.draw(character);
}



void Character::handlemovement(Event& e, float dt, Clock& c, Tiling& tile, Bounds& b, Clock& clock) {
    velocity = { 0.f, 0.f };
    if (Keyboard::isKeyPressed(Keyboard::Up)) {
        frame1.loadFromFile("Assets/Characters/charup1.png");
        frame2.loadFromFile("Assets/Characters/charup2.png");
        if (character.getGlobalBounds().top <= 0) {
            velocity.y = 0;
        }
        else {
            velocity.y += -playerspeed * dt;
        }
        if (c.getElapsedTime() >= interval) {
            c.restart();
            flag = !flag;
            if (flag) {
                character.setTexture(frame1);
            }
            else {
                character.setTexture(frame2);
            }
        }
    }
    if (Keyboard::isKeyPressed(Keyboard::Down)) {
        frame1.loadFromFile("Assets/Characters/chardown1.png");
        frame2.loadFromFile("Assets/Characters/chardown2.png");
        if (character.getGlobalBounds().top + character.getGlobalBounds().height >= tile.getmapsize() * tile.getgridsize()) {
            velocity.y = 0;
        }
        else {
           velocity.y += playerspeed * dt;
        }
        if (c.getElapsedTime() >= interval) {
            c.restart();
            flag = !flag;
            if (flag) {
                character.setTexture(frame1);
            }
            else {
                character.setTexture(frame2);
            }
        }
    }
    if (Keyboard::isKeyPressed(Keyboard::Left)) {
        frame1.loadFromFile("Assets/Characters/charleft1.png");
        frame2.loadFromFile("Assets/Characters/charleft2.png");
        if (character.getGlobalBounds().left <= 0) {
            velocity.x = 0;
        }
        else {
            velocity.x += -playerspeed * dt;
        }
        if (c.getElapsedTime() >= interval) {
            c.restart();
            flag = !flag;
            if (flag) {
                character.setTexture(frame1);
            }
            else {
                character.setTexture(frame2);
            }
        }
    }
    if (Keyboard::isKeyPressed(Keyboard::Right)) {
        frame1.loadFromFile("Assets/Characters/charright1.png");
        frame2.loadFromFile("Assets/Characters/charright2.png");
        if (character.getGlobalBounds().left + character.getGlobalBounds().width >= tile.getmapsize() * tile.getgridsize()) {
            velocity.x = 0;
        }
        else {
            velocity.x += playerspeed * dt;
        }
        if (c.getElapsedTime() >= interval) {
            c.restart();
            flag = !flag;
            if (flag) {
                character.setTexture(frame1);
            }
            else {
                character.setTexture(frame2);
            }
        }
    }

    Vector2f original = velocity;

    if (Keyboard::isKeyPressed(Keyboard::Space)) {
        velocity.x *= 2;
        velocity.y *= 2;
    }
    else {
        velocity = original;
    }
    character.move(b.collision(character, velocity));
}

