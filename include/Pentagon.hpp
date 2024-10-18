#ifndef PENTAGON_HPP
#define PENTAGON_HPP

#include "Figure.hpp"
#include "Point.hpp"

class Pentagon : public Figure
{
public:
    Pentagon() = default;
    Pentagon(const Point points[5]);
    Pentagon(const Pentagon& other);
    Pentagon& operator=(const Pentagon &other);
    Pentagon& operator=(Pentagon &&other) noexcept;
    bool operator==(const Figure &other) const override;
    void getInfo() const override;
    Point geometricCenter() const override;
    operator double() const override;

    Figure* clone() const override;

    friend std::ostream &operator<<(std::ostream &os, const Pentagon &pentagon);
    friend std::istream &operator>>(std::istream &is, Pentagon &pentagon);
    
    bool isValidPentagon() const;

private:
    Point points_[5];  
};

#endif // PENTAGON_HPP
