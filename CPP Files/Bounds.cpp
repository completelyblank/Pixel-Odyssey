#include "Bounds.hpp"

Bounds::Bounds() {
    rec.setSize(Vector2f(50.f, 50.f));
    rec.setFillColor(Color::Cyan);
}

void Bounds::set(Coordinates& cord) {
    bound.clear();
    for (int i = 0; i < cord.coordinates.size(); i++) {
        rec.setPosition(cord.coordinates[i]);
        bound.push_back(rec);
    }
}

void Bounds::set(Inside& cord) {
    bound.clear();
    for (int i = 0; i < cord.inside.size(); i++) {
        rec.setPosition(cord.inside[i]);
        bound.push_back(rec);
    }
}

Vector2f Bounds::collision(Sprite& sp, Vector2f velocity)
{
    for (auto& i : bound)
    {
        FloatRect spritebounds = sp.getGlobalBounds();
        FloatRect wallbounds = i.getGlobalBounds();
        nextpos = spritebounds;
        nextpos.left += velocity.x;
        nextpos.top += velocity.y;

        if (wallbounds.intersects(nextpos))
        {
            // sprite moving to the right 
            if (velocity.x > 0 &&
                spritebounds.left + spritebounds.width <= wallbounds.left &&
                nextpos.left + spritebounds.width > wallbounds.left)
            {
                velocity.x = 0.f;
                sp.setPosition(wallbounds.left - spritebounds.width, spritebounds.top);
            }

            // sprite moving to the left 
            if (velocity.x < 0 &&
                spritebounds.left >= wallbounds.left + wallbounds.width &&
                nextpos.left < wallbounds.left + wallbounds.width)
            {
                velocity.x = 0.f;
                sp.setPosition(wallbounds.left + wallbounds.width, spritebounds.top);
            }

            // sprite moving to the top
            if (velocity.y < 0 &&
                spritebounds.top >= wallbounds.top + wallbounds.height &&
                nextpos.top < wallbounds.top + wallbounds.height)
            {
                velocity.y = 0.f;
                sp.setPosition(spritebounds.left, wallbounds.top + wallbounds.height);
            }

            // sprite moving to the bottom 
            if (velocity.y > 0 &&
                spritebounds.top + spritebounds.height <= wallbounds.top &&
                nextpos.top + spritebounds.height > wallbounds.top)
            {
                velocity.y = 0.f;
                sp.setPosition(spritebounds.left, wallbounds.top - spritebounds.height);
            }
        }
    }
    return velocity;
}
