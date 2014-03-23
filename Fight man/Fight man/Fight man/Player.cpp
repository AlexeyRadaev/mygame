#pragma once
#include "Player.h"

PLAYER::PLAYER(Texture &t)
{
	flug2 = false;
	flug = 0;
	onGround = false;
	x = 10;
	y = GetSystemMetrics(SM_CYFULLSCREEN) - 180;
	dir = 0;
	state = stay;
	flug1 = false;
	anim.create("walk",t,90,10,180,90,4,0.003,90);
	anim.create("jump",t,0,220,170,90,1,0.003,1);
	anim.create("stay",t,0,10,180,90,1,0.003,1);
	anim.create("kick",t,0,395,180,90,2,0.005,90);
	anim.create("jumpKick",t,90,220,170,95,1,0,0);
	anim.create("jumpKick1",t,600,220,170,110,1,0,0);
	anim.create("jump1",t,200,220,170,100,4,0.008,100);
}
void PLAYER::keyCheck()
{
	if (key["L"])
	{
		dir = 1;
		if (state != jump && state != jumpkick && state != kick) dx = -0.2;
		if ( state != jumpkick1 &&state != jump && state == stay) state = walk;
	    if (flug && state == jump) state = jump1;
		else if (!flug && state != walk)state = jump;
	    if (flug1 && state == jump1)
		{
			ataka = foot;
			state = jumpkick1;
		}
		
	}
	if (key["R"])
	{
		dir = 0;
		if (state != jump && state != jumpkick && state != kick) dx = 0.2;
		if ( state != jumpkick1 &&state != jump && state == stay) state = walk;
		if (flug && state == jump) state = jump1;
		else if (!flug && state != walk)state = jump;
		if (flug1 && state == jump1)
		{
			ataka = foot;
			state = jumpkick1;
		}
	}
	if (key["Up"])
	{
		if (state != kick && !flug && state != jump)dy = -0.2;
		if (state == stay)state = upDown;
	}
	if (key["Down"])
	{
		if (state != kick && !flug && state != jump)dy = 0.2;
		if (state == stay)state = upDown;
	}
	if (key["X"])
	{
		if(!flug && state == jump)
		{
			state = stay;
		}
		else if (state == stay && !flug && !onGround && flug2)
		{
			flug2 = false;
			flug = true;
			onGround = true;
			state = jump;
			dy = -0.4;
		}
	}
	if (key["Z"])
	{  
		
	   if(flug && state == jump )
	   {  
			   state = jumpkick;
			   ataka = foot;
	   }
	   else if (state != stay && !flug && state != kick)state = jump;
	   if (state != jump && state == stay) 
	   {
		   ataka = hand;
		   state = kick;
	   }
	   flug1 = true;
	}
	if (!(key["R"] || key["L"]))
	{
	    dx = 0;
		if (state == walk)state = stay;
		if (state == jump1 || state == jumpkick1) state = jump;
	}
	if (!(key["Up"] || key["Down"]))
	{

		if (state == upDown)state = stay;
	}
	if (!(key["Z"]))
	{
		if (state == kick || state == jumpkick)	
		{
			ataka = noAtaka;
			state = stay;
		}
	}

	if (!(key["X"]))
	{
		if (state !=walk && state != upDown && !onGround)dy = 0;
		if (!flug && state == jump) state = stay;
		flug2 = true;
	}
	if(state == stay || state == kick) dx = 0; 
	
}
void PLAYER::update(double time, RenderWindow &window)
{
	keyCheck();
	if (state == stay)anim.set("stay");
	if (flug)anim.set("jump");
	if (state == walk)anim.set("walk");
	if (state == upDown)anim.set("walk");
	if (state == kick)anim.set("kick");
	if (state == jumpkick)anim.set("jumpKick");
	if (state == jump1)anim.set("jump1");
	if (state == jumpkick1)anim.set("jumpKick1");
	anim.flip(dir);
	x += dx*time;

	if (flug && onGround)
	{
		dy += 0.001*time;

	}
	y += dy*time;
	if (!flug)
	{
		const_y = y;
		dy = 0;
	}

	anim.tick(time);
	anim.draw(window, x, y);
	if (onGround && y > const_y)
	{
		flug = 0;
		y = const_y;
		flug1 = false;
		ataka = noAtaka;
		onGround = false;
	}
	key["R"] = key["L"] = key["Down"] = key["Up"] = key["X"] = key["Z"] = false;
}