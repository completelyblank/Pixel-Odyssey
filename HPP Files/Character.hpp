#ifndef CHARACTER_H
#define CHARACTER_H

#include <SFML/Graphics.hpp>
#include "Tiling.hpp"
#include "Bounds.hpp"
#include <string>
using namespace std;
using namespace sf;

class Character {
public:
    Character();
    void setPosition(float x, float y);
    Vector2f getPosition();
    void setTexture(string fp);
    void draw(RenderWindow& window);
    void handlemovement(Event& e, float dt, Clock& c, Tiling& tile, Bounds& b, Clock& clock);
    Vector2f velocity;
    Sprite character;
    //void updateTexture(string f1, string f2, Clock t, Character& background);
private:
    Texture text;
    Texture frame1;
    Texture frame2;
    bool flag;
    float playerspeed;
    Time interval;
};

#endif // CHARACTER_H
