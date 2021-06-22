#include "Vector2D.h"

namespace fe {
	Vector2D Vector2D::operator-() const {
		return Vector2D(-x, -y);
	}

	void Vector2D::operator=(const Vector2D &v) {
		x = v.x;
		y = v.y;
	}
	void Vector2D::operator+=(const Vector2D &v) {
		x += v.x;
		y += v.y;
	}
	void Vector2D::operator-=(const Vector2D &v) {
		x -= v.x;
		y -= v.y;
	}
	void Vector2D::operator*=(const real &k) {
		x *= k;
		y *= k;
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
			return (*this) * (1.0 / l);
	}

	Vector2D Vector2D::componentProduct(const Vector2D &v) const {
		return Vector2D(x * v.x, y * v.y);
	}

	Vector2D operator+(const Vector2D &v1, const Vector2D &v2) {
		return Vector2D(v1.x + v2.x, v1.y + v2.y);
	}
	Vector2D operator-(const Vector2D &v1, const Vector2D &v2) {
		return Vector2D(v1.x - v2.x, v1.y - v2.y);
	}
	Vector2D operator*(const real &k, const Vector2D &v) {
		return Vector2D(k * v.x, k * v.y);
	}
	Vector2D operator*(const Vector2D &v, const real &k) {
		return k * v;
	}
	real operator*(const Vector2D &v1, const Vector2D &v2) {
		return (v1.x * v2.x) + (v1.y * v2.y);
	}

	std::ostream& operator<<(std::ostream &out, const Vector2D &v) {
		out << "Vector2D(" << v.x << ", " << v.y << ")";
		return out;
	}
	std::istream& operator>>(std::istream &in, Vector2D &v) {
		in >> v.x;
		in >> v.y;
		return in;
	}
}