#ifndef BOUNDS_H
#define BOUNDS_H

#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Tiling.hpp"
#include "Coordinates.hpp"
#include "CityCoordinates.hpp"
#include "ParkCoordinates.hpp"
#include "Inside.hpp"
#include "Maze.hpp"
#include "BeachCoordinates.hpp"

using namespace sf;
using namespace std;

class Bounds {
public:
	Bounds();
	void set(Coordinates& cord);
	void set(CityCoordinates& cord);
	void set(Inside& cord);
	void set(ParkCoordinates& cord);
	void set(Maze& cord);
	void set(BeachCoordinates& cord);
	vector<RectangleShape>bound;
	RectangleShape rec;
	Vector2f collision(Sprite& sp, Vector2f velocity);
	Vector2f collision(Sprite& sp, float velocityX, float velocityY);
	Vector2f collision(Sprite& sp, Vector2f velocity, vector <Sprite> sprites);
private:
	FloatRect nextpos;
};

#endif BOUNDS_H