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

#if WINDOWS && !_DEBUG
# include <Windows.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
#else
int main()
#endif
{
  SFMLPictureDraw draw(1280, 720);

  draw.setPixel(Vector2Int(50, 50), Color(255, 0, 0));

  while (draw.windowIsOpen())
    draw.updateWindow();
}