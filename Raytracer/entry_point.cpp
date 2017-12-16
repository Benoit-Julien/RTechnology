/*
** entry_point.cpp for RTechnology in
**
** Made by julien1.benoit@epitech.eu
** Login   <julien1.benoit@epitech.eu>
**
** Started on  mar. nov. 20:26 2017 benoit_g
** Last update mar. nov. 20:26 2017 benoit_g
*/

#include <iostream>
#include <arrayfire.h>
#include <Raytracer/config.h>

DLL std::string entry_point()
{
  std::string str;

  char t_device_name[64] = {0};
  char t_device_platform[64] = {0};
  char t_device_toolkit[64] = {0};
  char t_device_compute[64] = {0};
  af::deviceInfo(t_device_name, t_device_platform, t_device_toolkit, t_device_compute);

  str += "Device name: " + std::string(t_device_name) + "<br/>";
  str += "Platform name :" + std::string(t_device_platform) + "<br/>";
  str += "Toolkit: " + std::string(t_device_toolkit) + "<br/>";
  str += "Compute version: " + std::string(t_device_compute) + "<br/>";

  af::array undefined_1D(100);
  return str;
}