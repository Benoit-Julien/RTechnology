/*
** Light.hpp for RTechnology in
**
** Made by julien1.benoit@epitech.eu
** Login   <julien1.benoit@epitech.eu>
**
** Started on  sam. févr. 15:42 2018 benoit_g
** Last update sam. févr. 15:42 2018 benoit_g
*/

#ifndef RTECHNOLOGY_RT_LIGHT_HPP
#define RTECHNOLOGY_RT_LIGHT_HPP

#include "math/Vector3.hpp"
#include "Color.hpp"

RT_NAMESPACE_BEGIN

  class Light
  {
   public:
    enum class Type
    {
      POINT
    };

   private:
    Type _type;
    const Vector3F _position;
    const Vector3F _rotation;
    Color _color;

   public:
    explicit Light();
    explicit Light(const Vector3F &position);
    Light(const Vector3F &position, const Vector3F &rotation);
    Light(const Light &light);
    Light(Light &&light) noexcept;
    Light &operator=(const Light &light);
    Light &operator=(Light &&light) noexcept;
    ~Light();

    void setType(const Type &type);
    const Type &getType() const;

    void setColor(const Color &color);
    const Color &getColor() const;

    const Vector3F &getPosition() const;
    const Vector3F &getRotation() const;
  };

RT_NAMESPACE_END

#endif /* !RTECHNOLOGY_RT_LIGHT_HPP */
