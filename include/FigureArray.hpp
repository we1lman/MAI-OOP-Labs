#ifndef FIGUREARRAY_HPP
#define FIGUREARRAY_HPP

#include "Figure.hpp"

class FigureArray {
private:
    Figure** figures_;
    size_t size_;
    size_t capacity_;

public:
    FigureArray(size_t capacity);
    FigureArray(const FigureArray& other);
    FigureArray& operator=(const FigureArray& other);
    FigureArray(FigureArray&& other) noexcept;
    FigureArray& operator=(FigureArray&& other) noexcept;
    ~FigureArray();

    void addFigure(Figure* figure);
    void removeFigure(size_t index);
    double totalArea() const;
    void printAll() const;
    size_t getSize() const { return size_; }
};

#endif // FIGUREARRAY_HPP
