/*
** Color.cpp for RTechnology in
**
** Made by julien1.benoit@epitech.eu
** Login   <julien1.benoit@epitech.eu>
**
** Started on  mar. déc. 11:10 2017 benoit_g
** Last update mar. déc. 11:10 2017 benoit_g
*/

#include "Color.hpp"

Color::Color(const unsigned char &red)
	: r(red)
{}

Color::Color(const unsigned char &red, const unsigned char &green)
	: r(red),
	  g(green)
{}

Color::Color(const unsigned char &red, const unsigned char &green, const unsigned char &blue)
	: r(red),
	  g(green),
	  b(blue)
{}

Color::Color(const unsigned char &red, const unsigned char &green, const unsigned char &blue, const unsigned char &alpha)
	: r(red),
	  g(green),
	  b(blue),
	  a(alpha)
{}

Color::Color(const Color &col)
	: r(col.r),
	  g(col.g),
	  b(col.b),
	  a(col.a)
{}

Color::Color(Color &&col) noexcept
	: r(col.r),
	  g(col.g),
	  b(col.b),
	  a(col.a)
{}

Color &Color::operator=(const Color &col)
{
  this->r = col.r;
  this->g = col.g;
  this->b = col.b;
  this->a = col.a;

  return *this;
}

Color &Color::operator=(Color &&col) noexcept
{
  this->r = col.r;
  this->g = col.g;
  this->b = col.b;
  this->a = col.a;

  return *this;
}