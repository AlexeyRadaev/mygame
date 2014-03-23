#pragma once
#include "game.h"
#include "Animation.h"
#include "Player.h"
class Enemy
{
public:
	double x,y,dx,dy,const_y;
	int index;
	AnimationManager anim;
	bool dir,onGround,flug;
	map<string,bool> key;
	enum{stay,walk,upDown,fall,kick,getHitHand,getHitFoot} state;
	Enemy(Texture &t,int A,int B);
	void keyCheck(double time);
	void update(double time,RenderWindow &window);
};