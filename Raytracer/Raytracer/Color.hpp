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

#include <string>
#include "config.h"

class RT_DLL Color
{
 public:
  uint8_t r;
  uint8_t g;
  uint8_t b;
  uint8_t a;

  Color() = default;
  explicit Color(const uint8_t &red);
  Color(const uint8_t &red, const uint8_t &green);
  Color(const uint8_t &red, const uint8_t &green, const uint8_t &blue);
  Color(const uint8_t &red, const uint8_t &green, const uint8_t &blue, const uint8_t &alpha);
  Color(const Color &col);
  Color(Color &&col) noexcept;
  ~Color() = default;

  Color &operator=(const Color &col);
  Color &operator=(Color &&col) noexcept;
};

#endif /* !RTECHNOLOGY_COLOR_HPP */
