#pragma once

#include <map>

#include "stdafx.h" 
#include "GameObject.h"
#include "DrawableGameObject.h"
#include "Level.h"
#include "Player.h"

#define WINDOW_WIDTH 1000
#define WINDOW_HEIGHT 700
#define WINDOW_TITLE "The Amazing Platformer Game"

#define MAX_FRAMERATE 60

using namespace sf;
using namespace std;

class Game {
	public:
		static void Start();

		static void AddNetworkedPlayer(int id, DrawableGameObject player);
		static void UpdateNetworkedPlayer(int id, int x, int y);

		static vector<GameObject*> gameObjects;
		static Player player;
		static View view;

		static bool IsFocused;
	private:
		static void Loop();
		static void Splash();
		static RenderWindow gameWindow;
		static Level level;
		static map<int, DrawableGameObject> networkedPlayers;
};

