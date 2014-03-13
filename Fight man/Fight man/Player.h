#pragma once
#include "game.h"
#include "Animation.h"

class PLAYER
{
public:
	float x,y,dx,dy,const_y;
	AnimationManager anim;
	bool dir,onGround,flag;
	map<string,bool> key;
	enum{stay,walk,jump,kick,upDown} state;
	PLAYER();
	void keyCheck();
	void update(float time,RenderWindow &window);
};
