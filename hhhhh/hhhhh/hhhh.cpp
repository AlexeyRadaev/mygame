#include <SFML/Graphics.hpp>
#include <sstream>
#include <Windows.h>

using namespace sf;
class PLAYER2 {
public:
	float dx, dy;
	FloatRect rect;
	bool Jump; 
	Sprite sprite;
	int flug;
	int flug1;
	float const_Y;
	int flug2;
    float currentFrame;
	float currentFrame1;

	PLAYER2(Texture &t)
	{
		sprite.setTexture(t);
		sprite.setTextureRect(IntRect(0, 5, 60, 100));
		rect = FloatRect(10, GetSystemMetrics(SM_CYFULLSCREEN) - 180, 0, 0);
		dx = dy = 0.1;
		flug1 = 0;
		Jump = true;
		currentFrame = 0;
		currentFrame1 = 0;
	}
	void update(float time)
	{	
		rect.left += dx * time;
		if(flug1 && !Jump)
		{ 
			dy += 0.0005*time;
		}
		rect.top += dy * time;
		if (!flug1  ) 
		{
				const_Y = rect.top;
			dy = 0;
		}
		Jump = false;
		currentFrame += time * 0.005;
		if (currentFrame > 4) currentFrame -= 4;
		if (flug == 1 || dx < 0)sprite.setTextureRect(IntRect(115 * int(currentFrame) + 180, 10, -115, 180));
		if (flug == 2 || dx > 0)sprite.setTextureRect(IntRect(115 * int(currentFrame) + 65, 10, 115, 180));

		sprite.setPosition(rect.left, rect.top);
		if (flug1 && rect.top > const_Y ) 
		{
			rect.top = const_Y;
			flug1 = 0;
			dy = 0;
			Jump = true;
		}
		dx =  0;
		flug = 0;
	}
	void kick(float time,int a)
	{
		currentFrame1 += time * 0.005;
	    if (currentFrame > 2) currentFrame -= 2;
		if (a == 1)sprite.setTextureRect(IntRect(125 * int(currentFrame) + 125, 395, -125, 180));
		if (a == 2)sprite.setTextureRect(IntRect(125 * int(currentFrame) , 395, 125, 180));
	}
};
class PLAYER1 {
public:
	float dx, dy;
	FloatRect rect;
	bool Jump; 
	Sprite sprite;
	int flug;
	int flug1;
	float const_Y;
	int flug2;
    float currentFrame;
	float currentFrame1;

	PLAYER1(Texture &t)
	{
		sprite.setTexture(t);
		sprite.setTextureRect(IntRect(0, 5, 60, 100));
		rect = FloatRect(10, GetSystemMetrics(SM_CYFULLSCREEN) - 180, 0, 0);
		dx = dy = 0.1;
		flug1 = 0;
		Jump = true;
		currentFrame = 0;
		currentFrame1 = 0;
	}
	void update(float time)
	{	
		rect.left += dx * time;
		if(flug1 && !Jump)
		{ 
			dy += 0.0005*time;
		}
		rect.top += dy * time;
		if (!flug1  ) 
		{
				const_Y = rect.top;
			dy = 0;
		}
		Jump = false;
		currentFrame += time * 0.005;
		if (currentFrame > 4) currentFrame -= 4;
		if (flug == 1 || dx < 0)sprite.setTextureRect(IntRect(115 * int(currentFrame) + 180, 10, -115, 180));
		if (flug == 2 || dx > 0)sprite.setTextureRect(IntRect(115 * int(currentFrame) + 65, 10, 115, 180));

		sprite.setPosition(rect.left, rect.top);
		if (flug1 && rect.top > const_Y ) 
		{
			rect.top = const_Y;
			flug1 = 0;
			dy = 0;
			Jump = true;
		}
		dx =  0;
		flug = 0;
	}
	void kick(float time,int a)
	{
		currentFrame1 += time * 0.005;
	    if (currentFrame > 2) currentFrame -= 2;
		if (a == 1)sprite.setTextureRect(IntRect(125 * int(currentFrame) + 125, 395, -125, 180));
		if (a == 2)sprite.setTextureRect(IntRect(125 * int(currentFrame) , 395, 125, 180));
	}
};
class PLAYER {
public:
	float dx, dy;
	FloatRect rect;
	bool Jump; 
	Sprite sprite;
	int flug;
	int flug1;
	float const_Y;
	int flug2;
    float currentFrame;
	float currentFrame1;

