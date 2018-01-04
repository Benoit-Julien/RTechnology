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

#include "Raytracer.hpp"
/*
#ifdef LINUX

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#else
#endif
*/

Raytracer::Raytracer(std::shared_ptr<APictureDraw> drawer)
	: _drawer(drawer)
{}

void Raytracer::renderer()
{
  auto &cameraPosition = this->_manager.getSceneSettings().getSettings().cameraPosition;
  float viewPlaneDist = 1.0;
  float viewPlaneHeight = 0.35;
  float viewPlaneWidth = 0.5;
  float xIndent = viewPlaneWidth / static_cast<float>(this->_drawer->getWidth());
  float yIndent = viewPlaneHeight / static_cast<float>(this->_drawer->getHeight());
  Vector3Float viewPlaneUpLeft = cameraPosition + ((Vector3Float::forward * viewPlaneDist) + (Vector3Float::up * (viewPlaneHeight / 2.0f))) - (Vector3Float::right * (viewPlaneWidth / 2.0f));
  std::queue<Vector2Int> tasks;
  bool stop = false;
  std::mutex mutex;
  std::condition_variable cv;

  auto func = [&]()
  {
    af::setBackend(af::Backend::AF_BACKEND_CPU);
    while (!stop || !tasks.empty())
      {
	std::unique_lock<std::mutex> lck(mutex);
	cv.wait(lck);
	if (tasks.empty())
	  continue;

	auto task = tasks.front();
	tasks.pop();
	std::cout << "x: " << task.x() << " y: " << task.y() << std::endl;
	lck.unlock();

	Vector3Float direction = viewPlaneUpLeft + Vector3Float::right * xIndent * task.x() - Vector3Float::up * yIndent * task.y();
	Ray ray(cameraPosition, direction);

	this->_drawer->setPixel(task, this->_manager.checkHitAndGetColor(ray));
      }
  };

  std::cout << af::getActiveBackend() << std::endl;


  std::array<std::thread, 4> threads;
  for (auto i = 0; i < threads.size(); i++)
    threads[i] = std::thread(func);

  for (auto y = 0; y < this->_drawer->getWidth(); y++)
    for (auto x = 0; x < this->_drawer->getHeight(); x++)
      {
	tasks.push(Vector2Int(x, y));
	cv.notify_all();
      }
  stop = true;

  for (auto &t : threads)
    t.join();

/*  for (auto y = 0; y < this->_drawer->getWidth(); y++)
    {
      for (auto x = 0; x < this->_drawer->getHeight(); x++)
	{
	  Vector3Float direction = viewPlaneUpLeft + Vector3Float::right * xIndent * x - Vector3Float::up * yIndent * y;
	  Ray ray(cameraPosition, direction);
	  this->_drawer->setPixel(Vector2Int(x, y), Color(255, 0, 0));
	}
    }*/
}

void Raytracer::initialiseScene(const std::string &json)
{
  rapidjson::Document doc;
  doc.Parse(json.c_str());
  this->_manager.parseSceneJson(doc);
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

void __attribute__ ((constructor)) setup()
{
  af::setBackend(af::Backend::AF_BACKEND_CPU);
}