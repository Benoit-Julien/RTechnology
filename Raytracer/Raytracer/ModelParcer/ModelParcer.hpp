/*
** ModelParcer.hpp for RTechnology in
**
** Made by julien1.benoit@epitech.eu
** Login   <julien1.benoit@epitech.eu>
**
** Started on  mer. févr. 14:00 2018 benoit_g
** Last update mer. févr. 14:00 2018 benoit_g
*/

#ifndef RTECHNOLOGY_MODELPARCER_HPP
#define RTECHNOLOGY_MODELPARCER_HPP

#include <unordered_map>
#include "A3DModel.hpp"
#include "../config.h"

class RT_DLL ModelParcer
{
  static std::unordered_map<std::string, bool (ModelParcer::*)(const std::string &)> _loaders;
  std::unordered_map<std::string, std::shared_ptr<A3DModel>> _models;
  std::string _scenePath;

 private:
  ModelParcer();

 public:
  ~ModelParcer();
  ModelParcer(const ModelParcer &) = delete;
  ModelParcer(ModelParcer &&) noexcept = delete;
  ModelParcer &operator=(const ModelParcer &) = delete;
  ModelParcer &operator=(ModelParcer &&) noexcept = delete;

  static ModelParcer &getSingleton();

  bool loadModel(const std::string &filename);
  bool removeModel(const std::string &filename);
  void reloadModels();
  bool compute(const std::string &filename, std::shared_ptr<Model> model);

  inline void setScenePath(const std::string &path)
  { this->_scenePath = path; }

 private:
  bool loadObj(const std::string &filename);
};

#endif /* !RTECHNOLOGY_MODELPARCER_HPP */
