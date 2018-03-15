/*
** QOpenGLPictureDraw.hpp for RTechnology in
**
** Made by julien1.benoit@epitech.eu
** Login   <julien1.benoit@epitech.eu>
**
** Started on  sam. mars 16:00 2018 benoit_g
** Last update sam. mars 16:00 2018 benoit_g
*/

#ifndef RTECHNOLOGY_QOPENGLPICTUREDRAW_HPP
#define RTECHNOLOGY_QOPENGLPICTUREDRAW_HPP

#include <memory>
#include <Raytracer/APictureDraw.hpp>

class MyGLWidget;

class QOpenGLPictureDraw : public rt::APictureDraw
{
  std::shared_ptr<QImage> _image;

 public:
  explicit QOpenGLPictureDraw(std::shared_ptr<QImage> image);
  virtual ~QOpenGLPictureDraw();

 protected:
  virtual void _setPixel(const rt::Vector2I &position, const rt::Color &pixColor);
  virtual void _drawPicture(const std::vector<std::vector<rt::Color>> &picture);
};


#endif /* !RTECHNOLOGY_QOPENGLPICTUREDRAW_HPP */
