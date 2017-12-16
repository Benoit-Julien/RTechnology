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

#ifdef WINDOWS
  #define DLL __declspec(dllexport)
#else
  #define DLL
#endif

#ifndef RT_USE_FLOAT
  #if !defined(RT_USE_DOUBLE) || defined(ENVIRONMENT32)
    #define RT_USE_FLOAT
  #endif
#endif

#ifndef RT_REAL_T
  #define RT_REAL_T

  #if defined(RT_USE_DOUBLE) && defined(ENVIRONMENT64)
    typedef double real_t;
  #elif defined(RT_USE_FLOAT)
    typedef float real_t;
  #endif
#endif

#endif /* !RTECHNOLOGY_CONFIG_H */
