#include "stdafx.h"
#include "Line.h"


Line::Line(){

}



Line::Line(sf::Vector2f initPos, sf::Vector2f deltaPos){
	body.setFillColor(sf::Color::White);
	body.setPosition(initPos);
	body.setSize(sf::Vector2f(width, sqrt(pow(deltaPos.x, 2) + pow(deltaPos.y, 2))));
	body.rotate((atan2(deltaPos.y, deltaPos.x) * (180 / _PI_)) + 90);
}

Line::~Line(){
}


sf::RectangleShape Line::getBody(){
	return body;
}