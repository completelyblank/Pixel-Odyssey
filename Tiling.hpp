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
	const int mapsize = 65;
	const float gridsize = 50.f;
	Texture tiletext;
};

#endif TILING_H
