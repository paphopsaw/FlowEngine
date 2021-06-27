#include "Vector3D.h"

Vector3D Vector3D::operator-() const {
	return Vector3D(-x, -y, -z);
}

void Vector3D::operator=(const Vector3D& v) {
	x = v.x;
	y = v.y;
	z = v.z;
}

void Vector3D::operator+=(const Vector3D& v) {
	x += v.x;
	y += v.y;
	z += v.z;
}

void Vector3D::operator-=(const Vector3D& v) {
	x -= v.x;
	y -= v.y;
	z -= v.z;
}

void Vector3D::operator*=(const real& k) {
	x *= k;
	y *= k;
	z *= k;
}

void Vector3D::timesUpdate(const Vector3D& v) {
	x *= v.x;
	y *= v.y;
	z *= v.z;
}

void Vector3D::crossUpdate(const Vector3D& v) {
	x = y * v.z - z * v.y;
	y = z * v.z - x * v.z;
	z = x * v.y - y * v.x;
}

Vector3D Vector3D::times(const Vector3D& v) const {
	return Vector3D(x * v.x, y * v.y, z * v.z);
}

real Vector3D::dot(const Vector3D& v) const {
	return (x * v.x + y * v.y + z * v.z);
}

Vector3D Vector3D::cross(const Vector3D& v) const {
	return Vector3D(y * v.z - z * v.y,
		z * v.z - x * v.z,
		x * v.y - y * v.x);
}

real Vector3D::magnitude() const {
	return std::sqrt(x * x + y * y + z * z);
}

real Vector3D::squareMagnitude() const {
	return x * x + y * y + z * z;
}

Vector3D Vector3D::normalized() const {
	real l{ magnitude() };
	if (l > 0)
		return (*this) * ((real)1.0 / l);
	return (*this);
}

Vector3D operator+(const Vector3D& v1, const Vector3D& v2) {
	return Vector3D(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}

Vector3D operator-(const Vector3D& v1, const Vector3D& v2) {
	return Vector3D(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}

Vector3D operator*(const real& k, const Vector3D& v) {
	return Vector3D(k * v.x, k * v.y, k * v.z);
}

Vector3D operator*(const Vector3D& v, const real& k) {
	return k * v;
}

real operator*(const Vector3D& v1, const Vector3D& v2) {
	return v1.dot(v2);
}

Vector3D componentProduct(const Vector3D& v1, const Vector3D& v2) {
	return v1.times(v2);
}

real dotProduct(const Vector3D& v1, const Vector3D& v2) {
	return v1.dot(v2);
}

Vector3D crossProduct(const Vector3D& v1, const Vector3D& v2) {
	return v1.cross(v2);
}

std::ostream& operator<<(std::ostream& out, const Vector3D& v) {
	out << "Vector3D(" << v.x << ", " << v.y << ",  " << v.z << ")";
	return out;
}

std::istream& operator>>(std::istream& in, Vector3D& v) {
	in >> v.x;
	in >> v.y;
	in >> v.z;
	return in;
}
