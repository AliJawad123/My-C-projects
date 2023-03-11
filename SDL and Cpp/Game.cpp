#include"Game.h"
#include"TextureManager.h"
#include"Map.h"

// I have made my own code but initially i have copied code from let's make game to add textures in my game.

SDL_Texture* playerTex;
SDL_Rect srcRect, destRect, winRect, homeRect;
Map* map;
SDL_Texture* winTex;
SDL_Texture* homeTex;
//integers
int srcX = 0;
int srcY = 0;

int dstX = 48;
int dstY = 59;
int bachaX = 1;   //---->initial position of man and bacha
int bachaY = 0;

SDL_Renderer* Game::renderer = nullptr;

bool isrunning = true;


Game::Game() {}

Game::~Game() {}

void Game::init(const char* title, int width, int height, bool fullscreen)
{
	int flags = 0;
	if (fullscreen)   // Setting windows
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		cout << "Subsystem Initilised!!" << endl;
		window = SDL_CreateWindow(title,SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
		if (window)
		{
			cout << "Windows created." << endl;
		}
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);  // Set the color for drawing operation
			cout << "Renderer created." << endl;
		}
		isrunning = true;
	}
	

  playerTex = TextureManager::LoadTexture("assets/18.png");
  winTex = TextureManager::LoadTexture("assets/grass.png");
  homeTex = TextureManager::LoadTexture("assets/home.png");
  map = new Map();

	
}

void Game::handleevents()
{
	// I have copied initial code from certain youtube channel but for 
	//  collisions i have made my own code

	SDL_Event event;
	SDL_PollEvent(&event);
	if (event.type == SDL_QUIT)
	{
		isrunning = false;
	}
	if (event.type == SDL_KEYDOWN)
	{
		if (event.key.keysym.sym == SDLK_DOWN)
		{
			if (Map::lvl1[bachaX][bachaY] == 9) {
				//isrunning = false;
			}
			else if (Map::lvl1[bachaX + 1][bachaY] == 0 || Map::lvl1[bachaX + 1][bachaY] == 9) {
				dstY += 15;
				bachaX =bachaX+1;
			
			}
			 
			
			
		}
		if (event.key.keysym.sym == SDLK_RIGHT)
		{
			if (Map::lvl1[bachaX][bachaY] == 9) {
				//isrunning = false;
			}
			else if (Map::lvl1[bachaX][bachaY+1] == 0 || Map::lvl1[bachaX][bachaY + 1] == 9) {
				dstX += 15;
				bachaY++;
			}
			
			
		}
		if (event.key.keysym.sym == SDLK_UP)
		{
			if (Map::lvl1[bachaX ][bachaY] == 9) {
				//isrunning = false;
			}
			else if (Map::lvl1[bachaX - 1][bachaY] == 0 || Map::lvl1[bachaX - 1][bachaY] == 9) {
				dstY -= 15;
				bachaX -= 1;
			}
			
		}
		if (event.key.keysym.sym == SDLK_LEFT)
		{
			
			if (Map::lvl1[bachaX][bachaY ] == 9) {
				//isrunning = false;
			}
			else if (Map::lvl1[bachaX][bachaY - 1] == 0 || Map::lvl1[bachaX][bachaY - 1] == 9) {
				dstX -= 15;
				bachaY -= 1;
			}
			
		}
		if (dstX < 0)
		{
			dstX = 0;
		}
		if (dstY < 0)
		{
			dstY = 0;
		}
		if (dstX == 800 || dstY == 640)
		{
			cout << "player won the game." << endl;
		}
	
	}
}

void Game::update() {
	

	srcRect.h = 13;
	srcRect.w = 13;
	srcRect.x = srcX;
	srcRect.y = srcY;

	destRect.x = dstX;
	destRect.y = dstY;
	destRect.w = srcRect.w * 2;
	destRect.h = srcRect.h * 2;


	winRect.x = 350;
	winRect.y = 300;

	winRect.w = 100;
	winRect.h = 100;

	homeRect.x = 710;
	homeRect.y = 568;
	homeRect.w = 30;
	homeRect.h = 30;

	
}




void Game::render()
{

	SDL_RenderClear(renderer);
	map->DrawMap();
	
	SDL_RenderCopy(Game::renderer, playerTex, NULL,&destRect);
	if (Map::lvl1[bachaX][bachaY] == 9) {
		SDL_RenderCopy(Game::renderer, winTex, NULL, &winRect);
	}
	SDL_RenderCopy(Game::renderer, homeTex, NULL, &homeRect);

	
	
	SDL_RenderPresent(renderer);

}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	cout << "Game Cleaned." << endl;
}

bool Game::running() {
	if (isrunning) {
		return true;
	}
	else {
		return false;
	}
	
}