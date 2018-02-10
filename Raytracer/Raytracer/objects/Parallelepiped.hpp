/*
** Parallelepiped.hpp for RTechnology in
**
** Made by auguste.larrive-jahan@epitech.eu
** Login   <auguste.larrive-jahan@epitech.eu>
**
** Started on  jeu. janv. 15:42 2018 each
** Last update jeu. janv. 15:42 2018 each
*/

#ifndef RTECHNOLOGY_PARALLELEPIPED_HPP
#define RTECHNOLOGY_PARALLELEPIPED_HPP

#include "../Object.hpp"

class Parallelepiped : public Object
{
 public:
  explicit Parallelepiped();
  explicit Parallelepiped(const Vector3F &pos);
  Parallelepiped(const Vector3F &pos, const Vector3F &rot);
  Parallelepiped(const Vector3F &pos, const Vector3F &rot, const Vector3F &scal);
  virtual ~Parallelepiped();

  virtual HitInfo Hit(const Ray &ray, const SceneSettings &settings);
  virtual Color getColorHit(const HitInfo &info);
};


#endif /* !RTECHNOLOGY_PARALLELEPIPED_HPP */
