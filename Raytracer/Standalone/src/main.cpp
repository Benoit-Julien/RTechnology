/*
** main.cpp for RTechnology in
**
** Made by julien1.benoit@epitech.eu
** Login   <julien1.benoit@epitech.eu>
**
** Started on  mar. nov. 21:05 2017 benoit_g
** Last update mar. nov. 21:05 2017 benoit_g
*/

#include <SFML/Graphics.hpp>
#include <Raytracer/Raytracer.h>

//TODO: Mettre ça dans un config.h

#if _WIN32 || _WIN64
# if _WIN64
#  define ENVIRONMENT64
# else
#  define ENVIRONMENT32
# endif
#endif

// Check GCC
#if __GNUC__
# if __x86_64__ || __ppc64__
#  define ENVIRONMENT64
# else
#  define ENVIRONMENT32
# endif
#endif

#if _WIN64 && !_DEBUG
# include <Windows.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
#else
int main()
#endif
{
  sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
  sf::CircleShape shape(100.f);
  shape.setFillColor(sf::Color::Green);
  entry_point();

  while (window.isOpen())
    {
      sf::Event event;
      while (window.pollEvent(event))
	{
	  if (event.type == sf::Event::Closed)
	    window.close();
	}

      window.clear();
      window.draw(shape);
      window.display();
    }

  return 0;
}