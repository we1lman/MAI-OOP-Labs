#ifndef FIGURE_HPP
#define FIGURE_HPP

#include "Point.hpp"
#include <iostream>

class Figure
{
public:
    virtual ~Figure() noexcept = default;

    virtual void getInfo() const = 0;
    virtual operator double() const = 0;
    virtual bool operator==(const Figure &other) const = 0;
    virtual Point geometricCenter() const = 0;
    virtual Figure* clone() const = 0;
};

#endif // FIGURE_HPP
