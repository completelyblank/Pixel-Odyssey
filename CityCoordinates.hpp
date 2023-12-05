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
		coordinates.push_back(Vector2f(1100.f, 2160.f));
		coordinates.push_back(Vector2f(190.f, 660.f));
		for (float i = 540; i < 2500; i += 110) {
			if (i == 870 || i == 1750) {
				continue;
			}
			coordinates.push_back(Vector2f(i, 405.f));
		}
		coordinates.push_back(Vector2f(2490.f, 405.f));
		coordinates.push_back(Vector2f(2700.f, 405.f));
		coordinates.push_back(Vector2f(2750.f, 405.f));
		coordinates.push_back(Vector2f(2750.f, 285.f));
		coordinates.push_back(Vector2f(2810.f, 295.f));
		coordinates.push_back(Vector2f(2900.f, 295.f));
		coordinates.push_back(Vector2f(2970.f, 335.f));
		coordinates.push_back(Vector2f(3100.f, 345.f));
		coordinates.push_back(Vector2f(3170.f, 345.f));
		coordinates.push_back(Vector2f(3270.f, 345.f));
		for (float i = 450; i < 2260; i += 130) {
			if (i > 1215 && i < 1560) {
				continue;
			}
			coordinates.push_back(Vector2f(3270.f, i));
		}
		coordinates.push_back(Vector2f(3270.f, 1200.f));
		coordinates.push_back(Vector2f(3270.f, 2220.f));
		coordinates.push_back(Vector2f(3310.f, 2295.f));
		coordinates.push_back(Vector2f(3380.f, 2340.f));
		coordinates.push_back(Vector2f(3485.f, 2340.f));
		coordinates.push_back(Vector2f(920, 2910.f));
		for (float i = 170; i < 930; i += 130) {
			coordinates.push_back(Vector2f(i, 2910.f));
		}
		coordinates.push_back(Vector2f(900.f, 3015.f));
		coordinates.push_back(Vector2f(900.f, 3105.f));
		coordinates.push_back(Vector2f(190.f, 3015.f));
		coordinates.push_back(Vector2f(190.f, 3105.f));

		coordinates.push_back(Vector2f(270.f, 3140.f));
		coordinates.push_back(Vector2f(360.f, 3210.f));
		coordinates.push_back(Vector2f(810.f, 3140.f));
		coordinates.push_back(Vector2f(710.f, 3210.f));
		coordinates.push_back(Vector2f(460.f, 3210.f));
		coordinates.push_back(Vector2f(610.f, 3210.f));

		for (float i = 2790; i < 3580; i += 130) {
			coordinates.push_back(Vector2f(i, 2835.f));
		}

		for (float i = 2935; i < 3140; i += 100) {
			coordinates.push_back(Vector2f(2790.f, i));
		}

		for (float i = 3330; i < 3530; i += 100) {
			coordinates.push_back(Vector2f(2790.f, i));
		}

		for (float i = 2790; i > 0; i -= 130) {
			coordinates.push_back(Vector2f(i, 3510.f));
		}

		for (float i = 1300; i < 2200; i += 130) {
			coordinates.push_back(Vector2f(i, 1740.f));
		}
		coordinates.push_back(Vector2f(1300.f, 1870.f));
		coordinates.push_back(Vector2f(2080.f, 1870.f));
		coordinates.push_back(Vector2f(1400.f, 1900.f));
		coordinates.push_back(Vector2f(1980.f, 1900.f));
		coordinates.push_back(Vector2f(1500.f, 1920.f));
		coordinates.push_back(Vector2f(1880.f, 1920.f));
		coordinates.push_back(Vector2f(1600.f, 1920.f));
		coordinates.push_back(Vector2f(1700.f, 1920.f));
		coordinates.push_back(Vector2f(1800.f, 1920.f));
	}
};

#endif CITYCOORD_H