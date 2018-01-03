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
#include "SceneSettings.hpp"

class SceneManager
{
 private:
  std::vector<std::shared_ptr<Object>> _objects;
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

  void parseSceneJson(const rapidjson::Document &document);

 private:
  void parseObjects(rapidjson::GenericValue<rapidjson::UTF8<>>::ConstArray objects);
  void parseAttributeObject(std::shared_ptr<Object> obj, rapidjson::GenericValue<rapidjson::UTF8<>>::ConstArray attributes);
};


#endif /* !RTECHNOLOGY_SCENEMANAGER_HPP */
