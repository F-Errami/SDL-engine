#include "../include/Math.hpp"

Vector2D::Vector2D()
{
    x = 0;
    y = 0;
}
Vector2D::Vector2D(float p_x, float p_y):
x(p_x),y(p_y)
{}

Vector2D & Vector2D::Add(const Vector2D &vect)
{
    x +=vect.x;
    y +=vect.y;
    return *this;
}

Vector2D & Vector2D::Subtract(const Vector2D &vec)
{
    x -=vect.x;
    y -=vect.y;
    return *this;
}
Vector2D & Vector2D::Multiply(const Vector2D &vect)
{
    x *=vect.x;
    y *=vect.y;
    return *this;
}
Vector2D & Vector2D::Divide(const Vector2D &vect)
{
    x /=vect.x;
    y /=vect.y;
    return *this;
}

Vector2D & Vector2D::operator+(Vector2D& v1,const Vector2D &v2)
        {
           return v1.add(v2);
        }
Vector2D & Vector2D::operator-(Vector2D& v1,const Vector2D &v2)
{
return v1.Subtract(v2);
}
Vector2D & Vector2D::operator*(Vector2D& v1,const Vector2D &v2)
{
return v1.Multiply(v2);
}
Vector2D & Vector2D::operator/(Vector2D& v1,const Vector2D &v2)
{
return v1.Divide(v2);
}


Vector2D & Vector2D::operator+=(const Vector2D &v2)
{
    return this->add(v2);
}
Vector2D & Vector2D::operator-=(const Vector2D &v2)
{
    return thsi->Subtract(v2);
}
Vector2D & Vector2D::operator*=(const Vector2D &v2)
{
    return this->Multiply(v2);
}
Vector2D & Vector2D::operator/=(const Vector2D &v2)
{
    return thsi->Divide(v2);
}



