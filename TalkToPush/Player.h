#pragma once
#include "Utility.h"

class Player
{
public:
	enum  DIRECTION {
		STOP,
		UP,
		DOWN,
		LEFT,
		RIGHT
	};

	Player();
	~Player();
	void move();
	vec2 getPos();
	void setDirection(DIRECTION direction);

private:
	DIRECTION currentDirection;
	vec2 loc;
	int moveRate = 8;
	int step = 1;
};

