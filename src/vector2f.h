#ifndef VECTOR2F_H
#define VECTOR2F_H

class Vector2f {
public:
    float x;
    float y;

    Vector2f();
    Vector2f(float x, float y);

    float length() const;
    float normalize();
    float dot(const Vector2f& other) const;

    Vector2f operator+(const Vector2f& other) const;
    Vector2f operator-(const Vector2f& other) const;
    Vector2f operator* (float scalar) const;
    Vector2f operator/(float scalar) const;

    bool operator==(const Vector2f& other) const;
    bool operator!=(const Vector2f& other) const;
};

#endif // VECTOR2F_H