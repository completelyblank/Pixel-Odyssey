#include "Tiling.hpp"
#include <SFML/Graphics.hpp>
#include<iostream>
using namespace sf;

#ifdef _WIN32
#define EXECUTABLE_DIRECTORY ""
#else
#define EXECUTABLE_DIRECTORY "./"
#endif

Tiling::Tiling() {
	for (int x = 0; x < mapsize; x++) {
		tilemap.emplace_back();
		for (int y = 0; y < mapsize; y++) {
			Sprite sprite;
			sprite.setPosition(x * gridsize, y * gridsize);
			tilemap[x].push_back(sprite);
		}
	}
}

void Tiling::setTexture(std::string fp) {
	if (!tiletext.loadFromFile(fp)) {
		std::cout << "error";
	}
	for (int i = 0; i < mapsize; i++) {
		for (int j = 0; j < mapsize; j++) {
			tilemap[i][j].setTexture(tiletext);
		}
	}
}

float Tiling::getmapsize() {
	return mapsize;
}
float Tiling::getgridsize() {
	return gridsize;
}

void Tiling::updatevals(float vx, float vy) {
	left = vx / gridsize - 14;
	right = vx / gridsize + 15;
	up = vy / gridsize - 11;
	down = vy / gridsize + 11;
}

void Tiling::check()
{
	if (left < 0)
	{
		left = 0;
	}
	else if (left >= mapsize)
	{
		left = mapsize;
	}
	if (up < 0)
	{
		up = 0;
	}
	else if (up >= mapsize)
	{
		up = mapsize;
	}
	if (right < 0)
	{
		right = 0;
	}
	else if (right >= mapsize)
	{
		right = mapsize;
	}
	if (down < 0)
	{
		down = 0;
	}
	else if (down >= mapsize)
	{
		down = mapsize;
	}
}