#include "vector2d.h"

Vector2D::Vector2D() : x(0.0f), y(0.0f) {}

Vector2D::Vector2D(float x, float y) : x(x), y(y) {}

float Vector2D::getX() const {
    return x;
}

float Vector2D::getY() const {
    return y;
}

void Vector2D::setX(float x) {
    this->x = x;
}

void Vector2D::setY(float y) {
    this->y = y;
}

float Vector2D::magnitude() const {
    return std::sqrt(x * x + y * y);
}

Vector2D Vector2D::normalized() const {
    float mag = magnitude();
    if (mag > 0) {
        return Vector2D(x / mag, y / mag);
    }
    return Vector2D(0, 0);
}

Vector2D Vector2D::operator+(const Vector2D& other) const {
    return Vector2D(x + other.x, y + other.y);
}

Vector2D Vector2D::operator-(const Vector2D& other) const {
    return Vector2D(x - other.x, y - other.y);
}

Vector2D Vector2D::operator*(float scalar) const {
    return Vector2D(x * scalar, y * scalar);
}

Vector2D Vector2D::operator/(float scalar) const {
    if (scalar != 0) {
        return Vector2D(x / scalar, y / scalar);
    }
    return *this;
}

float Vector2D::distance(const Vector2D& a, const Vector2D& b) {
    float dx = b.x - a.x;
    float dy = b.y - a.y;
    return std::sqrt(dx * dx + dy * dy);
}