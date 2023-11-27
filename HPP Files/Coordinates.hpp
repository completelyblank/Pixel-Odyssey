#ifndef COORD_H
#define COORD_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

using namespace std;
using namespace sf;

class Coordinates {
public:
	vector<Vector2f> coordinates;
	Coordinates() {
		// Arcade
		for (int i = 765; i <= 1865; i += 100) {
			coordinates.push_back(Vector2f(i, 385.f));
		}
		for (int j = 360; j < 900; j += 100) {
			coordinates.push_back(Vector2f(810.f, j));
		}
		coordinates.push_back(Vector2f(1140.f, 435.f));
		coordinates.push_back(Vector2f(1865.f, 485.f));
		coordinates.push_back(Vector2f(1865.f, 585.f));
		coordinates.push_back(Vector2f(1665.f, 610.f));
		coordinates.push_back(Vector2f(1765.f, 610.f));
		coordinates.push_back(Vector2f(1665.f, 710.f));
		coordinates.push_back(Vector2f(1665.f, 810.f));
		coordinates.push_back(Vector2f(1665.f, 910.f));
		for (int j = 830; j < 1665; j += 100) {
			if (j == 1330) {
				continue;
			}
			if (j == 1230 || j == 1430) {
				coordinates.push_back(Vector2f(j, 970.f));
			}
			coordinates.push_back(Vector2f(j, 930.f));
		}
	}
};

#endif COORD_H