/*
** APictureDraw.hpp for RTechnology in
**
** Made by julien1.benoit@epitech.eu
** Login   <julien1.benoit@epitech.eu>
**
** Started on  mer. déc. 10:39 2017 benoit_g
** Last update mer. déc. 10:39 2017 benoit_g
*/

#ifndef RTECHNOLOGY_APICTUREDRAW_HPP
#define RTECHNOLOGY_APICTUREDRAW_HPP

#include <string>
#include <mutex>
#include <Raytracer/math/Vector2.hpp>

#include "config.h"
#include "Color.hpp"

class APictureDraw
{
  std::mutex _mutex;

 protected:
  const std::size_t height;
  const std::size_t width;

 public:
  APictureDraw(const std::size_t &height, const std::size_t &width);
  APictureDraw(const APictureDraw &draw) = delete;
  APictureDraw(APictureDraw &&draw) noexcept = delete;
  APictureDraw &operator=(const APictureDraw &draw) = delete;
  APictureDraw &operator=(APictureDraw &&draw) noexcept = delete;
  virtual ~APictureDraw() = default;

  const std::size_t &getHeight() const;
  const std::size_t &getWidth() const;

  void setPixel(const Vector2Int &position, const Color &pixColor);

 protected:
  virtual void _setPixel(const Vector2Int &position, const Color &pixColor) = 0;
};

#endif /* !RTECHNOLOGY_APICTUREDRAW_HPP */
