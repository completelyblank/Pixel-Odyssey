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

		// sarah's house
		coordinates.push_back(Vector2f(15.f, 150.f));
		
		coordinates.push_back(Vector2f(280.f, 210.f));
		coordinates.push_back(Vector2f(200.f, 230.f));
		coordinates.push_back(Vector2f(100.f, 210.f));

		coordinates.push_back(Vector2f(360.f, 180.f));
		coordinates.push_back(Vector2f(440.f, 180.f));
		coordinates.push_back(Vector2f(500.f, 160.f));

		// assorted houses
		for (float i = 600; i <= 3200; i += 100) {
			if (i >= 3000 && i <= 3100) {
				coordinates.push_back(Vector2f(i, 220.f));
			}
			else {
				coordinates.push_back(Vector2f(i, 190.f));
			}
		}
		coordinates.push_back(Vector2f(2960.f, 220.f));

		// fences
		for (float i = 0; i <= 3250; i += 108) {
			if (i >= 1700 && i <= 1800) {
				continue;
			}
			coordinates.push_back(Vector2f(i, 580));
		}
	}
};

#endif COORD_H