/*
** SceneSettings.hpp for RTechnology in
**
** Made by julien1.benoit@epitech.eu
** Login   <julien1.benoit@epitech.eu>
**
** Started on  mar. janv. 12:44 2018 benoit_g
** Last update mar. janv. 12:44 2018 benoit_g
*/

#ifndef RTECHNOLOGY_SCENESETTINGS_HPP
#define RTECHNOLOGY_SCENESETTINGS_HPP

#include <rapidjson/document.h>
#include <unordered_map>
#include <functional>

#include "config.h"

class SceneSettings
{
 public:
  struct Settings
  {
    Vector3Float cameraPosition;
    Vector3Float cameraRotation;
    int defaultLight;

    explicit Settings();
    Settings(const Settings &settings);
    Settings(Settings &&settings) noexcept;
    Settings &operator=(const Settings &settings);
    Settings &operator=(Settings &&settings) noexcept;
    ~Settings();
  };

 private:
  typedef void (SceneSettings::*SetSettingFuncType)(const rapidjson::GenericValue<rapidjson::UTF8<char>> &);

  Settings _settings;
  std::unordered_map<std::string, SetSettingFuncType> _map;

 public:
  explicit SceneSettings();
  SceneSettings(const SceneSettings &settings) = delete;
  SceneSettings(SceneSettings &&settings) noexcept = delete;
  SceneSettings &operator=(const SceneSettings &settings) = delete;
  SceneSettings &operator=(SceneSettings &&settings) noexcept = delete;
  ~SceneSettings();

  const Settings &getSettings() const;
  void setSetting(const std::string &name, const rapidjson::GenericValue<rapidjson::UTF8<>> &value);

 private:
  void setDefaultLight(const rapidjson::GenericValue<rapidjson::UTF8<>> &value);
  void setCameraPosition(const rapidjson::GenericValue<rapidjson::UTF8<>> &value);
  void setCameraRotation(const rapidjson::GenericValue<rapidjson::UTF8<>> &value);
};

#endif /* !RTECHNOLOGY_SCENESETTINGS_HPP */
