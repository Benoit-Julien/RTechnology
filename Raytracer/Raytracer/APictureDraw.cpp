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

RT_NAMESPACE_BEGIN

  APictureDraw::APictureDraw(const std::size_t &width, const std::size_t &height)
	  : height(height),
	    width(width)
  {}

  void APictureDraw::setPixel(const Vector2I &position, const Color &pixColor)
  {
    std::lock_guard<std::mutex> lock(this->_mutex);

    this->_setPixel(position, pixColor);
  }

  void APictureDraw::drawPicture(const std::vector<std::vector<Color>> &picture)
  {
    std::lock_guard<std::mutex> lock(this->_mutex);

    this->_drawPicture(picture);
  }

RT_NAMESPACE_END