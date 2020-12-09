#pragma once

#include<iostream>
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>

class Player
{
private:
	sf::RectangleShape shape;
	void initShape();
	void initVariables();
public:
	Player();
	virtual ~Player();

	void update();
	void render(sf::RenderTarget* target);

};