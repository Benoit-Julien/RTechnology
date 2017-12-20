/*
** SFMLPictureDraw.cpp for RTechnology in
**
** Made by julien1.benoit@epitech.eu
** Login   <julien1.benoit@epitech.eu>
**
** Started on  mer. déc. 11:03 2017 benoit_g
** Last update mer. déc. 11:03 2017 benoit_g
*/

#include "SFMLPictureDraw.hpp"

SFMLPictureDraw::SFMLPictureDraw(const std::size_t &height, const std::size_t &width)
	: APictureDraw(height, width),
	  _window(sf::VideoMode((unsigned int)height, (unsigned int)width), "Raytracer"),
	  _array(sf::Points, height * width)
{
  for (auto y = 0; y < width; y++)
    for (auto x = 0; x < height; x++)
      {
	this->_array[y * height + x].position = sf::Vector2f(x, y);
	this->_array[y * height + x].color = sf::Color::Black;
      }
}

bool SFMLPictureDraw::windowIsOpen()
{
  if (!this->_window.isOpen())
    return false;

  sf::Event event;
  while (this->_window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
	return false;
    }
  return true;
}

void SFMLPictureDraw::updateWindow()
{
  this->_window.clear();
  this->_window.draw(this->_array);
  this->_window.display();
}

void SFMLPictureDraw::_setPixel(const Vector2Int &position, const Color &pixColor)
{
  this->_array[position.y() * this->height + position.x()].color = sf::Color(pixColor.r, pixColor.g, pixColor.b);
}