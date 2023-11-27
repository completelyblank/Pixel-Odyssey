#ifndef BOUNDS_H
#define BOUNDS_H

#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Tiling.hpp"
#include "Coordinates.hpp"
#include "CityCoordinates.hpp"
#include "Inside.hpp"

using namespace sf;
using namespace std;

class Bounds {
public:
	Bounds();
	void set(Coordinates& cord);
	void set(CityCoordinates& cord);
	void set(Inside& cord);
	vector<RectangleShape>bound;
	RectangleShape rec;
	Vector2f collision(Sprite& sp, Vector2f velocity);
private:
	FloatRect nextpos;
};

#endif BOUNDS_H