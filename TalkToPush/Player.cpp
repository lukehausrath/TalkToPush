#include "Player.h"
#include <iostream>


Player::Player()
{
	loc.x = 4;
	loc.y = 4;
}


Player::~Player()
{
}


vec2 Player::getPos()
{
	return loc;
}


void Player::setDirection(DIRECTION direction)
{
	currentDirection = direction;
}


void Player::move()
{
	if (step == moveRate) {
		if (currentDirection == UP)
			loc.y += 1;
		if (currentDirection == DOWN)
			loc.y -= 1;
		if (currentDirection == LEFT)
			loc.x -= 1;
		if (currentDirection == RIGHT)
			loc.x += 1;
		if (loc.y > 7)
			loc.y = 0;
		if (loc.y < 0)
			loc.y = 7;
		if (loc.x > 7)
			loc.x = 0;
		if (loc.x < 0)
			loc.x = 7;
	}
	step++;
	if (step > 16)
		step = 1;
}