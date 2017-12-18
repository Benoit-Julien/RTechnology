/*
** main.cpp for RTechnology in
**
** Made by julien1.benoit@epitech.eu
** Login   <julien1.benoit@epitech.eu>
**
** Started on  mar. nov. 21:05 2017 benoit_g
** Last update mar. nov. 21:05 2017 benoit_g
*/

#include <iostream>
#include <SFML/Graphics.hpp>
#include <Raytracer/Raytracer.h>
#include <Raytracer/config.h>

#include <Raytracer/math/Vector3.hpp>
#include <Raytracer/math/Vector2.hpp>

#if WINDOWS && !_DEBUG
# include <Windows.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
#else
int main()
#endif
{
  /*sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
  sf::CircleShape shape(100.f);
  shape.setFillColor(sf::Color::Green);
  std::cout << entry_point() << std::endl;

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

  return 0;*/

  Vector3Float vec(2.2, 3, 5);
  std::cout << vec << std::endl;

  float x = 3.2;

  vec.Set(x, 6, 9.62);
  std::cout << vec << std::endl;

  vec += 3;
  std::cout << vec << std::endl;

  vec -= 3;
  std::cout << vec << std::endl;

  vec *= 3;
  std::cout << vec << std::endl;

  vec /= 3;
  std::cout << vec << std::endl;

  std::cout << std::boolalpha << (vec == vec) << std::noboolalpha << std::endl;

  std::cout << std::boolalpha << (Vector3Int::up != Vector3Int::down) << std::noboolalpha << std::endl;

  std::cout << (Vector3Int::Angle(Vector3Int::forward, Vector3Int::left) * 180 / 3.14) << std::endl;



  Vector2Float vec2(2.2, 3);
  std::cout << vec2 << std::endl;

  vec2.Set(x, 6);
  std::cout << vec2 << std::endl;

  vec2 += 3;
  std::cout << vec2 << std::endl;

  vec2 -= 3;
  std::cout << vec2 << std::endl;

  vec2 *= 3;
  std::cout << vec2 << std::endl;

  vec2 /= 3;
  std::cout << vec2 << std::endl;

  std::cout << std::boolalpha << (vec2 == vec2) << std::noboolalpha << std::endl;

  std::cout << std::boolalpha << (Vector2Int::up != Vector2Int::down) << std::noboolalpha << std::endl;

  std::cout << (Vector2Int::Angle(Vector2Int::up, Vector2Int::left) * 180 / 3.14) << std::endl;
}