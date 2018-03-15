/*
** Raytracer.hpp for RTechnology in
**
** Made by julien1.benoit@epitech.eu
** Login   <julien1.benoit@epitech.eu>
**
** Started on  mer. déc. 15:28 2017 benoit_g
** Last update mer. déc. 15:28 2017 benoit_g
*/

#ifndef RTECHNOLOGY_RT_RAYTRACER_HPP
#define RTECHNOLOGY_RT_RAYTRACER_HPP

#include <memory>
#include <string>
#include <thread>
#include <array>

#include "APictureDraw.hpp"
#include "SceneManager.hpp"

RT_NAMESPACE_BEGIN

  class RT_DLL Raytracer
  {
    const bool _useThreads;

    std::shared_ptr<SceneManager> _manager;
    std::shared_ptr<APictureDraw> _drawer;
    bool _stop;
    std::array<std::thread, 4> _threads;

   public:
    Raytracer(std::shared_ptr<APictureDraw> drawer, const bool &useThreads);
    Raytracer(const Raytracer &raytracer) = delete;
    Raytracer(Raytracer &&raytracer) noexcept = delete;
    Raytracer &operator=(const Raytracer &raytracer) = delete;
    Raytracer &operator=(Raytracer &&raytracer) noexcept = delete;
    ~Raytracer();

    void initialiseScene(const std::string &json);
    void initialiseScene(const rapidjson::Document &doc);
    void reset();
    void start();
    void stop();
    void setScenePath(const std::string &path);

   private:
    void handleThreadFunction(const Vector2I &begin, const Vector2I &end);
  };

RT_NAMESPACE_END

#endif /* !RTECHNOLOGY_RT_RAYTRACER_HPP */
