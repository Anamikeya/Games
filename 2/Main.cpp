#include"Game.h"

int main(int argc, char const *argv[])
{
	srand(static_cast<unsigned>(time(0)));
	Game game;
	//Game loop
	while (game.running())
	{
		game.update();
		game.render();

	}
	return 0;
}