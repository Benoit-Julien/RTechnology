/*
** Light.cpp for RTechnology in
**
** Made by julien1.benoit@epitech.eu
** Login   <julien1.benoit@epitech.eu>
**
** Started on  sam. févr. 15:42 2018 benoit_g
** Last update sam. févr. 15:42 2018 benoit_g
*/

#include "Light.hpp"

RT_NAMESPACE_BEGIN

  Light::Light()
	  : _type(Type::POINT),
	    _color(Color::White)
  {}

  Light::Light(const Vector3F &position)
	  : _type(Type::POINT),
	    _position(position),
	    _color(Color::White)
  {}

  Light::Light(const Vector3F &position, const Vector3F &rotation)
	  : _type(Type::POINT),
	    _position(position),
	    _rotation(rotation),
	    _color(Color::White)
  {}

  Light::Light(const Light &light)
	  : _type(light._type),
	    _position(light._position),
	    _rotation(light._rotation),
	    _color(light._color)
  {}

  Light::Light(Light &&light) noexcept
	  : _type(light._type),
	    _position(light._position),
	    _rotation(light._rotation),
	    _color(light._color)
  {}

  Light &Light::operator=(const Light &light)
  {
    this->_color = light._color;
    this->_type = light._type;

    return *this;
  }

  Light &Light::operator=(Light &&light) noexcept
  {
    this->_color = light._color;
    this->_type = light._type;

    return *this;
  }

  Light::~Light()
  {}

  void Light::setType(const Type &type)
  {
    this->_type = type;
  }

  const Light::Type &Light::getType() const
  {
    return this->_type;
  }

  void Light::setColor(const Color &color)
  {
    this->_color = color;
  }

  const Color &Light::getColor() const
  {
    return this->_color;
  }

  const Vector3F &Light::getPosition() const
  {
    return this->_position;
  }

  const Vector3F &Light::getRotation() const
  {
    return this->_rotation;
  }

RT_NAMESPACE_END