#ifndef  INSIDE_H
#define INSIDE_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

using namespace std;
using namespace sf;

class Inside {
public:
	vector <Vector2f> inside;
	Inside() {
		for (float i = 585; i < 1710; i += 100) {
			inside.push_back(Vector2f(1690.f, i));
			inside.push_back(Vector2f(2730.f, i));
		}
		for (float i = 1690; i < 2730; i += 105) {
			inside.push_back(Vector2f(i, 840.f));
			if (i == 2215.f) {
				continue;
			}
			inside.push_back(Vector2f(i, 1650.f));
		}
		inside.push_back(Vector2f(2110, 1750.f));
		inside.push_back(Vector2f(2320, 1750.f));
		inside.push_back(Vector2f(1795.f, 925.f));
		inside.push_back(Vector2f(1900.f, 925.f));
		inside.push_back(Vector2f(2490.f, 945.f));
		inside.push_back(Vector2f(2490.f, 1080.f));
		inside.push_back(Vector2f(2575.f, 1080.f));
		inside.push_back(Vector2f(2675.f, 1080.f));
		inside.push_back(Vector2f(2490.f, 980.f));
		inside.push_back(Vector2f(1890.f, 1040.f));
	}
};

#endif // ! INSIDE_H
