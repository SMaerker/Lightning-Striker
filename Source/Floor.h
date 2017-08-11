#ifndef FLOOR_H
#define FLOOR_H

#include "stdafx.h"


struct Floor{
	
	static void setHeight(float windowHeight, float floorHeight){
		body.setPosition(sf::Vector2f(0, windowHeight - floorHeight));
		body.setFillColor(sf::Color::White);
	}

	static sf::RectangleShape body;
	
};

sf::RectangleShape Floor::body = sf::RectangleShape(sf::Vector2f(800.0f, 10.0f));


#endif