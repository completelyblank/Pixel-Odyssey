#ifndef VIEW_H
#define VIEW_H
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

class ViewScroll {
public:
	ViewScroll();
	void scroll();
private:
	float scrollSpeed = 20.0f;
	sf::View view;
};

#endif VIEW_H
