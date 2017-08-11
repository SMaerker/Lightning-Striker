#ifndef NODE_H
#define NODE_H
#include "stdafx.h"
#include "Line.h"
#include <Windows.h>
#include <fstream>

struct Node{

	Node() : hasKids(true), childrenNum(1), coords(sf::Vector2f(std::rand() % 800, 0)) 
	{
		
		
	
	};

	Node(sf::Vector2f parentCoords) :
		hasKids(true),
		childrenNum((std::rand() % 100) < 5 ? (rand() % 2 + 1) : (1)),
		coords(sf::Vector2f(parentCoords.x + ((std::rand() % 50) - 25), parentCoords.y + (std::rand() % 50 ))) 
	{
		if (coords.y > 570.0f){
			coords.y = 570.0f;
		}	

		cord = Line(parentCoords, sf::Vector2f(parentCoords.x - coords.x, parentCoords.y - coords.y));
	};

	Line cord;

	bool hasKids;
	
	sf::Vector2f coords;
	int childrenNum;
	Node *children;
};





#endif