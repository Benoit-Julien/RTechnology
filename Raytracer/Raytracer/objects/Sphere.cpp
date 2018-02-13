/*
** Sphere.cpp for RTechnology in
**
** Made by auguste.larrive-jahan@epitech.eu
** Login   <auguste.larrive-jahan@epitech.eu>
**
** Started on  mer. janv. 16:16 2018 each
** Last update mer. janv. 16:16 2018 each
*/

#include "../SceneManager.hpp"
#include "Sphere.hpp"

Sphere::Sphere()
	: _radius(1)
{}

Sphere::Sphere(const Vector3F &pos)
	: Object(pos),
	  _radius(1)
{}

Sphere::Sphere(const Vector3F &pos, const Vector3F &rot)
	: Object(pos, rot),
	  _radius(1)
{}

Sphere::Sphere(const Vector3F &pos, const Vector3F &rot, const Vector3F &scal)
	: Object(pos, rot, scal),
	  _radius(1)
{}

Sphere::~Sphere()
{}

Object::HitInfo Sphere::Hit(const Ray &ray, const SceneManager &manager)
{
  const auto &V = ray.getDirection();
  const auto &C = ray.getOrigin();
  const auto &O = this->position;


  float a = V.magnitude();
  float b = 2 * (V.x() * (O.x() - C.x()) + V.y() * (O.y() - C.y()) + V.z() * (O.z() - C.z()));
  float c = ((O - C) ^ 2) - this->_radius * this->_radius;

  float det;
  /*if (a == 0.25f)
    det = b * b - 4*c;
  else*/
  det = b * b - 4 * a * c;

  HitInfo info;
  float k = this->checkDelta(a, b, det);
  if (k > 0)
    {
      info.haveHit = true;
      info.hitObject = this;
      info.distance = k;
      info.hitPosition = C + V * k;
    }
  else
    info.haveHit = false;

  return info;
}

/*
 * On va ici calculer la couleur de retour de l'objet,
 * Pour ça on crée un rayon entre le point d'impact du rayon et chaque lumière
 * On regarde si il n'y a rien entre le point d'impact et la lumière
 * Création du vecteur normal pour une sphère
 *
 */
Color Sphere::getColorHit(const HitInfo &info, const SceneManager &manager)
{
  Color color(255, 0, 0);

  for (auto &l : manager.getLights())
    {
      Ray my_ray(info.hitPosition, info.hitPosition - l->getPosition());
      auto objectHit = manager.checkHit(my_ray);
      if (objectHit.haveHit && objectHit.hitObject != this)
	return Color();
      Vector3F normal = info.hitPosition - this->position;
      auto angle = Vector3F::Angle(normal, my_ray.getDirection());
      std::cout << "angle = " << angle << std::endl;
      if (angle >= af::Pi / 2)
	return Color();
      color.r = color.r - (color.r * angle / (af::Pi / 2));
      color.g = color.g - (color.g * angle / (af::Pi / 2));
      color.b = color.b - (color.b * angle / (af::Pi / 2));
    }
  return color;
}

float Sphere::checkDelta(const float &a, const float &b, const float &delta)
{
  float s1;
  float s2;

  if (delta > 0)
    {
      s1 = (-b + std::sqrt(delta)) / (2 * a);
      s2 = (-b - std::sqrt(delta)) / (2 * a);
      if (s2 > s1)
	{
	  if (s1 > 0)
	    return s1;
	  else
	    return s2;
	}
      else
	{
	  if (s2 > 0)
	    return s2;
	  else
	    return s1;
	}
    }
  return -1;
}

void Sphere::setRadius(const float &radius)
{
  this->_radius = radius;
}