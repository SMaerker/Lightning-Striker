#ifndef LIGHTNING_H
#define LIGHTNING_H

#include "stdafx.h"
#include "Node.h"
class Lightning
{
public:
	Lightning();
	Lightning(float windowHeight, float floorHeight);
	~Lightning();

	void generateTrunk();
	void drawTrunk(sf::RenderWindow *window, Node &parent);
	Node returnRoot();

	int getNodeNum();

private:

	void populateTree(Node &parent);

	int nodeNum = 0;
	float floorDist;
	Node root;

};

#endif