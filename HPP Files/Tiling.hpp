#ifndef TILING_H
#define TILING_H

#include <SFML/Graphics.hpp>
#include <vector>
using namespace sf;
using namespace std;

class Tiling {
public:
	Tiling();
	void setTexture(string fp);
	int left, right, up, down;
	vector<vector<Sprite>>tilemap;
	float getgridsize();
	float getmapsize();
	void updatevals(float vx, float vy);
	void check();
private:
	const int mapsize = 80.f;
	const float gridsize = 45.f;
	Texture tiletext;
};

#endif TILING_H
