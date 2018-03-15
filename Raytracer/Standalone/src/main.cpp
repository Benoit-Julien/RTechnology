/*
** main.cpp for RTechnology in
**
** Made by julien1.benoit@epitech.eu
** Login   <julien1.benoit@epitech.eu>
**
** Started on  mar. nov. 21:05 2017 benoit_g
** Last update mar. nov. 21:05 2017 benoit_g
*/

#include "SFMLPictureDraw.hpp"
#include <Raytracer/Raytracer.hpp>

#include <fstream>
#include <rapidjson/document.h>
#include <rapidjson/filereadstream.h>

#ifndef SCENES_PATH
  #define SCENE_PATH "."
#endif

#if defined(WINDOWS) && !defined(_DEBUG)
# include <Windows.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
#else
int main(int ac, char **av)
#endif
{
  if (ac < 2)
    return (-1);

  auto draw = std::make_shared<SFMLPictureDraw>(1280, 720);
  rt::Raytracer raytracer(draw, true);

  std::string filepath = av[1];
  std::ifstream file(filepath);
  std::string json;

  if (!file)
    {
      std::cerr << filepath << ": not found" << std::endl;
      return -1;
    }

  std::string tmp;
  while (std::getline(file, tmp))
    json.append(tmp + "\n");

  file.close();

  draw->updateWindow();
  raytracer.setScenePath(SCENES_PATH);
  raytracer.initialiseScene(json);
  raytracer.start();

  while (draw->windowIsOpen())
    draw->updateWindow();
  raytracer.stop();

  return 0;
}