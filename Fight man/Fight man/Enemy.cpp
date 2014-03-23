#pragma once
#include "Enemy.h"


Enemy::Enemy(Texture &t,int A,int B)
{
	
	x = 600;
	if(!B)y = GetSystemMetrics(SM_CYFULLSCREEN) - 180;
	index = 0;
	if(B == 1)y = GetSystemMetrics(SM_CYFULLSCREEN) - 200;
	if(B == 2)y = GetSystemMetrics(SM_CYFULLSCREEN) - 220;
	if(B == 3)y = GetSystemMetrics(SM_CYFULLSCREEN) - 240;
	if(B == 4)y = GetSystemMetrics(SM_CYFULLSCREEN) - 260;
	if(B == 5)y = GetSystemMetrics(SM_CYFULLSCREEN) - 280;
	flug = 0;
	onGround = false;
	dir = 0;
	state = stay;
	anim.create("walk",t,90,10,180,90,4,0.003,90);
	anim.create("stay",t,0,10,180,90,1,0.003,1);
	anim.create("kick",t,0,395,180,90,2,0.003,90);
	anim.create("HAND",t,200,395,180,90,1,0,90);
	anim.create("FOOT",t,300,395,180,180,1,0,180);
	anim.create("FALL",t,600,395,180,170,1,0,170);
}
void Enemy::keyCheck(double time)
{
	if (key["L"])
	{
		dir = 1;
		if(state != fall && state == stay)dx = -0.1;
		if ( state == stay) state = walk;
	}
	if (key["R"])
	{
		dir = 0;
	    if(state != fall && state == stay) dx = 0.1;
		if ( state == stay) state = walk;
	}
	if (key["Up"])
	{
		dy = -0.1;
		if (state == stay)state = upDown;
	}
	if (key["Down"])
	{
		dy = 0.1;
		if (state == stay)state = upDown;
	}
	
	if (key["Z"])
	{  
	   if (state == stay) state = kick;
	}
	if(key["fall"])
	{
		if (state == stay && !flug && !onGround)
		{
			flug = true;
			onGround = true;
			state = getHitFoot;
			dy = -0.4;
			index = 0;
		}
	}
	if(key["getFace"])
	{
		state = getHitHand;
	}
	if (!(key["R"] || key["L"]))
	{
		if(state != getHitFoot ) dx = 0;
		if (state != getHitFoot && state == walk)state = stay;
	}
	if (!(key["Up"] || key["Down"]))
	{
		if (state != getHitFoot && state == upDown)state = stay;
	}
	if (!(key["Z"]))
	{
		if (state != getHitFoot && state == kick)state = stay;
	}
	if(!(key["fall"]))
	{
		if (!onGround)dy = 0;
		if (!flug && state == getHitFoot) 
		{
				 dx = 0;
				 state = fall;
		}
		if(!flug && index > 1000 && state == fall) state = stay;
		if(state == fall)index += (int) time;
	}
	if(!(key["getFace"]))
	{
		if(state == getHitHand)state = stay;
	}
	if(flug)
	{
		if(dir)dx = 0.3;
		if(!dir)dx = -0.3;
	}

}
void Enemy::update(double time, RenderWindow &window)
{
	keyCheck(time);
	if (state == stay)anim.set("stay");
	if (state == walk)anim.set("walk");
	if (state == upDown)anim.set("walk");
	if (state == kick)anim.set("kick");
	if (state == getHitHand)anim.set("HAND");
	if (state == getHitFoot)anim.set("FOOT");
	if (state == fall)anim.set("FALL");
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
		dy = 0;
		onGround = false;
	}
	key["R"] = key["L"] = key["Down"] = key["Up"] =  key["Z"] = key["fall"] = key["getFace"] = false;
}