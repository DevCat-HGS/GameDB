#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <cmath>

class Vector2D {
public:
    Vector2D();
    Vector2D(float x, float y);
    
    float getX() const;
    float getY() const;
    
    void setX(float x);
    void setY(float y);
    
    float magnitude() const;
    Vector2D normalized() const;
    
    Vector2D operator+(const Vector2D& other) const;
    Vector2D operator-(const Vector2D& other) const;
    Vector2D operator*(float scalar) const;
    Vector2D operator/(float scalar) const;
    
    static float distance(const Vector2D& a, const Vector2D& b);
    
private:
    float x;
    float y;
};

#endif // VECTOR2D_H