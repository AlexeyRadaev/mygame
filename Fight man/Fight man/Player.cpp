#pragma once
#include "Player.h"

PLAYER::PLAYER()
{
	flag = 0;
	onGround = false;
	x = 10;
	y = GetSystemMetrics(SM_CYFULLSCREEN) - 180;
	dir = 0;
	state = stay;
}
void PLAYER::keyCheck()
{
	if (key["L"])
	{
		dir = 1;
		if (state != kick) dx = -0.1;
		if (state == stay) state = walk;
	}
	if (key["R"])
	{
		dir = 0;
		if (state != kick) dx = 0.1;
		if (state == stay) state = walk;
	}
	if (key["Up"])
	{
		if (state != kick && !flag)dy = -0.1;
		if (state == stay)state = upDown;
	}
	if (key["Down"])
	{
		if (state != kick && !flag)dy = 0.1;
		if (state == stay)state = upDown;
	}
	if (key["X"])
	{
		if (state == stay && !flag && onGround)
		{
			flag = true;
			onGround = true;
			state = jump;
			dy = -0.57;
		}
	}
	if (key["Z"])
	{
		if (state == stay)
		{
			state = kick;
		}
	}
	if (!(key["R"] || key["L"]))
	{
		dx = 0;
		if (state == walk)state = stay;
	}
	if (!(key["Up"] || key["Down"]))
	{

		if (state == upDown)state = stay;
	}
	if (!(key["Z"]))
	{
		if (state == kick)state = stay;
	}

	if (!(key["X"]))
	{
		if (state != upDown && !onGround)dy = 0;
		if (state == jump) state = stay;
	}
}
void PLAYER::update(float time, RenderWindow &window)
{
	keyCheck();
	if (state == stay)anim.set("stay");
	if (flag)anim.set("jump");
	if (state == walk)anim.set("walk");
	if (state == upDown)anim.set("walk");
	if (state == kick)anim.set("kick");

	anim.flip(dir);
	x += dx*time;

	if (flag && onGround)
	{
		dy += 0.001*time;

	}
	y += dy*time;
	if (!flag)
	{
		const_y = y;
		dy = 0;
	}
	onGround = true;


	anim.tick(time);
	anim.draw(window, x, y);
	if (onGround && y > const_y)
	{
		flag = 0;
		y = const_y;
		dy = 0;
		onGround = false;
	}
	key["R"] = key["L"] = key["Down"] = key["Up"] = key["X"] = key["Z"] = false;
}