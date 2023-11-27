#ifndef CITYCOORD_H
#define CITYCOORD_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

using namespace std;
using namespace sf;

class CityCoordinates {
public:
	vector<Vector2f> coordinates;
	CityCoordinates() {
		coordinates.push_back(Vector2f(0.f, 260.f));
		coordinates.push_back(Vector2f(120.f, 260.f));
		coordinates.push_back(Vector2f(240.f, 280.f));
		coordinates.push_back(Vector2f(360.f, 280.f));
		coordinates.push_back(Vector2f(380.f, 360.f));
		coordinates.push_back(Vector2f(380.f, 460.f));
		coordinates.push_back(Vector2f(380.f, 560.f));
		coordinates.push_back(Vector2f(380.f, 660.f));
		coordinates.push_back(Vector2f(450.f, 660.f));
		coordinates.push_back(Vector2f(490.f, 490.f));
		coordinates.push_back(Vector2f(510.f, 600.f));
		coordinates.push_back(Vector2f(540.f, 520.f));
		coordinates.push_back(Vector2f(270.f, 660.f));
		coordinates.push_back(Vector2f(190.f, 660.f));
		for (float i = 540; i < 2500; i += 110) {
			if (i == 870 || i == 1750) {
				continue;
			}
			coordinates.push_back(Vector2f(i, 405.f));
		}
		coordinates.push_back(Vector2f(2490.f, 405.f));
		coordinates.push_back(Vector2f(2750.f, 405.f));
		coordinates.push_back(Vector2f(2750.f, 285.f));
		coordinates.push_back(Vector2f(2810.f, 295.f));
		coordinates.push_back(Vector2f(2900.f, 295.f));
		coordinates.push_back(Vector2f(2970.f, 335.f));
		coordinates.push_back(Vector2f(3100.f, 345.f));
		coordinates.push_back(Vector2f(3170.f, 345.f));
		coordinates.push_back(Vector2f(3270.f, 345.f));
	}
};

#endif CITYCOORD_H