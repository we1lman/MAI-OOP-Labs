#ifndef RHOMBUS_HPP
#define RHOMBUS_HPP

#include "Figure.hpp"
#include "Point.hpp"

class Rhombus : public Figure
{
public:
    Rhombus() = default;
    Rhombus(const Point points[4]);
    Rhombus(const Rhombus& other);
    
    Rhombus &operator=(const Rhombus &other);
    Rhombus &operator=(Rhombus &&other) noexcept;

    bool operator==(const Figure &other) const override;
    void getInfo() const override;
    Point geometricCenter() const override;
    operator double() const override;

    Figure* clone() const override {
        return new Rhombus(*this);
    }

    friend std::ostream &operator<<(std::ostream &os, const Rhombus &rhombus);
    friend std::istream &operator>>(std::istream &is, Rhombus &rhombus);
    
    bool isValidRhombus() const;

private:
    Point points_[4];
};

#endif // RHOMBUS_HPP
