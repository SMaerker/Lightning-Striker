#ifndef LINE_H
#define LINE_H

#include "stdafx.h"

class Line{
public:
	Line();

	Line(sf::Vector2f initPos, sf::Vector2f deltaPos);

	~Line();

	sf::RectangleShape getBody();

private:
	sf::RectangleShape body;

	float width = 1.0f;
	float length = 50.0f;

};

#endif