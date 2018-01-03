/*
** Raytracer.cpp for RTechnology in
**
** Made by julien1.benoit@epitech.eu
** Login   <julien1.benoit@epitech.eu>
**
** Started on  mer. déc. 15:28 2017 benoit_g
** Last update mer. déc. 15:28 2017 benoit_g
*/

#include <rapidjson/document.h>

#include "Raytracer.hpp"

#ifdef LINUX
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#else
#endif

Raytracer::Raytracer(std::shared_ptr<APictureDraw> drawer, const bool &useGraphicCard)
	: _drawer(drawer)
{
  if (!useGraphicCard)
    af::setBackend(AF_BACKEND_CPU);
}

void Raytracer::renderer()
{
  this->_drawer->setPixel(Vector2Int(50, 50), Color(255, 0, 0));
}

void Raytracer::initialiseScene(const std::string &json)
{
  rapidjson::Document doc;
  doc.Parse(json.c_str());
  try
    {
      this->_manager.parseSceneJson(doc);
    }
  catch (std::exception)
    {
    }
}

#ifdef LINUX
bool Raytracer::testArrayFire()
{
  pid_t childIp = fork();
  int status;

  if (childIp == -1)
    return false;
  else if (childIp == 0)
    {
      af::array array1 = af::constant(0, 3);
      af::array array2 = af::constant(1, 3);

      auto result = array1 * array2;
      std::exit(0);
    }

  if (waitpid(childIp, &status, 0) == -1)
    return false;
  else if (WIFEXITED(status) && WEXITSTATUS(status) == 0)
    return true;

  return false;
}
#else
bool Raytracer::testArrayFire()
{
  return false;
}
#endif