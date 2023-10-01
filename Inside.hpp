#ifndef  INSIDE_H
#define INSIDE_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

using namespace std;
using namespace sf;

class Inside {
public:
	vector<Vector2f> inside;
	Inside() {
		inside.push_back(Vector2f(1180, 940));
		inside.push_back(Vector2f(1080, 940));
		inside.push_back(Vector2f(980, 940));
		
		inside.push_back(Vector2f(1320, 940));
		inside.push_back(Vector2f(1420, 940));
		inside.push_back(Vector2f(1510, 940));

		inside.push_back(Vector2f(1560, 870));
		inside.push_back(Vector2f(1560, 760));
		inside.push_back(Vector2f(1560, 690));

		inside.push_back(Vector2f(945, 870));
		inside.push_back(Vector2f(945, 760));
		inside.push_back(Vector2f(945, 690));
		inside.push_back(Vector2f(945, 590));

		inside.push_back(Vector2f(1030, 465));
		inside.push_back(Vector2f(1070, 465));
		inside.push_back(Vector2f(1130, 420));
		inside.push_back(Vector2f(1230, 420));
		inside.push_back(Vector2f(1330, 420));
		inside.push_back(Vector2f(1430, 570));
		inside.push_back(Vector2f(1460, 570));
		inside.push_back(Vector2f(1430, 450));
	}
};

#endif // ! INSIDE_H
