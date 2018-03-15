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
#include <mutex>
#include <condition_variable>
#include <thread>
#include <queue>

#include "ModelParcer/ModelParcer.hpp"
#include "Raytracer.hpp"

/*
#ifdef LINUX

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#else
#endif
*/

#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

bool useGraphics = false;

RT_NAMESPACE_BEGIN

  Raytracer::Raytracer(std::shared_ptr<APictureDraw> drawer, const bool &useThreads)
	  : _useThreads(useThreads), _drawer(drawer), _stop(false)
  {
    this->_manager = std::make_shared<SceneManager>();
  }

  Raytracer::~Raytracer()
  {
    this->stop();
  }

  void Raytracer::reset()
  {
    this->stop();
    this->_stop = false;
    this->_manager = std::make_shared<SceneManager>();
  }

  void Raytracer::start()
  {
    const auto &height = this->_drawer->getHeight();
    const auto &width = this->_drawer->getWidth();

    if (this->_useThreads)
      {
	this->_threads[0] = std::thread(&Raytracer::handleThreadFunction, this, Vector2I(0, 0), Vector2I(width / 2, height / 2));
	this->_threads[1] = std::thread(&Raytracer::handleThreadFunction, this, Vector2I(width / 2, 0), Vector2I(width, height / 2));
	this->_threads[2] = std::thread(&Raytracer::handleThreadFunction, this, Vector2I(0, height / 2), Vector2I(width / 2, height));
	this->_threads[3] = std::thread(&Raytracer::handleThreadFunction, this, Vector2I(width / 2, height / 2), Vector2I(width, height));
      }
    else
      this->handleThreadFunction(Vector2I(0, 0), Vector2I(width, height));
  }

  void Raytracer::stop()
  {
    if (!this->_useThreads)
      return;

    this->_stop = true;
    for (auto &t : this->_threads)
      {
	if (t.joinable())
	  t.join();
      }
  }

  void Raytracer::initialiseScene(const std::string &json)
  {
    rapidjson::Document doc;
    doc.Parse(json.c_str());
    this->_manager->parseSceneJson(doc);
  }

  void Raytracer::initialiseScene(const rapidjson::Document &doc)
  {
    rapidjson::StringBuffer buffer;
    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
    doc.Accept(writer);
    // Output {"project":"rapidjson","stars":11}
    std::cout << buffer.GetString() << std::endl;
    this->_manager->parseSceneJson(doc);
  }

  void Raytracer::setScenePath(const std::string &path)
  {
    ModelParcer::getSingleton().setScenePath(path);
  }

  void Raytracer::handleThreadFunction(const Vector2I &begin, const Vector2I &end)
  {
    const auto &settings = this->_manager->getSceneSettings().getSettings();
    auto &camPos = settings.cameraPosition;
    Vector3F PtLook = camPos + Vector3F::forward;
    Vector3F H = Vector3F::up;

    Vector3F U = PtLook - camPos;
    Vector3F D = Vector3F::Cross(U, H);

    Vector3F PosHGView_PosC = U * settings.viewPlaneDistance
				     + H * (settings.viewPlaneHeight / 2)
				     - D * (settings.viewPlaneWidth / 2);

    Vector3F Dxvpwd2 = D * (settings.viewPlaneWidth / this->_drawer->getWidth());
    Vector3F Hxvphd2 = H * (settings.viewPlaneHeight / this->_drawer->getHeight());

    for (auto y = begin.y(); y < end.y(); y++)
      for (auto x = begin.x(); x < end.x(); x++)
	{
	  if (this->_stop)
	    return;
  Vector3F V = PosHGView_PosC + Dxvpwd2 * x - Hxvphd2 * y;
	V = V.normalized();
	Ray ray(camPos, V);
	Color color = this->_manager->checkHitAndGetColor(ray);
	this->_drawer->setPixel(Vector2I(x, y), color);
	  //std::cout << "x: " << x << " y: " << y << std::endl;
	}
  }

/*
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

void Raytracer::activateGraphicCard()
{
  af::setBackend(af::Backend::AF_BACKEND_DEFAULT);
}

void Raytracer::deactivateGraphicCard()
{
  af::setBackend(af::Backend::AF_BACKEND_CPU);
}

#else
bool Raytracer::testArrayFire()
{
  return false;
}
#endif
*/
RT_NAMESPACE_END

void __attribute__ ((constructor)) setup()
{
  af::setBackend(af::Backend::AF_BACKEND_CPU);
}