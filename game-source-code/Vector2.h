#ifndef VECTOR2_H
#define VECTOR2_H

class Vector2
{
public:
    Vector2(): X(0), Y(0) {}
    Vector2(const float& x, const float& y) : X(x), Y(y)
    {}

    Vector2& add(const Vector2& other) 
    {
       this->X += other.X;
       this->Y += other.Y;
       return *this;
    }

    Vector2& subtract(const Vector2& other)
    {
        this->X -= other.X;
        this->Y -= other.Y;
        return *this;
    }

    float X;
    float Y;
};

#endif
