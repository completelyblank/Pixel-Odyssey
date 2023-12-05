#ifndef MAZE_H
#define MAZE_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

using namespace std;
using namespace sf;

class Maze {
public:
	vector<Vector2f> coordinates;
	Maze() {
		for (float i = 545; i > 140; i -= 30) {
			coordinates.push_back(Vector2f(395.f, i)); 
			coordinates.push_back(Vector2f(990.f, i));
		}
		for (float i = 295; i < 395; i += 30) {
			coordinates.push_back(Vector2f(i, 270.f));
		}
		for (float i = 80; i < 600; i += 30) {
			coordinates.push_back(Vector2f(290.f, i));
		}
		for (float i = 80; i < 600; i += 30) {
			coordinates.push_back(Vector2f(1080.f, i));
		}
		coordinates.push_back(Vector2f(395.f, 140.f));
		coordinates.push_back(Vector2f(485.f, 110.f));
		coordinates.push_back(Vector2f(515.f, 110.f));
		coordinates.push_back(Vector2f(545.f, 110.f));
		coordinates.push_back(Vector2f(575.f, 110.f));
		for (float i = 290; i < 1100; i += 30) {
			coordinates.push_back(Vector2f(i, 80.f));
		}
		for (float i = 290; i < 1100; i += 30) {
			coordinates.push_back(Vector2f(i, 610.f));
		}
		for (float i = 395; i < 470; i += 30) {
			coordinates.push_back(Vector2f(i, 430.f));
		}
		for (float i = 485; i < 560; i += 30) {
			coordinates.push_back(Vector2f(i, 490.f));
		}
		for (float i = 395; i < 570; i += 30) {
			coordinates.push_back(Vector2f(i, 555.f));
		}
		for (float i = 580; i < 750; i += 30) {
			coordinates.push_back(Vector2f(i, 530.f));
		}
		for (float i = 750; i < 900; i += 30) {
			coordinates.push_back(Vector2f(i, 545.f));
		}
		for (float i = 535; i > 200; i -= 30) {
			coordinates.push_back(Vector2f(660.f, i));
		}
		for (float i = 680; i < 740; i += 30) {
			coordinates.push_back(Vector2f(i, 205.f));
		}
		for (float i = 660; i < 740; i += 30) {
			coordinates.push_back(Vector2f(i, 320.f));
		}
		for (float i = 750; i < 840; i += 30) {
			coordinates.push_back(Vector2f(i, 370.f));
		}
		for (float i = 750; i < 840; i += 30) {
			coordinates.push_back(Vector2f(i, 260.f));
		}
		for (float i = 680; i < 740; i += 30) {
			coordinates.push_back(Vector2f(i, 437.f));
		}
		for (float i = 990; i > 560; i -= 30) {
			coordinates.push_back(Vector2f(i, 130.f));
		}
		for (float i = 120; i < 330; i += 30) {
			coordinates.push_back(Vector2f(570.f, i));
		}
		for (float i = 220; i < 350; i += 30) {
			coordinates.push_back(Vector2f(485.f, i));
		}
		for (float i = 485; i < 660.f; i += 30) {
			coordinates.push_back(Vector2f(i, 365.f));
		}
		for (float i = 425; i < 600; i += 30) {
			coordinates.push_back(Vector2f(555.f, i));
		}
		for (float i = 475; i > 200; i -= 30) {
			coordinates.push_back(Vector2f(805.f, i));
		}
		for (float i = 840; i < 910; i += 30) {
			coordinates.push_back(Vector2f(i, 480.f));
		}
		for (float i = 480; i < 570; i += 30) {
			coordinates.push_back(Vector2f(900.f, i));
		}
		for (float i = 900; i < 970; i += 30) {
			coordinates.push_back(Vector2f(i, 425.f));
		}
		for (float i = 830; i < 900; i += 30) {
			coordinates.push_back(Vector2f(i, 365.f));
		}
		for (float i = 890; i < 960; i += 30) {
			coordinates.push_back(Vector2f(i, 310.f));
		}
		for (float i = 830; i < 900; i += 30) {
			coordinates.push_back(Vector2f(i, 250.f));
		}
	}
};

#endif MAZE_H