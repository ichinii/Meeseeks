#ifndef UTIL_VEC_H
#define UTIL_VEC_H

#include "math.h"

template <typename T>
class Vec2_base {
public:
	template <typename U>
	Vec2_base(const Vec2_base<U> &v) : x(v.x), y(v.y) {}
	Vec2_base() : x(0), y(0) {}
	Vec2_base(Vec2_base&&) = default;
	Vec2_base(T nx, T ny) : x(nx), y(ny) {}

	union { T x; T u; };
	union { T y; T v; };

	Vec2_base& operator= (const Vec2_base&) = default;
	Vec2_base& operator= (Vec2_base&&) = default;

	Vec2_base operator* (const T n) const { return Vec2_base(x * n, y * n); }
	Vec2_base operator/ (const T n) const { return Vec2_base(x / n, y / n); }
	Vec2_base operator* (const Vec2_base &v) const { return Vec2_base(x * v.x, y * v.y); }
	Vec2_base operator/ (const Vec2_base &v) const { return Vec2_base(x / v.x, y / v.y); }
	Vec2_base operator+ (const Vec2_base &v) const { return Vec2_base(x + v.x, y + v.y); }
	Vec2_base operator- (const Vec2_base &v) const { return Vec2_base(x - v.x, y - v.y); }

	const Vec2_base& operator*= (const T n) { x *= n; y *= n; return *this; }
	const Vec2_base& operator/= (const T n) { x /= n; y /= n; return *this; }
	const Vec2_base& operator*= (const Vec2_base &v) { x *= v.x; y *= v.y; return *this; }
	const Vec2_base& operator/= (const Vec2_base &v) { x /= v.x; y /= v.y; return *this; }
	const Vec2_base& operator+= (const Vec2_base &v) { x += v.x; y += v.y; return *this; }
	const Vec2_base& operator-= (const Vec2_base &v) { x -= v.x; y -= v.y; return *this; }

	bool operator== (const Vec2_base &v) { return x == v.x && y == v.y; }
	bool operator!= (const Vec2_base &v) { return x != v.x || y != v.y; }
};

using Vec2 = Vec2_base<float>;
using Vec2i = Vec2_base<int>;

template <typename T>
inline float length(Vec2_base<T> &v)
{
	return sqrtf(v.x * v.x, v.y * v.y);
}

template <typename T>
inline Vec2_base<T> normalize(Vec2_base<T> &v)
{
	float l = length(v);
	return Vec2_base<T>(v.x / l, v.y / l);
}

#endif
