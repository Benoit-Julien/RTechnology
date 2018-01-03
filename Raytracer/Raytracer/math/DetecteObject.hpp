/*
** DetecteObject.hpp for RTechnology in
**
** Made by auguste.larrive-jahan@epitech.eu
** Login   <auguste.larrive-jahan@epitech.net>
**
** Started on  mar. janv. 11:56 2018 each
** Last update mar. janv. 11:56 2018 each
*/

#ifndef RTECHNOLOGY_DETECTEOBJECT_HPP
#define RTECHNOLOGY_DETECTEOBJECT_HPP

#include "Vector3.hpp"

class DetecteObject {
    Vector3Float _positionObject;
public:
    DetecteObject(const Vector3Float &posObject);
    ~DetecteObject();
    float detecteSphere(const Vector3Float &posCam, const Vector3Float &vector, const float &radius);
    float detecteCylinder(const Vector3Float &posCam, const Vector3Float &vector, const float &radius);
    float detecteCone(const Vector3Float &posCam, const Vector3Float &vector, const float &angle);
    float checkDelta(const float &a, const float &b, const float &delta);
};

#endif /* !RTECHNOLOGY_DETECTEOBJECT_HPP */
