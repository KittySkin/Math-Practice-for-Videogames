#include <iostream>

class Vector {
public:
    Vector() {}
    Vector(float X, float Y){
        x = X;
        y = Y;
    }

    float Length() const;
    float LengthSqr() const;

    Vector operator*(float s) const;
    Vector operator/(float s) const;

    float x, y;
};

class Point {
public:
    Point AddVector(Vector v);

    float x, y;
};

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
    Vector v(3, 4);

    std::cout << "Pac man's initial speed: " << v.Length() << "\n";

    Vector doubled;

    doubled = v * 2;

    std::cout << "Pac man's doubled speed: " << doubled.Length() << "\n";

    Vector halved;

    halved = v / 2;

    std::cout << "Pac man's halved speed: " << halved.Length() << "\n";

    return 0;
}
