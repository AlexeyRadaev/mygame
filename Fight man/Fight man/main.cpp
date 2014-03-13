#include "game.h"
#include "Player.h"
#include "Animation.h"	

int main()
{
	RenderWindow window(VideoMode(0,0), "Window", Style::Fullscreen);
	Texture t;
	t.loadFromFile("men.png");
	
	Clock clock;
    PLAYER man;
	man.anim.create("walk",t,90,10,180,90,4,0.005,90);
	man.anim.create("jump",t,15,220,170,50,1,0.005,1);
	man.anim.create("stay",t,0,10,180,90,1,0.005,1);
	man.anim.create("kick",t,0,395,180,90,2,0.005,90);
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
		if (Keyboard::isKeyPressed(Keyboard::Left))  
		{
			man.key["L"] = true; 
		}
		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			man.key["R"] = true; 
		}
		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			man.key["Up"] = true;
		}
		if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			man.key["Down"] = true;
		}
		if (Keyboard::isKeyPressed(Keyboard::X))
		{
			man.key["X"] = true;
		}
		if (Keyboard::isKeyPressed(Keyboard::Z))
		{
			man.key["Z"] = true;
		}
	    if(Keyboard::isKeyPressed(Keyboard::Escape)) window.close();
		
		window.clear(Color::White);
		man.update(time,window);
		window.display();
	}
}