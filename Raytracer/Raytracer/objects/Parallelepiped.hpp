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
  explicit Parallelepiped(const Vector3Float &pos);
  Parallelepiped(const Vector3Float &pos, const Vector3Float &rot);
  Parallelepiped(const Vector3Float &pos, const Vector3Float &rot, const Vector3Float &scal);
  virtual ~Parallelepiped();

  virtual HitInfo Hit(const Ray &ray);
};


#endif /* !RTECHNOLOGY_PARALLELEPIPED_HPP */
