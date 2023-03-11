#pragma once

#include"Game.h"

class Map {
public:
	Map();
	~Map();

	void Loadup(int arr[37][44]);
	void DrawMap();


	SDL_Rect src, dest;
	SDL_Texture* dirt;
	SDL_Texture* grass;
	SDL_Texture* water;
	SDL_Texture* LL;
	SDL_Texture* RL;
	SDL_Texture* UL;
	SDL_Texture* DL;  

	SDL_Texture* TRC;
	SDL_Texture* BRC;
	SDL_Texture* TLC;
	SDL_Texture* BLC;
	
	
	SDL_Texture* HL;
	SDL_Texture* HLRF;
	SDL_Texture* HLLF;

	SDL_Texture* VL;
	SDL_Texture* VLTF;
	SDL_Texture* VLBF;

	SDL_Texture* T_Left;
	SDL_Texture* T_Right;
	SDL_Texture* T_Buttom;
	SDL_Texture* T_Top;

	int map[37][44];
	static int lvl1[37][44];
};
