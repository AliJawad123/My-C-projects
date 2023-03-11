#pragma once

#include"Game.h"

// Sir I have copied this code from "Lets's make Game".

class TextureManager {

public:
	static SDL_Texture* LoadTexture(const char* filename);
	static void Draw(SDL_Texture* tex,SDL_Rect src, SDL_Rect dest);

};
