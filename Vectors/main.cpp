#include <iostream>

class Vector {
public:
    float Length() const;
    float LengthSqr() const;

    float x, y;
};

class Point {
public:
    Point AddVector(Vector v);

    float x, y;
};

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
    Point p; // (0, -1)
    p.x = 0;
    p.y = -1;

    Point i; // (1, 1)
    i.x = 1;
    i.y = 1;

    Point c; // (2, -1)
    c.x = 2;
    c.y = -1;

    Vector cp;
    Vector ip;

    cp = p - c;
    ip = p - i;

    float length_sqr_cp = cp.LengthSqr();
    float length_sqr_ip = ip.LengthSqr();

    std::cout << "Length squared of CP: " << length_sqr_cp << "\n";
    std::cout << "Length squared of IP: " << length_sqr_ip << "\n";

    return 0;
}
