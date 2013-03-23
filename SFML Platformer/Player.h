#pragma once

#include "stdafx.h"
#include "DrawableGameObject.h"
#include <SFML/Network.hpp>

using namespace std;
using namespace sf;

#define GRAVITY 5
#define JUMP_HEIGHT 20
#define SPEED 2

#define SEND_PORT 9000
#define RECEIVE_PORT 9001

class Player : public DrawableGameObject
{
	public:
		Player (string name, Vector2f position, int direction);
		void Update(Level level, View view);

		friend ostream& operator<<(ostream& stream, const Player& player);
	private:
		float velocity;
		Vector2f lastPosition;

		IpAddress address;
		UdpSocket socket;
		Packet packet;
		int id;
};

