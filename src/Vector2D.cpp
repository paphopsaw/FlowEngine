#include "Vector2D.h"

Vector2D Vector2D::operator-() const {
	return Vector2D(-x, -y);
}

void Vector2D::operator=(const Vector2D& v) {
	x = v.x;
	y = v.y;
}
void Vector2D::operator+=(const Vector2D& v) {
	x += v.x;
	y += v.y;
}
void Vector2D::operator-=(const Vector2D& v) {
	x -= v.x;
	y -= v.y;
}
void Vector2D::operator*=(const real& k) {
	x *= k;
	y *= k;
}

Vector2D Vector2D::times(const Vector2D& v) const {
	return Vector2D(x * v.x, y * v.y);
}

real Vector2D::dot(const Vector2D& v) const {
	return (x * v.x) + (y * v.y);
}

real Vector2D::magnitude() const {
	return std::sqrt(x * x + y * y);
}

real Vector2D::squareMagnitude() const {
	return x * x + y * y;
}

Vector2D Vector2D::normalized() const {
	real l{ magnitude() };
	if (l > 0)
		return (*this) * ((real)1.0 / l);
	return (*this);
}

Vector2D operator+(const Vector2D& v1, const Vector2D& v2) {
	return Vector2D(v1.x + v2.x, v1.y + v2.y);
}
Vector2D operator-(const Vector2D& v1, const Vector2D& v2) {
	return Vector2D(v1.x - v2.x, v1.y - v2.y);
}
Vector2D operator*(const real& k, const Vector2D& v) {
	return Vector2D(k * v.x, k * v.y);
}
Vector2D operator*(const Vector2D& v, const real& k) {
	return k * v;
}
real operator*(const Vector2D& v1, const Vector2D& v2) {
	return v1.dot(v2);
}

Vector2D componentProduct(const Vector2D& v1, const Vector2D& v2)
{
	return v1.times(v2);
}

real dotProduct(const Vector2D& v1, const Vector2D& v2) {
	return v1.dot(v2);
}

std::ostream& operator<<(std::ostream& out, const Vector2D& v) {
	out << "Vector2D(" << v.x << ", " << v.y << ")";
	return out;
}
std::istream& operator>>(std::istream& in, Vector2D& v) {
	in >> v.x;
	in >> v.y;
	return in;
}
