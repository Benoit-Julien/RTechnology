/*
** APictureDraw.cpp for RTechnology in
**
** Made by julien1.benoit@epitech.eu
** Login   <julien1.benoit@epitech.eu>
**
** Started on  mer. déc. 10:39 2017 benoit_g
** Last update mer. déc. 10:39 2017 benoit_g
*/

#include "APictureDraw.hpp"

APictureDraw::APictureDraw(const std::size_t &height, const std::size_t &width)
	: height(height),
	  width(width)
{}

const std::size_t &APictureDraw::getHeight() const
{
  return this->height;
}

const std::size_t &APictureDraw::getWidth() const
{
  return this->width;
}

void APictureDraw::setPixel(const Vector2Int &position, const Color &pixColor)
{
  //std::lock_guard<std::mutex> lock(this->_mutex);

  this->_setPixel(position, pixColor);
}