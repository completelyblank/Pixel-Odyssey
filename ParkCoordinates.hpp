#ifndef PARKCOORD_H
#define PARKCOORD_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

using namespace std;
using namespace sf;

class ParkCoordinates {
public:
	vector<Vector2f> coordinates;
	ParkCoordinates() {
		coordinates.push_back(Vector2f(1430.f, 720.f));
		coordinates.push_back(Vector2f(1360.f, 570.f));
		coordinates.push_back(Vector2f(1630.f, 720.f));
		coordinates.push_back(Vector2f(990.f, 180.f));
		coordinates.push_back(Vector2f(900.f, 180.f));
		coordinates.push_back(Vector2f(810.f, 180.f));
		coordinates.push_back(Vector2f(1040.f, 180.f));
		coordinates.push_back(Vector2f(1170.f, 90.f));
		for (float i = 1170; i < 1810; i += 90) {
			coordinates.push_back(Vector2f(i, 90.f));
		}
		for (float i = 135; i < 936; i += 100) {
			coordinates.push_back(Vector2f(1860.f, i));
		}
		for (float i = 810; i < 1820; i += 90) {
			coordinates.push_back(Vector2f(i, 900.f));
		}
		coordinates.push_back(Vector2f(820.f, 360.f));
		coordinates.push_back(Vector2f(820.f, 435.f));
		coordinates.push_back(Vector2f(720.f, 435.f));
		coordinates.push_back(Vector2f(675.f, 450.f));
		coordinates.push_back(Vector2f(600.f, 450.f));
		coordinates.push_back(Vector2f(675.f, 610.f));
		coordinates.push_back(Vector2f(765.f, 610.f));
		coordinates.push_back(Vector2f(820.f, 610.f));
		coordinates.push_back(Vector2f(820.f, 675.f));
		coordinates.push_back(Vector2f(820.f, 765.f));
		coordinates.push_back(Vector2f(820.f, 810.f));

		coordinates.push_back(Vector2f(1440.f, 360.f));
		coordinates.push_back(Vector2f(1530.f, 360.f));
		coordinates.push_back(Vector2f(1575.f, 360.f));
		coordinates.push_back(Vector2f(1665.f, 495.f));
		coordinates.push_back(Vector2f(1440.f, 540.f));
		coordinates.push_back(Vector2f(1575.f, 540.f));
		coordinates.push_back(Vector2f(1665.f, 585.f));
	}
};

#endif PARKCOORD_H