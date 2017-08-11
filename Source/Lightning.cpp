#include "stdafx.h"
#include "Lightning.h"

Lightning::Lightning(){
	
	floorDist = 600 - 30;
	generateTrunk();
}

Lightning::Lightning(float windowHeight, float floorHeight){
	
	floorDist = windowHeight - floorHeight;

}


Lightning::~Lightning(){

}


void Lightning::generateTrunk(){
	populateTree(root);
}


void Lightning::populateTree(Node &parent){
	

	if (parent.coords.y != 570 /*|| (parent.coords.x < 800.0f && parent.coords.x > 0.0f)*/){
		nodeNum++;
		parent.children = new Node[parent.childrenNum];	
		for (int i = 0; i < parent.childrenNum; i++){
			
			parent.children[i] = Node(parent.coords);
			populateTree(parent.children[i]);
		}
	}

	else{
		parent.hasKids = false;
	}

	
}

void Lightning::drawTrunk(sf::RenderWindow *window, Node &parent){
	if (parent.hasKids){
		window->draw(parent.cord.getBody());
		for (int i = 0; i < parent.childrenNum; i++){
			drawTrunk(window, parent.children[i]);
		}
	}

}

Node Lightning::returnRoot(){
	return root;
}

int Lightning::getNodeNum(){
	return nodeNum;
}