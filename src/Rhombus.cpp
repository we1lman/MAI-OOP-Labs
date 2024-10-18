#include "Rhombus.hpp"
#include <cmath>
#include <iostream>

Rhombus::Rhombus(const Point points[4])
{
    for (int i = 0; i < 4; ++i) {
        points_[i] = points[i];
    }
    isValidRhombus();
}

Rhombus::Rhombus(const Rhombus& other) {
    for (int i = 0; i < 4; ++i) {
        points_[i] = other.points_[i];
    }
}

Rhombus &Rhombus::operator=(const Rhombus &other)
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

Rhombus &Rhombus::operator=(Rhombus &&other) noexcept
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

bool Rhombus::operator==(const Figure &other) const
{
    const Rhombus *otherRhombus = dynamic_cast<const Rhombus *>(&other);
    if (!otherRhombus)
        return false;
    for (int i = 0; i < 4; ++i)
    {
        if (points_[i] != otherRhombus->points_[i])
        {
            return false;
        }
    }
    return true;
}

void Rhombus::getInfo() const
{
    std::cout << *this << std::endl;
}

Point Rhombus::geometricCenter() const
{
    double centerX = (points_[0].x + points_[2].x) / 2.0;
    double centerY = (points_[0].y + points_[2].y) / 2.0;

    return Point{centerX, centerY};
}

Rhombus::operator double() const
{
    double d1 = std::sqrt(std::pow(points_[1].x - points_[0].x, 2) + std::pow(points_[1].y - points_[0].y, 2));
    double d2 = std::sqrt(std::pow(points_[2].x - points_[1].x, 2) + std::pow(points_[2].y - points_[1].y, 2));
    return 0.5 * d1 * d2;
}

bool Rhombus::isValidRhombus() const
{
    const double epsilon = 1e-3;
    double sideLength = std::sqrt(std::pow(points_[1].x - points_[0].x, 2) + std::pow(points_[1].y - points_[0].y, 2));

    for (int i = 1; i < 4; ++i)
    {
        int next = (i + 1) % 4;
        double currentSide = std::sqrt(std::pow(points_[next].x - points_[i].x, 2) + std::pow(points_[next].y - points_[i].y, 2));
        if (std::abs(currentSide - sideLength) > epsilon)
        {
            throw std::invalid_argument("Points do not form a valid rhombus.");
        }
    }

    return true;
}

std::ostream &operator<<(std::ostream &os, const Rhombus &rhombus)
{
    os << "Rhombus: points = ";
    for (const auto &point : rhombus.points_)
    {
        os << point << " ";
    }
    return os;
}

std::istream &operator>>(std::istream &is, Rhombus &rhombus)
{
    Point points[4];
    for (int i = 0; i < 4; ++i)
    {
        is >> points[i];
    }
    for (int i = 0; i < 4; ++i)
    {
        rhombus.points_[i] = points[i];
    }
    return is;
}
