/*
** Model.hpp for RTechnology in
**
** Made by julien1.benoit@epitech.eu
** Login   <julien1.benoit@epitech.eu>
**
** Started on  mer. févr. 14:16 2018 benoit_g
** Last update mer. févr. 14:16 2018 benoit_g
*/

#ifndef RTECHNOLOGY_MODEL_HPP
#define RTECHNOLOGY_MODEL_HPP

#include "../Object.hpp"

class Model : public Object
{
 public:
  explicit Model();
  explicit Model(const Vector3F &pos);
  Model(const Vector3F &pos, const Vector3F &rot);
  Model(const Vector3F &pos, const Vector3F &rot, const Vector3F &scal);
  virtual ~Model();

  virtual HitInfo Hit(const Ray &ray, const SceneManager &manager);
  virtual Color getColorHit(const HitInfo &info, const SceneManager &manager);
};

#endif /* !RTECHNOLOGY_MODEL_HPP */
