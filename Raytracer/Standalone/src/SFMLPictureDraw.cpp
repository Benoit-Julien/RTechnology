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

SFMLPictureDraw::SFMLPictureDraw(const std::size_t &width, const std::size_t &height)
	: APictureDraw(width, height),
	  _window(sf::VideoMode((unsigned int)width, (unsigned int)height), "Raytracer"),
	  _array(sf::Points, width * height)
{
  for (auto y = 0; y < height; y++)
    for (auto x = 0; x < width; x++)
      {
	this->_array[y * width + x].position = sf::Vector2f(x, y);
	this->_array[y * width + x].color = sf::Color::Black;
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

void SFMLPictureDraw::_setPixel(const rt::Vector2I &position, const rt::Color &pixColor)
{
  this->_array[position.y() * this->width + position.x()].color = sf::Color(pixColor.r, pixColor.g, pixColor.b);
}

void SFMLPictureDraw::_drawPicture(const std::vector<std::vector<rt::Color>> &picture)
{
  for (auto y = 0; y < this->height; y++)
    for (auto x = 0; x < this->width; x++)
      {
	auto color = picture[y][x];
	this->_array[y * this->width + x].color = sf::Color(color.r, color.g, color.b);
      }
}