/*
** DetecteObject.cpp for RTechnology in
**
** Made by auguste.larrive-jahan@epitech.eu
** Login   <auguste.larrive-jahan@epitech.net>
**
** Started on  mar. janv. 11:56 2018 each
** Last update mar. janv. 11:56 2018 each
*/


#include "DetecteObject.hpp"

DetecteObject::DetecteObject(const Vector3Float &posObject) {
    this->_positionObject = posObject;
}

DetecteObject::~DetecteObject() {}

float DetecteObject::checkDelta(const float &a, const float &b, const float &delta) {
    float s1;
    float s2;

    if (delta > 0) {
        s1 = (-b + sqrt(delta)) / (2 * a);
        s2 = (-b - sqrt(delta)) / (2 * a);
        if (s2 > s1) {
            if (s1 > 0)
                return s1;
            else
                return s2;
        } else {
            if (s2 > 0)
                return s2;
            else
                return s1;
        }
    }
    return -1;
}

float DetecteObject::detecteSphere(const Vector3Float &posCam, const Vector3Float &vector, const float &radius) {
    float delta;
    float a;
    float b;
    float c;
    float k;

    a = (vector.x() * vector.x()) + (vector.y() * vector.y()) + (vector.z() * vector.z());
    b = 2 * ((posCam.x() * vector.x()) + (posCam.y() * vector.y()) + (posCam.z() * vector.z()));
    c = (posCam.x() * posCam.x()) + (posCam.y() + posCam.y()) + (posCam.z() * posCam.z()) - (radius * radius);
    delta = (b * b) - (4 * (a * c));
    k = checkDelta(a, b, delta);
    return k;
}

float DetecteObject::detecteCylinder(const Vector3Float &posCam, const Vector3Float &vector, const float &radius) {
    float delta;
    float a;
    float b;
    float c;
    float k;

    a = (vector.x() * vector.x()) + (vector.z() * vector.z());
    b = 2 * ((vector.x() * posCam.x()) + (vector.z() * posCam.z()));
    c = (posCam.x() + posCam.x()) + (posCam.z() * posCam.z()) - (radius * radius);
    delta = (b * b) - (4 * (a * c));
    k = checkDelta(a, b, delta);
    return k;
}

float DetecteObject::detecteCone(const Vector3Float &posCam, const Vector3Float &vector, const float &angle) {
    float delta;
    float a;
    float b;
    float c;
    float k;
    float ratio;

    ratio = angle / 100;
    a = (vector.x() * vector.x()) + (vector.z() * vector.z()) - ((ratio * ratio) * (vector.y() * vector.y()));
    b = 2 * ((vector.x() * posCam.x()) + (vector.z() * posCam.z()) - ((ratio * ratio) * (vector.y() * posCam.y())));
    c = (posCam.x() * posCam.x()) + (posCam.z() * posCam.z()) - ((ratio * ratio) * (posCam.y() * posCam.y()));
    delta = (b * b) - (4 * (a * c));
    k = checkDelta(a, b, delta);
    return k;
}