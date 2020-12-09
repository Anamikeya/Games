#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>
using namespace std;
#include<vector>
#include<ctime>
#include<sstream>
class game
{
private:
	sf:: RenderWindow* window;
	sf:: VideoMode videoMode;
	sf:: Event ev;
	sf:: Vector2i mousePos;
	sf:: Vector2f mousePosView;
	

	//resources
	sf :: Font font;

	//text
	sf::Text text;

	//game objects
	vector<sf::RectangleShape> enemies;
	sf::RectangleShape enemy;



	//game logic
	bool endgame;
	unsigned points;
	float enemySpawnTimer;
	float enemySpawnTimermax;
	int maxEnemies;
	bool mouseHeld;
	int health;


	void initVariables();
	void initWindow();
	void initEnemies();
	void initFonts();
	void initText();
public:
	//cunstructors and destructors
	game();
	~game();
	

	//accessors
	const bool running() const;
	const bool getEndgame() const;
	

	//function
	void spawnEnemies();
	void updateEnemies();
	void renderEnemies(sf::RenderTarget& target);
	void pollEvents();
	void getmousePos();
	void update();
	void render();
	void renderText(sf::RenderTarget& target);
	void updateText();
	
};
