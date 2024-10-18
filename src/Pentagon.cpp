#include "Pentagon.hpp"
#include <cmath>
#include <iostream>

Pentagon::Pentagon(const Point points[5]) {
    for (int i = 0; i < 5; ++i) {
        points_[i] = points[i];
    }
}

Pentagon::Pentagon(const Pentagon& other) {
    for (int i = 0; i < 5; ++i) {
        points_[i] = other.points_[i];
    }
}

Pentagon& Pentagon::operator=(const Pentagon& other)
{
    if (this != &other)
    {
        for (int i = 0; i < 5; ++i)
        {
            points_[i] = other.points_[i];
        }
    }
    return *this;
}

Pentagon& Pentagon::operator=(Pentagon&& other) noexcept
{
    if (this != &other)
    {
        for (int i = 0; i < 5; ++i)
        {
            points_[i] = std::move(other.points_[i]);
        }
    }
    return *this;
}

Figure* Pentagon::clone() const
{
    return new Pentagon(*this);
}

bool Pentagon::operator==(const Figure &other) const
{
    const Pentagon *otherPentagon = dynamic_cast<const Pentagon *>(&other);
    if (!otherPentagon)
        return false;
    for (int i = 0; i < 5; ++i)
    {
        if (points_[i] != otherPentagon->points_[i])
        {
            return false;
        }
    }
    return true;
}

void Pentagon::getInfo() const
{
    std::cout << *this << std::endl;
}

Point Pentagon::geometricCenter() const
{
    double centerX = 0, centerY = 0;
    for (const auto &point : points_)
    {
        centerX += point.x;
        centerY += point.y;
    }
    return Point{centerX / 5, centerY / 5};
}

Pentagon::operator double() const
{
    double area = 0;
    for (int i = 0; i < 5; ++i)
    {
        int j = (i + 1) % 5;
        area += points_[i].x * points_[j].y - points_[j].x * points_[i].y;
    }
    return std::abs(area) / 2;
}

bool Pentagon::isValidPentagon() const
{
    const double epsilon = 1e-3;
    double sideLength = std::sqrt(std::pow(points_[1].x - points_[0].x, 2) + std::pow(points_[1].y - points_[0].y, 2));

    for (int i = 1; i < 5; ++i)
    {
        int next = (i + 1) % 5;
        double currentSide = std::sqrt(std::pow(points_[next].x - points_[i].x, 2) + std::pow(points_[next].y - points_[i].y, 2));
        if (std::abs(currentSide - sideLength) > epsilon)
        {
            throw std::invalid_argument("Points do not form a valid pentagon.");
        }
    }

    return true;
}

std::ostream &operator<<(std::ostream &os, const Pentagon &pentagon)
{
    os << "Pentagon: points = ";
    for (const auto &point : pentagon.points_)
    {
        os << point << " ";
    }
    return os;
}

std::istream &operator>>(std::istream &is, Pentagon &pentagon)
{
    Point points[5];
    for (int i = 0; i < 5; ++i)
    {
        is >> points[i];
    }
    for (int i = 0; i < 5; ++i)
    {
        pentagon.points_[i] = points[i];
    }
    return is;
}
