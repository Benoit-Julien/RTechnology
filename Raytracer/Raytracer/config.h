/*
** config.h for RTechnology in
**
** Made by julien1.benoit@epitech.eu
** Login   <julien1.benoit@epitech.eu>
**
** Started on  mer. déc. 16:56 2017 benoit_g
** Last update mer. déc. 16:56 2017 benoit_g
*/

#ifndef RTECHNOLOGY_CONFIG_H
#define RTECHNOLOGY_CONFIG_H

#if defined(_WIN32) || defined(_WIN64)
  #define WINDOWS
#else
  #define LINUX
#endif

#ifdef WINDOWS
# if _WIN64
#  define ENVIRONMENT64
# else
#  define ENVIRONMENT32
# endif
#else
#if defined(__x86_64__) || defined(__ppc64__)
#  define ENVIRONMENT64
# else
#  define ENVIRONMENT32
# endif
#endif

#ifndef RT_DLL
# ifdef WINDOWS
#  define RT_DLL __declspec(dllexport)
# else
#  define RT_DLL
# endif
#endif

RT_DLL extern bool useGraphics;

#endif /* !RTECHNOLOGY_CONFIG_H */
