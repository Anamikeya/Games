/*
class that act as a game engine all the function 
and functionality are here
*/
#include <SFML/Graphics.hpp>
#include "game.h"
//constructors
void game :: initVariables()
{
	this->window = nullptr;

	//Game logic
	this->endgame = false;
	this->points = 0;
	this->enemySpawnTimermax=10.f;
	this->enemySpawnTimer=this->enemySpawnTimermax;
	
	this->maxEnemies = 5;
	this->mouseHeld = false;
	this->health = 10;
}
void game :: initWindow()
{
	this->videoMode.height = 600;
	this->videoMode.width = 800;
	this->window = new sf:: RenderWindow(this->videoMode,"Game");
	this->window->setFramerateLimit(60);

} 
const bool game :: running() const
{
	return this->window->isOpen();
}

game::game()
{
	this->initVariables();
	this->initWindow();
	this->initEnemies();
	this->initFonts();
	this->initText();
}
game :: ~game()
{
	 
}
void game :: initFonts()
{
	if(!this->font.loadFromFile("cartoonfont.ttf"))
	{
		cout << "Error::Game::InitFonts:: Failed to load"<<endl;
	}

}
void game:: initText()
{
	this->text.setFont(this->font);
	this->text.setCharacterSize(12);
	this->text.setFillColor(sf::Color::White);
	this->text.setString("None");
}
void game :: renderText(sf::RenderTarget& target)
{
	target.draw(this->text);

}
void game:: updateText()
{
	stringstream ss;
	ss << "Points: " << this->points;
	this->text.setString(ss.str());
}



void game :: initEnemies()
{
	this->enemy.setPosition(10.f,10.f);
	this->enemy.setSize(sf::Vector2f(100.f,100.f));
	this->enemy.setScale(sf::Vector2f(0.5f,0.5f));
	this->enemy.setFillColor(sf::Color::Cyan);
	//this->enemy.setOutlineColor(sf::Color::Green);
	//this->enemy.setOutlineThickness(1.f);



}

void game :: pollEvents()
{

	while(this->window->pollEvent(this->ev))
	{
		switch(this->ev.type)
		{
			case sf :: Event ::Closed:
				this->window->close();
				break;
			

		}
	}

}
void game::getmousePos()
{
	/*
	returns void updates the window mouse position
	*/
	if(sf::Mouse::getPosition(*this->window).x>0 && sf::Mouse::getPosition(*this->window).x<=600 &&sf::Mouse::getPosition(*this->window).y>=0 && sf::Mouse::getPosition(*this->window).y<=800)
	{
		this->mousePos=sf::Mouse::getPosition(*this->window);
		this->mousePosView = this->window->mapPixelToCoords(this->mousePos);
  		
	}
}
void game::spawnEnemies()
{
	/*
		@return void
		spqwns enemiesand sets their colour 
		sets a random colour
		sets random colour

	*/
	this->enemy.setPosition(
		static_cast<float>(rand()%static_cast<int>(this->window->getSize().x-this->enemy.getSize().x)),0.f);
	// randomise enemies
	int type = rand()%5;
	switch(type)
	{
		case 0 :
			this->enemy.setSize(sf::Vector2f(40.f,50.f));
			this->enemy.setFillColor(sf::Color::Magenta);
			break;
		case 1 :
			this->enemy.setSize(sf::Vector2f(50.f,60.f));
			this->enemy.setFillColor(sf::Color::Red);
			break;
		case 2 :
			this->enemy.setSize(sf::Vector2f(60.f,60.f));
			this->enemy.setFillColor(sf::Color::Cyan);
			break;
		case 3 :
			this->enemy.setSize(sf::Vector2f(70.f,80.f));
			this->enemy.setFillColor(sf::Color::Blue);
			break;
		case 4 :
			this->enemy.setSize(sf::Vector2f(90.f,80.f));
			this->enemy.setFillColor(sf::Color::Green);
			break;
		default:
			this->enemy.setSize(sf::Vector2f(100.f,100.f));
			this->enemy.setFillColor(sf::Color::Green);
			break;

	}


	//spawn enemies
	this->enemies.push_back(this->enemy);


}
void game :: updateEnemies()
{
	/*Updates enemy spawn timer and adds enemy
		moves the enemy
		ramove the screen at the edge of the screen
	*/
	if(this->enemies.size() < this->maxEnemies)
	{
		if(this->enemySpawnTimer >= this->enemySpawnTimermax)
		{
			this->spawnEnemies();	
			this->enemySpawnTimer=0.f;
		}
		else
		{
			this->enemySpawnTimer += 1.f;
		}
	}
	//move enemies
	
	for(int i = 0 ; i < enemies.size() ;i++)
	{
		bool deleted = false;


		this->enemies[i].move(0.f,2.f);

		if(this->enemies[i].getPosition().y > this->window->getSize().y)
		{
			this->enemies.erase(this->enemies.begin()+i);
			this->health -= 1;
			cout << "health : "<<this->health<<endl;

		} 

		
	}
	//check if clicked apoun

	if(sf :: Mouse ::isButtonPressed(sf::Mouse::Left))
	{
		if(this->mouseHeld == false)
		{
			this->mouseHeld=true;

			
			bool deleted = false;
			for(size_t i =0; i<enemies.size() && deleted == false; i++)
			{
				if(this->enemies[i].getGlobalBounds().contains(this->mousePosView))
				{

					if(this->enemies[i].getFillColor() ==sf::Color::Magenta)
						this->points+=10;
					else if(this->enemies[i].getFillColor() ==sf::Color::Red)
						this->points+=7;
					else if(this->enemies[i].getFillColor() ==sf::Color::Blue)
						this->points+=5;
					else if(this->enemies[i].getFillColor() ==sf::Color::Cyan)
						this->points+=3;
					else if(this->enemies[i].getFillColor() ==sf::Color::Green)
						this->points+=4;

					std::cout<< "Points" <<this->points<< "\n";
					
					deleted = true;
					this->enemies.erase(this->enemies.begin()+i);
					

					this->points += 10.f;
					cout <<"Point : " << this->points << endl;
				}

			}

		}
	}
	else
	{
		this-> mouseHeld = false;
	}

}
void game :: renderEnemies(sf:: RenderTarget& target)
{
	for (auto &e : this->enemies)
	{
		target.draw(e);
	}

}
const bool game :: getEndgame() const
{
	return this->endgame;
}



void game :: update()
{
	this->pollEvents();
	if(this->endgame == false)
	{
		this->getmousePos();
		this->updateText();
		this->updateEnemies();
	}
	if(this->health <=0)
	{
		this->endgame = true;
	}
}
void game :: render()
{
	/*
	clear old frames
	render objects

	display frames in windows

	*/


	this->window->clear();

	//Draaw game
	this->renderText(*this->window);
	this->renderEnemies(*this->window);
	this->window->display();
}