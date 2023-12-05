#ifndef BEACHCOORD_H
#define BEACHCOORD_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

using namespace std;
using namespace sf;

class BeachCoordinates {
public:
	vector<Vector2f> coordinates;
	BeachCoordinates() {
		for (float i = 1020; i < 1930; i += 100) {
			coordinates.push_back(Vector2f(i, 150.f));
			coordinates.push_back(Vector2f(i, 1135.f));
		}
		coordinates.push_back(Vector2f(1720.f, 910.f));
		coordinates.push_back(Vector2f(945.f, 765.f));
		coordinates.push_back(Vector2f(945.f, 540.f));
		coordinates.push_back(Vector2f(1030.f, 765.f));
		coordinates.push_back(Vector2f(1030.f, 540.f));
		for (float i = 470; i > 150; i -= 100) {
			coordinates.push_back(Vector2f(1030.f, i));
		}
		for (float i = 820; i < 1135; i += 100) {
			coordinates.push_back(Vector2f(1030.f, i));
		}
		for (float i = 550; i < 835; i += 100) {
			coordinates.push_back(Vector2f(1900.f, i));
		}
		coordinates.push_back(Vector2f(1920.f, 450.f));
		coordinates.push_back(Vector2f(1940.f, 350.f));
		coordinates.push_back(Vector2f(1920.f, 850.f));
		coordinates.push_back(Vector2f(1940.f, 950.f));
		coordinates.push_back(Vector2f(1920.f, 250.f));
		coordinates.push_back(Vector2f(1940.f, 1050.f));
		coordinates.push_back(Vector2f(1130.f, 270.f));

		
	}
};

#endif BEACHCOORD_H
