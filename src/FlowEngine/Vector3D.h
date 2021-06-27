#ifndef VECTOR3D_H
#define VECTOR3D_H
#include <iostream>
#include <cmath>
#include "precision.h"
#include "Vector2D.h"

class Vector3D {
public:
	real x;
	real y;
	real z;

	Vector3D()
		: x{ 0 }, y{ 0 }, z{ 0 } {};
	Vector3D(const real x, const real y, const real z)
		: x{ x }, y{ y }, z{ z } {};
	Vector3D(const Vector2D& v, const real z)
		: x{ v.x }, y{ v.y }, z{ z } {};
	Vector3D(const real x, const Vector2D& v)
		: x{ x }, y{ v.x }, z{ v.y } {};

	Vector3D operator-() const;
	void operator=(const Vector3D& v);
	void operator+=(const Vector3D& v);
	void operator-=(const Vector3D& v);
	void operator*=(const real& k);
	void timesUpdate(const Vector3D& v);
	void crossUpdate(const Vector3D& v);

	Vector3D times(const Vector3D& v) const;
	real     dot(const Vector3D& v) const;
	Vector3D cross(const Vector3D& v) const;

	real     magnitude() const;
	real     squareMagnitude() const;
	Vector3D normalized() const;
};

Vector3D operator+(const Vector3D& v1, const Vector3D& v2);
Vector3D operator-(const Vector3D& v1, const Vector3D& v2);
Vector3D operator*(const real& k, const Vector3D& v);
Vector3D operator*(const Vector3D& v, const real& k);
real	 operator*(const Vector3D& v1, const Vector3D& v2);
Vector3D componentProduct(const Vector3D& v1, const Vector3D& v2);
real     dotProduct(const Vector3D& v1, const Vector3D& v2);
Vector3D crossProduct(const Vector3D& v1, const Vector3D& v2);

std::ostream& operator<<(std::ostream& out, const Vector3D& v);
std::istream& operator>>(std::istream& in, Vector3D& v);

#endif