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

static double m1 = -1;
static double m2 = -1;
static double m3 = -1;
static double m4 = -1;
static double m5 = -1;

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
{
  printf("m1 = %.5f\n", m1);
  printf("m2 = %.5f\n", m2);
  printf("m3 = %.5f\n", m3);
  printf("m4 = %.5f\n", m4);
  printf("m5 = %.5f\n", m5);
}
#include <ctime>

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

  for (auto &l : manager.getLights())
    {
      Ray my_ray(info.hitPosition, l->getPosition() - info.hitPosition);
      auto objectHit = manager.checkHit(my_ray);
      if (objectHit.haveHit && objectHit.hitObject != this)
	return Color();
      Vector3F normal = info.hitPosition + this->position;
      //std::cout << "pos = " << this->position << std::endl;
      //std::cout << "hitpos = " << info.hitPosition << std::endl;
      //std::cout << "normal = " << normal << std::endl;
      //std::cout << "dir = " << my_ray.getDirection() << std::endl;
      auto angle = Vector3F::Angle(normal, my_ray.getDirection());
      //std::cout << "angle = " << angle * 180 / af::Pi << std::endl;
      if (angle >= af::Pi / 2)
	return Color();
      float coeff = angle / (af::Pi / 2);
      color.r = color.r - (color.r * coeff);
      color.g = color.g - (color.g * coeff);
      color.b = color.b - (color.b * coeff);
    }
  return color;
}

float Sphere::checkDelta(const float &a, const float &b, const float &delta)
{
  float s1;
  float s2;

  if (delta > 0)
    {
      float a2 = 2 * a;
      float sqrt_delta = std::sqrt(delta);
      s1 = (-b + sqrt_delta) / a2;
      s2 = (-b - sqrt_delta) / a2;
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