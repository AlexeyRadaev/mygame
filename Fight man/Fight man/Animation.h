#pragma once
#ifndef ANIM_H
#define ANIM_H

#include "game.h"

class Animation
{
public:
	vector<IntRect> stills,still_flip;
	float currentFrame,speed;
	bool flip;
	Sprite sprite;
	Animation(){}
	Animation (Texture &t,int x, int y,int h , int w,int cout,float Speed,int step);
	void check(float time);
};

class AnimationManager
{
public:
	String currentAnim;
	std::map<String, Animation> List;
	AnimationManager(){}

	void create(String name, Texture &t, int x, int y, int w, int h, int count, float speed, int step);
	void draw(RenderWindow &window,int x, int y );
	void set(String name);
	void flip(bool b);
	void tick(float time);
};

#endif ANIM_H