	PLAYER(Texture &t)
	{
		sprite.setTexture(t);
		sprite.setTextureRect(IntRect(0, 5, 60, 100));
		rect = FloatRect(10, GetSystemMetrics(SM_CYFULLSCREEN) - 180, 0, 0);
		dx = dy = 0.1;
		flug1 = 0;
		Jump = true;
		currentFrame = 0;
		currentFrame1 = 0;
	}
	void update(float time)
	{	
		rect.left += dx * time;
		if(flug1 && !Jump)
		{ 
			dy += 0.0005*time;
		}
		rect.top += dy * time;
		if (!flug1  ) 
		{
				const_Y = rect.top;
			dy = 0;
		}
		Jump = false;
		currentFrame += time * 0.005;
		if (currentFrame > 4) currentFrame -= 4;
		if (flug == 1 || dx < 0)sprite.setTextureRect(IntRect(115 * int(currentFrame) + 180, 10, -115, 180));
		if (flug == 2 || dx > 0)sprite.setTextureRect(IntRect(115 * int(currentFrame) + 65, 10, 115, 180));

		sprite.setPosition(rect.left, rect.top);
		if (flug1 && rect.top > const_Y ) 
		{
			rect.top = const_Y;
			flug1 = 0;
			dy = 0;
			Jump = true;
		}
		dx =  0;
		flug = 0;
	}
	void kick(float time,int a)
	{
		currentFrame1 += time * 0.005;
	    if (currentFrame > 2) currentFrame -= 2;
		if (a == 1)sprite.setTextureRect(IntRect(125 * int(currentFrame) + 140, 395, -125, 180));
		if (a == 2)sprite.setTextureRect(IntRect(125 * int(currentFrame) + 15, 395, 125, 180));
	}
};
int main()
{
	RenderWindow window(VideoMode(GetSystemMetrics(SM_CXFULLSCREEN), GetSystemMetrics(SM_CYFULLSCREEN)), "Window");
	Texture t;
	t.loadFromFile("men.png");
	Texture p;
	Texture f;
	f.loadFromFile("men2.png");
	p.loadFromFile("men1.png");
	int flug = 2;
	PLAYER move(t);
	PLAYER move1(p);
	PLAYER move2(f);
	float currentFrame = 0;
	Clock clock;
	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 800;
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		if(!move.flug1)
		{
			if (flug == 1) move.sprite.setTextureRect(IntRect(65, 10, -50, 180));
			if (flug == 2) move.sprite.setTextureRect(IntRect(15, 10, 50, 180));
		}
		if (Keyboard::isKeyPressed(Keyboard::Left))  { flug = 1; move.dx = -0.1; }
		if (Keyboard::isKeyPressed(Keyboard::Right))	{ flug = 2; move.dx = 0.1; }
		
		if (Keyboard::isKeyPressed(Keyboard::Escape)) window.close();
		if (Keyboard::isKeyPressed(Keyboard::Up)) 
		{
			 
			if(move.rect.top > 400 && !move.flug1) 
			{
				move.dy = -0.1;
				move.flug = flug; 
			}
		}
		else if (Keyboard::isKeyPressed(Keyboard::Down)) 
		{ 
			if(move.rect.top < 550 && !move.flug1)
			{
				 move.dy = 0.1;
			     move.flug = flug;
			}
		}
		else if (Keyboard::isKeyPressed(Keyboard::X))
		{
			if(!move.flug1 && !move.Jump)
			{
				if (flug == 1) move.sprite.setTextureRect(IntRect(65, 220, -50, 170));
		        if (flug == 2) move.sprite.setTextureRect(IntRect(15, 220, 50, 170));
				move.flug2 = 0;
				move.flug1 = 1; 
				move.dy = -0.6;
				move.Jump = false;
			}
		}
		
		if(Keyboard::isKeyPressed(Keyboard::Z)) move.kick(time,flug);
		if((int)move.rect.left>(int)move1.rect.left -100) move1.dx = 0.05;
		if((int)move.rect.left<(int)move1.rect.left - 100) move1.dx = -0.05;
		if((int)move.rect.top>(int)move1.rect.top) move1.dy = 0.05;
		if((int)move.rect.top<(int)move1.rect.top) move1.dy = -0.05;
		if((int)move.rect.top ==  (int)move1.rect.top) move1.kick(time,flug);
		
		if((int)move.rect.left>(int)move2.rect.left +100) move2.dx = 0.05;
		if((int)move.rect.left<(int)move2.rect.left+100) move2.dx = -0.05;
		if((int)move.rect.top>(int)move2.rect.top) move2.dy = 0.05;
		if((int)move.rect.top<(int)move2.rect.top) move2.dy = -0.05;
		if((int)move.rect.top ==  (int)move2.rect.top) move2.kick(time,flug);
		move.update(time);
		move1.update(time);
		move2.update(time);
		window.clear(Color::White);
		window.draw(move.sprite);
		window.draw(move1.sprite);
		window.draw(move2.sprite);
		window.display();
	}
}


