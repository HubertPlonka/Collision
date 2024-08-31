#include "Vector2f.h"
#include <cmath>

// Vector2f::Vector2f() : x(0), y(0) {}
//
// Vector2f::Vector2f(float x, float y) : x(x), y(y) {}
//
// float Vector2f::length() const {
//     return sqrtf(x * x + y * y);
// }
//
// float Vector2f::normalize() {
//     float len = length();
//     x /= len;
//     y /= len;
//     return len;
// }
//
// float Vector2f::dot(const Vector2f& other) const {
//     return x * other.x + y * other.y;
// }
//
// Vector2f Vector2f::operator+(const Vector2f& other) const {
//     return Vector2f(x + other.x, y + other.y);
// }
//
// Vector2f Vector2f::operator-(const Vector2f& other) const {
//     return Vector2f(x - other.x, y - other.y);
// }
//
// Vector2f Vector2f::operator* (float scalar) const {
//     return Vector2f(x * scalar, y * scalar);
// }
//
// Vector2f Vector2f::operator/(float scalar) const {
//     return Vector2f(x / scalar, y / scalar);
// }
//
// bool Vector2f::operator==(const Vector2f& other) const {
//     return x == other.x && y == other.y;
// }
//
// bool Vector2f::operator!=(const Vector2f& other) const {
//     return !(*this == other);
// }