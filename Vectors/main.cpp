#include <iostream>

class Vector {
public:
    Vector() {}

    Vector(float X, float Y) {
        x = X;
        y = Y;
    }

    float Length() const;

    float LengthSqr() const;

    Vector operator+(const Vector& v) const;

    Vector operator-(const Vector& v) const;

    Vector operator*(float s) const;

    Vector operator/(float s) const;

    Vector Normalized() const;

    float x, y;
};

class Point {
public:
    Point AddVector(Vector v);

    Point() {}

    Point(float X, float Y) {
        x = X;
        y = Y;
    }

    float x, y;
};

Vector Vector::operator+(const Vector& v) const {
    Vector r;

    r.x = x + v.x;
    r.y = y + v.y;

    return r;
}

Vector Vector::operator-(const Vector& v) const {
    return Vector(x - v.x, y - v.y);
}

Vector Vector::Normalized() const {
    Vector normalized;

    normalized = (*this) / Length();
    return normalized;
}

Vector Vector::operator*(float s) const {
    Vector scaled;

    scaled.x = x * s;
    scaled.y = y * s;

    return scaled;
}

Vector Vector::operator/(float s) const {
    Vector scaled;

    scaled.x = x / s;
    scaled.y = y / s;

    return scaled;
}

float Vector::Length() const {
    float length;

    length = sqrt(x * x + y * y);

    return length;
}

float Vector::LengthSqr() const {
    float length;

    length = x * x + y * y;

    return length;
}

Vector operator-(Point a, Point b) {
    Vector v;

    v.x = a.x - b.x;
    v.y = a.y - b.y;

    return v;
}

Point Point::AddVector(Vector v) {
    Point p2;

    p2.x = x + v.x;
    p2.y = y + v.y;

    return p2;
}

int main() {
    Vector r(4, 0);
    Vector d(0, -5);

    Vector v = r + d;

    std::cout << "Pac man's new velocity: (" << v.x << ", " << v.y << ")\n";

    return 0;
}
