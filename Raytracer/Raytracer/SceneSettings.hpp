/*
** SceneSettings.hpp for RTechnology in
**
** Made by julien1.benoit@epitech.eu
** Login   <julien1.benoit@epitech.eu>
**
** Started on  mar. janv. 12:44 2018 benoit_g
** Last update mar. janv. 12:44 2018 benoit_g
*/

#ifndef RTECHNOLOGY_RT_SCENESETTINGS_HPP
#define RTECHNOLOGY_RT_SCENESETTINGS_HPP

#include <rapidjson/document.h>
#include <unordered_map>
#include <functional>

#include "config.h"

RT_NAMESPACE_BEGIN

  class SceneSettings
  {
   public:
    struct Settings
    {
      Vector3F cameraPosition;
      Vector3F cameraRotation;
      int defaultLight;
      float viewPlaneDistance;
      float viewPlaneWidth;
      float viewPlaneHeight;

      explicit Settings();
      Settings(const Settings &settings);
      Settings(Settings &&settings) noexcept;
      Settings &operator=(const Settings &settings);
      Settings &operator=(Settings &&settings) noexcept;
      ~Settings();
    };

   private:
    typedef void (SceneSettings::*SetSettingFuncType)(const rapidjson::Value &);

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
    void setSetting(const std::string &name, const rapidjson::Value &value);

   private:
    void setDefaultLight(const rapidjson::Value &value);
    void setCamera(const rapidjson::Value &value);
    void setViewPlaneDistance(const rapidjson::Value &value);
    void setViewPlaneWidth(const rapidjson::Value &value);
    void setViewPlaneHeight(const rapidjson::Value &value);
  };

RT_NAMESPACE_END

#endif /* !RTECHNOLOGY_RT_SCENESETTINGS_HPP */
