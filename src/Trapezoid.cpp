#include "Trapezoid.hpp"
#include <cmath>
#include <iostream>

Trapezoid::Trapezoid(const Point points[4]) {
    for (int i = 0; i < 4; ++i) {
        points_[i] = points[i];
    }
}

Trapezoid::Trapezoid(const Trapezoid& other) {
    for (int i = 0; i < 4; ++i) {
        points_[i] = other.points_[i];
    }
}

Trapezoid& Trapezoid::operator=(const Trapezoid& other)
{
    if (this != &other)
    {
        for (int i = 0; i < 4; ++i)
        {
            points_[i] = other.points_[i];
        }
    }
    return *this;
}

Trapezoid& Trapezoid::operator=(Trapezoid&& other) noexcept
{
    if (this != &other)
    {
        for (int i = 0; i < 4; ++i)
        {
            points_[i] = std::move(other.points_[i]);
        }
    }
    return *this;
}

bool Trapezoid::operator==(const Figure &other) const
{
    const Trapezoid *otherTrapezoid = dynamic_cast<const Trapezoid *>(&other);
    if (!otherTrapezoid)
        return false;
    for (int i = 0; i < 4; ++i)
    {
        if (points_[i] != otherTrapezoid->points_[i])
        {
            return false;
        }
    }
    return true;
}

void Trapezoid::getInfo() const
{
    std::cout << *this << std::endl;
}

Point Trapezoid::geometricCenter() const
{
    double centerX = 0, centerY = 0;
    for (const auto &point : points_)
    {
        centerX += point.x;
        centerY += point.y;
    }
    return Point{centerX / 4, centerY / 4};
}

Trapezoid::operator double() const
{
    double a = std::sqrt(std::pow(points_[1].x - points_[0].x, 2) + std::pow(points_[1].y - points_[0].y, 2));
    double b = std::sqrt(std::pow(points_[2].x - points_[3].x, 2) + std::pow(points_[2].y - points_[3].y, 2));

    double h = std::abs(points_[0].y - points_[2].y);

    return 0.5 * (a + b) * h;
}

bool Trapezoid::isValidTrapezoid() const
{
    double epsilon = 1e-5;
    double slope1 = (points_[1].y - points_[0].y) / (points_[1].x - points_[0].x + epsilon);
    double slope2 = (points_[3].y - points_[2].y) / (points_[3].x - points_[2].x + epsilon);

    if (std::abs(slope1 - slope2) > epsilon)
    {
        return true;
    }
    else
    {
        throw std::invalid_argument("Points do not form a valid trapezoid.");
    }
}

std::ostream &operator<<(std::ostream &os, const Trapezoid &trapezoid)
{
    os << "Trapezoid: points = ";
    for (const auto &point : trapezoid.points_)
    {
        os << point << " ";
    }
    return os;
}

std::istream &operator>>(std::istream &is, Trapezoid &trapezoid)
{
    Point points[4];
    for (int i = 0; i < 4; ++i)
    {
        is >> points[i];
    }
    for (int i = 0; i < 4; ++i)
    {
        trapezoid.points_[i] = points[i];
    }
    return is;
}
