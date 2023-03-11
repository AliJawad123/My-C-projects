#pragma once

#include<SDL.h>
#include<SDL_image.h>
#include<iostream>
#include<fstream>
#include<Windows.h>
#undef main
using namespace std;



class Game {
public:
	Game();
	~Game();


	// This function initialises SDL  .. x,y,width,height for position of screen in game and bool fullscreen for giving option for full screen

	void init(const char* title, int width, int height, bool fullscreen);

	// This function handle events

	void handleevents();

	// This function will update all the objects in game

	void update();
	// This function will provide changes to display

	void render();


	// This function clean 
	

	void clean();

	static SDL_Renderer* renderer;
	//static SDL_Event event;

	// This functio will tell us about the that game is running or not
	bool running();

private:
	//int counter = 0;
	int cnt;
	bool isrunning;
	SDL_Window* window;
	
};
