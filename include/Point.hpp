#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include <cmath>

struct Point
{
    double x, y;

    Point() : x(0), y(0) {}
    Point(double x_, double y_) : x(x_), y(y_) {}

    friend std::ostream &operator<<(std::ostream &os, const Point &point)
    {
        os << "(" << point.x << ", " << point.y << ")";
        return os;
    }

    friend std::istream &operator>>(std::istream &is, Point &point)
    {
        is >> point.x >> point.y;
        return is;
    }

    bool operator==(const Point& other) const
    {
        return std::abs(x - other.x) < 1e-6 && std::abs(y - other.y) < 1e-6;
    }
    bool operator!=(const Point& other) const
    {
        return !(*this == other);
    }
};

#endif // POINT_HPP
