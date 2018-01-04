/*
** SemiConeTop.hpp for RTechnology in
**
** Made by auguste.larrive-jahan@epitech.eu
** Login   <auguste.larrive-jahan@epitech.eu>
**
** Started on  mer. janv. 17:03 2018 each
** Last update mer. janv. 17:03 2018 each
*/

#ifndef RTECHNOLOGY_SEMICONETOP_HPP
#define RTECHNOLOGY_SEMICONETOP_HPP

#include "../Object.hpp"

class SemiConeTop : public Object
{
  float angle;
 public:
  explicit SemiConeTop();
  explicit SemiConeTop(const Vector3Float &pos);
  SemiConeTop(const Vector3Float &pos, const Vector3Float &rot);
  SemiConeTop(const Vector3Float &pos, const Vector3Float &rot, const Vector3Float &scal);
  virtual ~SemiConeTop();

  virtual bool Hit(const Ray &ray);
  virtual Color GetColorHit() const;
  void setAngle(const float &angle);
};


#endif /* !RTECHNOLOGY_SEMICONETOP_HPP */
