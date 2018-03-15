/*
** Parallelepiped.cpp for RTechnology in
**
** Made by auguste.larrive-jahan@epitech.eu
** Login   <auguste.larrive-jahan@epitech.eu>
**
** Started on  jeu. janv. 15:42 2018 each
** Last update jeu. janv. 15:42 2018 each
*/

#include "Parallelepiped.hpp"
#include "../SceneManager.hpp"

RT_NAMESPACE_BEGIN

  Parallelepiped::Parallelepiped()
  {}

  Parallelepiped::Parallelepiped(const Vector3F &pos) : Object(pos)
  {}

  Parallelepiped::Parallelepiped(const Vector3F &pos, const Vector3F &rot) : Object(pos, rot)
  {}

  Parallelepiped::Parallelepiped(const Vector3F &pos, const Vector3F &rot, const Vector3F &scal) : Object(pos, rot, scal)
  {}

  Parallelepiped::~Parallelepiped()
  {}

  Object::HitInfo Parallelepiped::Hit(const Ray &ray, const SceneManager &manager)
  {
    return HitInfo();
  }

  Color Parallelepiped::getColorHit(const HitInfo &info, const SceneManager &manager)
  {
    Color color(255, 0, 0);

    for (auto &l : manager.getLights())
      {
	Ray my_ray(info.hitPosition, l->getPosition() - info.hitPosition);
	auto objectHit = manager.checkHit(my_ray);
	if (objectHit.haveHit && objectHit.hitObject != this)
	  return Color();
	auto angle = Vector3F::Angle(info.normal, my_ray.getDirection());
	if (angle >= af::Pi / 2)
	  return Color();
	float coeff = angle / (af::Pi / 2);
	color.r = color.r - (color.r * coeff);
	color.g = color.g - (color.g * coeff);
	color.b = color.b - (color.b * coeff);

	auto angleSpec = Vector3F::Angle(info.reflect, my_ray.getDirection());
	if (angleSpec < af::Pi / 20)
	  {
	    float coeffSpec = angleSpec / (af::Pi / 20);
	    color.r = 255 - (255 - color.r) * coeffSpec;
	    color.g = 255 - (255 - color.g) * coeffSpec;
	    color.b = 255 - (255 - color.b) * coeffSpec;
	  }
      }
    return color;
  }

  void Parallelepiped::setWidth(const float &width)
  {
    this->_width = width;
  }

  void Parallelepiped::setHeight(const float &height)
  {
    this->_height = height;
  }

  void Parallelepiped::setLength(const float &length)
  {
    this->_length = length;
  }

RT_NAMESPACE_END

