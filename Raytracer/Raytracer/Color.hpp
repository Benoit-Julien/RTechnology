/*
** Color.hpp for RTechnology in
**
** Made by julien1.benoit@epitech.eu
** Login   <julien1.benoit@epitech.eu>
**
** Started on  mar. déc. 11:10 2017 benoit_g
** Last update mar. déc. 11:10 2017 benoit_g
*/

#ifndef RTECHNOLOGY_COLOR_HPP
#define RTECHNOLOGY_COLOR_HPP

#include "config.h"

class Color
{
 public:
  unsigned char r;
  unsigned char g;
  unsigned char b;
  unsigned char a;

  Color() = default;
  explicit Color(const unsigned char &red);
  Color(const unsigned char &red, const unsigned char &green);
  Color(const unsigned char &red, const unsigned char &green, const unsigned char &blue);
  Color(const unsigned char &red, const unsigned char &green, const unsigned char &blue, const unsigned char &alpha);
  Color(const Color &col);
  Color(Color &&col) noexcept;
  ~Color() = default;

  Color &operator=(const Color &col);
  Color &operator=(Color &&col) noexcept;
};

#endif /* !RTECHNOLOGY_COLOR_HPP */
