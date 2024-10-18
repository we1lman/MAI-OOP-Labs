#ifndef TRAPEZOID_HPP
#define TRAPEZOID_HPP

#include "Figure.hpp"
#include "Point.hpp"

class Trapezoid : public Figure
{
public:
    Trapezoid() = default;
    Trapezoid(const Point points[4]);
    Trapezoid(const Trapezoid& other);
    Trapezoid& operator=(const Trapezoid &other);
    Trapezoid& operator=(Trapezoid &&other) noexcept;

    bool operator==(const Figure &other) const override;
    void getInfo() const override;
    Point geometricCenter() const override;
    operator double() const override;

    Figure* clone() const override {
        return new Trapezoid(*this);
    }

    friend std::ostream &operator<<(std::ostream &os, const Trapezoid &trapezoid);
    friend std::istream &operator>>(std::istream &is, Trapezoid &trapezoid);
    
    bool isValidTrapezoid() const;

private:
    Point points_[4];
};

#endif // TRAPEZOID_HPP
