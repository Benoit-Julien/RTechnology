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

class SFMLPictureDraw : public APictureDraw
{
  sf::RenderWindow _window;
  sf::VertexArray _array;

 public:
  SFMLPictureDraw(const std::size_t &height, const std::size_t &width);
  virtual ~SFMLPictureDraw() = default;

  bool windowIsOpen();
  void updateWindow();

 protected:
  virtual void _setPixel(const Vector2I &position, const Color &pixColor);
  virtual void _drawPicture(const std::vector<std::vector<Color>> &picture);
};


#endif /* !RTECHNOLOGY_SFMLPICTUREDRAW_HPP */
