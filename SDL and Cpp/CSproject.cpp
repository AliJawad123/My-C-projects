#include"Game.h"
Game* game = nullptr;

// Sir i learned and copied some of codes from "Let's make game" youtube channel.


int main(int argc, const char* argv[])
{
	
	const int FPS = 60;                  
	const int frameDelay = 1000 / FPS;  

	Uint32 framestart;                   
	int frameTime;                       // I have written it for setting frame

	game = new Game();      
	game->init("GameWindow", 800, 640, false);
	while (game->running()) {

		framestart = SDL_GetTicks();  // setting frame when game is running

		game->handleevents();
		game->update();
		game->render();

		frameTime = SDL_GetTicks() - framestart;  // frame timing

		if (frameDelay > frameTime)  // slowing down moving process
		{
			SDL_Delay(frameDelay - frameTime);
		}

	}
	game->clean();


	return 0;

}