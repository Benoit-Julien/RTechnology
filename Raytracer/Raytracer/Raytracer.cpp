/*
** Raytracer.cpp for RTechnology in
**
** Made by julien1.benoit@epitech.eu
** Login   <julien1.benoit@epitech.eu>
**
** Started on  mer. déc. 15:28 2017 benoit_g
** Last update mer. déc. 15:28 2017 benoit_g
*/

#include "Raytracer.hpp"

Raytracer::Raytracer(std::shared_ptr<APictureDraw> drawer)
	: _drawer(drawer)
{}

void Raytracer::renderer()
{
  this->_drawer->setPixel(Vector2Int(50, 50), Color(255, 0, 0));
}

void Raytracer::initialiseScene(const std::string &json)
{}