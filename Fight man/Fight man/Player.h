#pragma once
#include "game.h"
#include "Animation.h"

class PLAYER
{
public:
	double x,y,dx,dy,const_y;
	AnimationManager anim;
	bool dir,onGround,flug,flug1,flug2;
	map<string,bool> key;
	enum{stay,walk,jump,kick,upDown,jumpkick,jumpkick1,jump1} state;
	enum{hand,noAtaka,foot}ataka;
	PLAYER(){}
	PLAYER(Texture &t);
	void keyCheck();
	void update(double time,RenderWindow &window);
};
