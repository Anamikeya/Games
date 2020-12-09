
#include "Game.h"

//private methods
void Game :: initVariables()
{
	this->endgame=false;

}
void Game :: initWindow()
{
	this->videoMode = sf :: VideoMode(800,900);
	this->window = new sf :: RenderWindow(this->videoMode,"Game 2",sf::Style::Close|sf::Style::Titlebar);

}
//constructor and destructors
Game :: Game()
{
	this->initVariables();
	this->initWindow();

}

Game :: ~Game()
{
	delete this->window;
}

//functions
const bool Game :: running() const
{

}
void Game :: pollEvents()
{
	while(this->window->pollEvent(this->sfmlEvent))
	{


		switch(this->sfmlEvent.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:

		
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
			    std::cout<<"Key is pressed\n";
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			{
			    // quit...
			    std::cout<<"Escape is pressed\n";
			}
			break;
		}
	}
}

void Game :: update()
{
	this->pollEvents();


}

void Game :: render()
{
	this->window->clear();

	// Reder something
	this->player.render(this->window);
	this->window->display();
	

}

