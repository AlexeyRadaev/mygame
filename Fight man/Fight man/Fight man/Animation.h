#pragma once
#ifndef ANIM_H
#define ANIM_H

#include "game.h"

class Animation
{
public:
	vector<IntRect> stills,still_flip;
	double currentFrame,speed;
	bool flip;
	Sprite sprite;
	Animation(){}
	Animation (Texture &t,int x, int y,int h , int w,int cout,double Speed,int step);
	void check(double time);
};

class AnimationManager
{
public:
	String currentAnim;
	map<String, Animation> List;
	AnimationManager(){}

	void create(String name, Texture &t, int x, int y, int w, int h, int count, double speed, int step);
	void draw(RenderWindow &window,double x, double y );
	void set(String name);
	void flip(bool b);
	void tick(double time);
};

#endif ANIM_H



