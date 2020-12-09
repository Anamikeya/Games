#include "game.h"

#include <iostream>
int main()
{
    srand(static_cast<unsigned>(time(NULL)));
   game gme;

    while(gme.running() && !gme.getEndgame()) 
    {
        //Update
        gme.update();

        //Render
        gme.render();
    }

    return 0;
}