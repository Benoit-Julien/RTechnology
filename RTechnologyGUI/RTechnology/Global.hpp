/*
** Global.hpp for RTechnology in
**
** Made by julien1.benoit@epitech.eu
** Login   <julien1.benoit@epitech.eu>
**
** Started on  dim. mars 23:44 2018 benoit_g
** Last update dim. mars 23:44 2018 benoit_g
*/

#ifndef RTECHNOLOGY_GLOBAL_HPP
#define RTECHNOLOGY_GLOBAL_HPP

#include "mainwindow.h"

class Global
{
  explicit Global() = default;

 public:
  ~Global() = default;
  Global(const Global &) = delete;
  Global(Global &&) noexcept = delete;
  Global &operator=(const Global &) = delete;
  Global &operator=(Global &&) noexcept = delete;

  static Global &getSingleton()
  {
    static Global global;
    return global;
  }

  void init()
  {
    this->mainWindow = std::make_shared<MainWindow>();
  }

  void reset()
  {
    this->mainWindow.reset();
  }

  std::shared_ptr<MainWindow> mainWindow;
};

#endif /* !RTECHNOLOGY_GLOBAL_HPP */
