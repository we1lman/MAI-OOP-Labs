#ifndef PENTAGON_HPP
#define PENTAGON_HPP

#include "Figure.hpp"
#include "Point.hpp"

class Pentagon : public Figure
{
public:
    Pentagon() = default;
    Pentagon(const Point (&points)[5]);
    Pentagon(const Pentagon &other);

    Pentagon& operator=(const Pentagon &other);
    Pentagon& operator=(Pentagon &&other) noexcept;

    Point geometricCenter() const override;
    operator double() const override;
    bool operator==(const Figure &other) const override;

    virtual Figure* clone() const override {
        return new Pentagon(*this);
    }

    void print(std::ostream& os) const override;
    void read(std::istream& is) override;

private:
    Point points_[5];
    
    bool isValidPentagon() const;
};

#endif // PENTAGON_HPP
