#include "stdafx.h"

#include "Floor.h"
#include "Lightning.h"


void initBuffer(std::vector<Lightning> *buffer);

void eventCheck(sf::RenderWindow *window);

void checkBuffer(std::vector<Lightning> *buffer, int deltaTime, bool buffering, int bufferTime);

bool determineStrike();

void executionLoop(sf::RenderWindow *window);



int _tmain(int argc, _TCHAR* argv[]){

	srand(time(NULL));

	const int windowWidth = 800, windowHeight = 600;
	const float floorHeight = 30.0f;

	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Lightning");
	window.setFramerateLimit(60);

	Floor::setHeight(windowHeight, floorHeight);
	

	executionLoop(&window);



	return 0;
}


void eventCheck(sf::RenderWindow *window){
	sf::Event evnt;

	while (window->pollEvent(evnt)){

		if (evnt.type == sf::Event::Closed){
			window->close();
		}

	}
}

void checkBuffer(std::vector<Lightning> *buffer, int deltaTime, bool *buffering, int bufferTime){
	if (*buffering){

		//std::cout << deltaTime << "\n";
		if (deltaTime <= bufferTime && ((deltaTime) % 60 == 0)){
			
			buffer->push_back(Lightning());
			
		}
		else if (deltaTime > bufferTime){
			*buffering = false;
		}
	}
}

bool determineStrike(bool *buffering){
	int chance = std::rand() % 1000;
	if ((chance) < 10 && (!*buffering)){

		*buffering = true;

		return true;
	}
	return false;
}


void initBuffer(std::vector<Lightning> *buffer){
	buffer->push_back(Lightning());
	buffer->push_back(Lightning());
	buffer->push_back(Lightning());
}

void executionLoop(sf::RenderWindow *window){


	std::vector<Lightning> buffer;
	initBuffer(&buffer);
	
	Lightning *lpntr = nullptr;
	sf::Time timer;
	sf::Clock clock;

	int second = 0;
	int initSecond = 0;
	int drawTime = 60;
	int bufferTime = 180;
	int deltaTime = 0;

	bool buffering = false;

	
	while (window->isOpen()){
		deltaTime = second - initSecond;

		eventCheck(window);

		checkBuffer(&buffer, deltaTime, &buffering, bufferTime);

		if (determineStrike(&buffering)){
			lpntr = &buffer.at(buffer.size() - 1);
			initSecond = second;
		}
		
		window->clear(((deltaTime) > (std::rand() % 7 + 1) && buffering) ? (sf::Color(70 - (deltaTime), 70 - (deltaTime), 70 - (deltaTime), 0)) : (sf::Color::Black));

		window->draw(Floor::body);

		if (buffering && (second - initSecond <= drawTime)){
			lpntr->drawTrunk(window, lpntr->returnRoot());

			

			if ((second - initSecond == drawTime)){
				buffer.pop_back();
			}
		}

		window->display();

		second++;
	}

}