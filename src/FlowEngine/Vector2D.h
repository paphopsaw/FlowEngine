#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <iostream>
#include <cmath>
#include "precision.h"

class Vector2D {
public:
	real x;
	real y;
	Vector2D()
		: x{ 0 }, y{ 0 } {};

	Vector2D(const real x, const real y)
		: x{ x }, y{ y } {};

	Vector2D operator-() const;
	void operator=(const Vector2D& v);
	void operator+=(const Vector2D& v);
	void operator-=(const Vector2D& v);
	void operator*=(const real& k);
	void timesUpdate(const Vector2D& v);

	Vector2D times(const Vector2D& v) const;
	real dot(const Vector2D& v) const;

	real magnitude() const;
	real squareMagnitude() const;
	Vector2D normalized() const;

};

Vector2D operator+(const Vector2D& v1, const Vector2D& v2);
Vector2D operator-(const Vector2D& v1, const Vector2D& v2);
Vector2D operator*(const real& k, const Vector2D& v);
Vector2D operator*(const Vector2D& v, const real& k);
real operator*(const Vector2D& v1, const Vector2D& v2);
Vector2D componentProduct(const Vector2D& v1, const Vector2D& v2);
real dotProduct(const Vector2D& v1, const Vector2D& v2);

std::ostream& operator<<(std::ostream& out, const Vector2D& v);
std::istream& operator>>(std::istream& in, Vector2D& v);

#endif