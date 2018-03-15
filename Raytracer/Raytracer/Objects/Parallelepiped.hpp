/*
** Parallelepiped.hpp for RTechnology in
**
** Made by auguste.larrive-jahan@epitech.eu
** Login   <auguste.larrive-jahan@epitech.eu>
**
** Started on  jeu. janv. 15:42 2018 each
** Last update jeu. janv. 15:42 2018 each
*/

#ifndef RTECHNOLOGY_RT_PARALLELEPIPED_HPP
#define RTECHNOLOGY_RT_PARALLELEPIPED_HPP

#include "../Object.hpp"

RT_NAMESPACE_BEGIN
class Parallelepiped : public Object
{
  float _length;
  float _width;
  float _height;
 public:
  explicit Parallelepiped();
  explicit Parallelepiped(const Vector3F &pos);
  Parallelepiped(const Vector3F &pos, const Vector3F &rot);
  Parallelepiped(const Vector3F &pos, const Vector3F &rot, const Vector3F &scal);
  virtual ~Parallelepiped();

  virtual HitInfo Hit(const Ray &ray, const SceneManager &manager);
  virtual Color getColorHit(const HitInfo &info, const SceneManager &manager);

  void setLength(const float &length);
  void setWidth(const float &width);
  void setHeight(const float &height);
};
RT_NAMESPACE_END

#endif /* !RTECHNOLOGY_RT_PARALLELEPIPED_HPP */
