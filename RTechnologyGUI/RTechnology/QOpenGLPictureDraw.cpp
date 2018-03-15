/*
** QOpenGLPictureDraw.cpp for RTechnology in
**
** Made by julien1.benoit@epitech.eu
** Login   <julien1.benoit@epitech.eu>
**
** Started on  sam. mars 16:00 2018 benoit_g
** Last update sam. mars 16:00 2018 benoit_g
*/

#include <QOpenGLFunctions>
#include <QOpenGLContext>
#include "QOpenGLPictureDraw.hpp"
#include "MyGLWidget.hpp"

QOpenGLPictureDraw::QOpenGLPictureDraw(std::shared_ptr<QImage> image)
	: rt::APictureDraw(1280, 720), _image(image)
{}

QOpenGLPictureDraw::~QOpenGLPictureDraw()
{}

void QOpenGLPictureDraw::_setPixel(const rt::Vector2I &position, const rt::Color &pixColor)
{
  this->_image->setPixelColor(position.x(), position.y(), QColor(pixColor.r, pixColor.g, pixColor.b));
}

void QOpenGLPictureDraw::_drawPicture(const std::vector<std::vector<rt::Color>> &picture)
{}