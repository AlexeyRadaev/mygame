#include "game.h"
#include "Player.h"
#include "Animation.h"
#include "Enemy.h"


int main()
{
	RenderWindow window(VideoMode(0,0), "Window", Style::Fullscreen);
	Texture t,p;
	t.loadFromFile("men.png");
	p.loadFromFile("men2.png");
	list<Enemy*> enemys;
	list<Enemy*>::iterator it;
	srand(time(NULL));

	Clock clock;
    PLAYER man(t);
	
    enemys.push_back(new Enemy(p,rand()%2,rand()%6));
	while (window.isOpen())
	{
		double time = (double)clock.getElapsedTime().asMicroseconds();
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
		
		for(it = enemys.begin();it !=enemys.end();it++)
		{
			Enemy *b = *it;
			if((man.x - 30) > b->x)b->key["R"] = true;
			if((man.x + 30) < b->x)b->key["L"] = true;
			if(man.ataka == man.hand && (man.x - 30) < b->x && (man.x + 30)>b->x)b->key["getFace"] = true;
			if(man.ataka == man.foot && (man.x - 30) < b->x && (man.x + 30)>b->x)b->key["fall"] = true;
		}
		for(it = enemys.begin();it !=enemys.end();it++)
			(*it)->update(time,window);
			
		man.update(time,window);
		window.display();
	}
}