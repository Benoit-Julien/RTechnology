/*
** SFMLPictureDraw.hpp for RTechnology in
**
** Made by julien1.benoit@epitech.eu
** Login   <julien1.benoit@epitech.eu>
**
** Started on  mer. déc. 11:03 2017 benoit_g
** Last update mer. déc. 11:03 2017 benoit_g
*/

#ifndef RTECHNOLOGY_SFMLPICTUREDRAW_HPP
#define RTECHNOLOGY_SFMLPICTUREDRAW_HPP

#include <Raytracer/APictureDraw.hpp>
#include <SFML/Graphics.hpp>

class SFMLPictureDraw : public rt::APictureDraw
{
  sf::RenderWindow _window;
  sf::VertexArray _array;

 public:
  SFMLPictureDraw(const std::size_t &width, const std::size_t &height);
  virtual ~SFMLPictureDraw() = default;

  bool windowIsOpen();
  void updateWindow();

 protected:
  virtual void _setPixel(const rt::Vector2I &position, const rt::Color &pixColor);
  virtual void _drawPicture(const std::vector<std::vector<rt::Color>> &picture);
};


#endif /* !RTECHNOLOGY_SFMLPICTUREDRAW_HPP */
