/*
** SceneSettings.cpp for RTechnology in
**
** Made by julien1.benoit@epitech.eu
** Login   <julien1.benoit@epitech.eu>
**
** Started on  mar. janv. 12:44 2018 benoit_g
** Last update mar. janv. 12:44 2018 benoit_g
*/

#include "SceneSettings.hpp"

SceneSettings::Settings::Settings() : defaultLight(10)
{}

SceneSettings::Settings::Settings(const Settings &settings)
{}

SceneSettings::Settings::Settings(Settings &&settings) noexcept
{}

SceneSettings::Settings &SceneSettings::Settings::operator=(const Settings &settings)
{}

SceneSettings::Settings &SceneSettings::Settings::operator=(Settings &&settings) noexcept
{}

SceneSettings::Settings::~Settings()
{}


SceneSettings::SceneSettings()
{
  this->_map = {
	  {"defaultLight", &SceneSettings::setDefaultLight},
  };
}

SceneSettings::~SceneSettings()
{}

const SceneSettings::Settings &SceneSettings::getSettings() const
{
  return this->_settings;
}

void SceneSettings::setSetting(const std::string &name, const rapidjson::GenericValue<rapidjson::UTF8<>> &value)
{
  auto it = this->_map.find(name);

  if (it != this->_map.end())
    (this->*it->second)(value);
}

void SceneSettings::setDefaultLight(const rapidjson::GenericValue<rapidjson::UTF8<>> &value)
{
  assert(value.IsInt());
  this->_settings.defaultLight = value.GetInt();
}