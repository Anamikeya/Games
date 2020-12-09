

#include"player.h"

#include<ctime>
class Game
{

private:
	sf :: VideoMode videoMode;
	sf :: RenderWindow* window;
	bool endgame;
	sf :: Event sfmlEvent;

	Player player;

	void initWindow();
	void initVariables();


public:
	//constructor
	Game();
	~Game();
 	//accessor


 	//modifiere

	//Function
	const bool running() const;
	void pollEvents();
	void update();
	void render();


 };

