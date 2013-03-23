#pragma once

#include "stdafx.h"

#define LEFT 0
#define RIGHT 1

using namespace sf;
using namespace std;

class DrawableGameObject : public GameObject {
	public:
		DrawableGameObject();
		DrawableGameObject(string filePath, Vector2f position, int direction);
		DrawableGameObject(Texture & texture, Vector2f* position);
		virtual ~DrawableGameObject(void);

		virtual void Draw(RenderWindow & window);
		virtual void Update();

		void Flip();
		Sprite sprite;
		bool loaded;

	protected:
		Texture texture;
		int direction; // 0 = left, 1 = right
};
