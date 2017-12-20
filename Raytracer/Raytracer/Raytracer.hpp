/*
** Raytracer.hpp for RTechnology in
**
** Made by julien1.benoit@epitech.eu
** Login   <julien1.benoit@epitech.eu>
**
** Started on  mer. déc. 15:28 2017 benoit_g
** Last update mer. déc. 15:28 2017 benoit_g
*/

#ifndef RTECHNOLOGY_RAYTRACER_HPP
#define RTECHNOLOGY_RAYTRACER_HPP

#include <memory>
#include <string>

#include "APictureDraw.hpp"

class Raytracer
{
  std::shared_ptr<APictureDraw> _drawer;

 public:
  explicit Raytracer(std::shared_ptr<APictureDraw> drawer);
  Raytracer(const Raytracer &raytracer) = delete;
  Raytracer(Raytracer &&raytracer) noexcept = delete;
  Raytracer &operator=(const Raytracer &raytracer) = delete;
  Raytracer &operator=(Raytracer &&raytracer) noexcept = delete;
  ~Raytracer() = default;

  void renderer();
  void initialiseScene(const std::string &json);
};


#endif /* !RTECHNOLOGY_RAYTRACER_HPP */
