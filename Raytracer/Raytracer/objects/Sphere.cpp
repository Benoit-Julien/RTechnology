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
  static float r2 = this->_radius * this->_radius;
  const auto &V = ray.getDirection();
  const auto &C = ray.getOrigin();
  const auto &O = this->position;
  const auto OmC = O - C;

  float a = V.magnitude();
  float b = 2 * (V.x() * (OmC.x()) + V.y() * (OmC.y()) + V.z() * (OmC.z()));
  float c = (OmC^2) - r2;

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
      info.hitPosition = C + (V * k);
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
  Vector3F normal = info.hitPosition + this->position;

  for (auto &l : manager.getLights())
    {
      Ray my_ray(info.hitPosition, l->getPosition() - info.hitPosition);
      auto objectHit = manager.checkHit(my_ray);
      if (objectHit.haveHit && objectHit.hitObject != this)
	return Color();
      auto angle = Vector3F::Angle(normal, my_ray.getDirection());
      if (angle >= af::Pi / 2)
	return Color();
      float coeff = angle / (af::Pi / 2);
      color.r = color.r - (color.r * coeff);
      color.g = color.g - (color.g * coeff);
      color.b = color.b - (color.b * coeff);
    }
  return color;
}

void Sphere::setRadius(const float &radius)
{
  this->_radius = radius;
}