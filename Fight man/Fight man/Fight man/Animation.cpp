#pragma once
#include "game.h"
#include "Animation.h"

Animation::Animation(Texture &t, int x, int y, int h, int w, int cout, double Speed, int step)
{
	speed = Speed;
	sprite.setTexture(t);
	currentFrame = 0;
	flip = false;

	for (int i = 0; i < cout; i++)
	{
		stills.push_back(IntRect(x + i*step, y, w, h));
		still_flip.push_back(IntRect(x + i*step + w, y, -w, h));
	}
}
void Animation::check(double time)
{
	currentFrame += speed*time;
	if (currentFrame > stills.size()) currentFrame -= stills.size();
	int n = (int)currentFrame;
	sprite.setTextureRect(stills[n]);
	if (flip) sprite.setTextureRect(still_flip[n]);
}



void AnimationManager::create(String name, Texture &t, int x, int y, int w, int h, int count, double speed, int step )
{
	List[name] = Animation(t, x, y, w, h, count, speed, step);
	currentAnim = name;
}
void AnimationManager::draw(RenderWindow &window, double x, double y)
{
	List[currentAnim].sprite.setPosition(x, y);
	window.draw(List[currentAnim].sprite);
}
void AnimationManager::set(String name)
{
	currentAnim = name;
}
void AnimationManager::flip(bool b)
{
	List[currentAnim].flip = b;
}

void AnimationManager::tick(double time)
{
	List[currentAnim].check(time);
}
