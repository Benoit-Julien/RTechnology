/*
** SemiConeTop.hpp for RTechnology in
**
** Made by auguste.larrive-jahan@epitech.eu
** Login   <auguste.larrive-jahan@epitech.eu>
**
** Started on  mer. janv. 17:03 2018 each
** Last update mer. janv. 17:03 2018 each
*/

#ifndef RTECHNOLOGY_RT_SEMICONETOP_HPP
#define RTECHNOLOGY_RT_SEMICONETOP_HPP

#include "../Object.hpp"

RT_NAMESPACE_BEGIN

  class SemiConeTop : public Object
  {
    float angle;
   public:
    explicit SemiConeTop();
    explicit SemiConeTop(const Vector3F &pos);
    SemiConeTop(const Vector3F &pos, const Vector3F &rot);
    SemiConeTop(const Vector3F &pos, const Vector3F &rot, const Vector3F &scal);
    virtual ~SemiConeTop();

    virtual HitInfo Hit(const Ray &ray, const SceneManager &manager);
    virtual Color getColorHit(const HitInfo &info, const SceneManager &manager);

    void setAngle(const float &angle);
  };

RT_NAMESPACE_END

#endif /* !RTECHNOLOGY_RT_SEMICONETOP_HPP */
