/*
** APictureDraw.hpp for RTechnology in
**
** Made by julien1.benoit@epitech.eu
** Login   <julien1.benoit@epitech.eu>
**
** Started on  mer. déc. 10:39 2017 benoit_g
** Last update mer. déc. 10:39 2017 benoit_g
*/

#ifndef RTECHNOLOGY_RT_APICTUREDRAW_HPP
#define RTECHNOLOGY_RT_APICTUREDRAW_HPP

#include <string>
#include <mutex>
#include <Raytracer/math/Vector2.hpp>

#include "config.h"
#include "Color.hpp"

RT_NAMESPACE_BEGIN

  class RT_DLL APictureDraw
  {
    std::mutex _mutex;

   protected:
    std::size_t height;
    std::size_t width;

   public:
    APictureDraw(const std::size_t &width, const std::size_t &height);
    APictureDraw(const APictureDraw &draw) = delete;
    APictureDraw(APictureDraw &&draw) noexcept = delete;
    APictureDraw &operator=(const APictureDraw &draw) = delete;
    APictureDraw &operator=(APictureDraw &&draw) noexcept = delete;
    virtual ~APictureDraw() = default;

    inline const std::size_t &getHeight() const
    { return this->height; }

    const std::size_t &getWidth() const
    { return this->width; }

    void setHeight(const std::size_t &height)
    { this->height = height; }

    void setWidth(const std::size_t &width)
    { this->width = width; }

    void setPixel(const Vector2I &position, const Color &pixColor);
    void drawPicture(const std::vector<std::vector<Color>> &picture);

   protected:
    virtual void _setPixel(const Vector2I &position, const Color &pixColor) = 0;
    virtual void _drawPicture(const std::vector<std::vector<Color>> &picture) = 0;
  };

RT_NAMESPACE_END

#endif /* !RTECHNOLOGY_RT_APICTUREDRAW_HPP */
