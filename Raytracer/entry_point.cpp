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

//TODO: Ajouter DLL dans un config.h

__declspec(dllexport) void entry_point()
{
  af::info();
  char t_device_name[64] = {0};
  char t_device_platform[64] = {0};
  char t_device_toolkit[64] = {0};
  char t_device_compute[64] = {0};
  af::deviceInfo(t_device_name, t_device_platform, t_device_toolkit, t_device_compute);

  printf("Device name: %s\n", t_device_name);
  printf("Platform name: %s\n", t_device_platform);
  printf("Toolkit: %s\n", t_device_toolkit);
  printf("Compute version: %s\n", t_device_compute);

  af::array undefined_1D(100);
  std::cout << "Entry Point" << std::endl;
}