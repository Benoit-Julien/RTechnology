/*
** SceneManager.hpp for RTechnology in
**
** Made by julien1.benoit@epitech.eu
** Login   <julien1.benoit@epitech.eu>
**
** Started on  mer. janv. 11:12 2018 benoit_g
** Last update mer. janv. 11:12 2018 benoit_g
*/

#ifndef RTECHNOLOGY_SCENEMANAGER_HPP
#define RTECHNOLOGY_SCENEMANAGER_HPP

#include <rapidjson/document.h>

#include "Object.hpp"
#include "Light.hpp"
#include "SceneSettings.hpp"

class SceneManager
{
 private:
  std::vector<std::shared_ptr<Object>> _objects;
  std::vector<std::shared_ptr<Light>> _lights;
  SceneSettings _settings;

 public:
  explicit SceneManager();
  SceneManager(const SceneManager &) = delete;
  SceneManager(SceneManager &&) noexcept = delete;
  SceneManager &operator=(const SceneManager &) = delete;
  SceneManager &operator=(SceneManager &&) noexcept = delete;
  ~SceneManager();

  const SceneSettings &getSceneSettings() const;
  const std::vector<std::shared_ptr<Object>> &getObjects() const;
  const std::vector<std::shared_ptr<Light>> &getLights() const;

  Color checkHitAndGetColor(const Ray &ray) const;

  void parseSceneJson(const rapidjson::Document &document);
  Object::HitInfo checkHit(const Ray &ray) const;

 private:
  void parseLights(rapidjson::Value::ConstArray lights);
  void parseObjects(rapidjson::Value::ConstArray objects);
  void parseAttributeObject(std::shared_ptr<Object> obj, rapidjson::Value::ConstArray attributes);

  static Vector3F getVector3Of(const std::string &name, rapidjson::Value::ConstObject params);
  static Color getColorOf(const std::string &name, rapidjson::Value::ConstObject params);
  static Light::Type getLightType(const std::string &name, rapidjson::Value::ConstObject params);
};


#endif /* !RTECHNOLOGY_SCENEMANAGER_HPP */
