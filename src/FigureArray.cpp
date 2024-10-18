#include "FigureArray.hpp"
#include <iostream>

FigureArray::FigureArray(size_t capacity)
    : figures_(new Figure*[capacity]), size_(0), capacity_(capacity) {}

FigureArray::FigureArray(const FigureArray& other)
    : figures_(new Figure*[other.capacity_]), size_(other.size_), capacity_(other.capacity_)
{
    for (size_t i = 0; i < size_; ++i) {
        figures_[i] = other.figures_[i]->clone();
    }
}

FigureArray& FigureArray::operator=(const FigureArray& other)
{
    if (this == &other) {
        return *this;
    }

    for (size_t i = 0; i < size_; ++i) {
        delete figures_[i];
    }
    delete[] figures_;

    figures_ = new Figure*[other.capacity_];
    size_ = other.size_;
    capacity_ = other.capacity_;
    for (size_t i = 0; i < size_; ++i) {
        figures_[i] = other.figures_[i]->clone();
    }
    return *this;
}

FigureArray::FigureArray(FigureArray&& other) noexcept
    : figures_(other.figures_), size_(other.size_), capacity_(other.capacity_)
{
    other.figures_ = nullptr;
    other.size_ = 0;
    other.capacity_ = 0;
}

FigureArray& FigureArray::operator=(FigureArray&& other) noexcept
{
    if (this != &other) {
        for (size_t i = 0; i < size_; ++i) {
            delete figures_[i];
        }
        delete[] figures_;

        figures_ = other.figures_;
        size_ = other.size_;
        capacity_ = other.capacity_;

        other.figures_ = nullptr;
        other.size_ = 0;
        other.capacity_ = 0;
    }
    return *this;
}

FigureArray::~FigureArray()
{
    for (size_t i = 0; i < size_; ++i) {
        delete figures_[i];
    }
    delete[] figures_;
}

void FigureArray::addFigure(Figure* figure)
{
    if (size_ >= capacity_) {
        std::cerr << "Array is full." << std::endl;
        return;
    }
    figures_[size_++] = figure;
}

void FigureArray::removeFigure(size_t index)
{
    if (index >= size_) {
        std::cerr << "Invalid index." << std::endl;
        return;
    }
    delete figures_[index];
    for (size_t i = index; i < size_ - 1; ++i) {
        figures_[i] = figures_[i + 1];
    }
    --size_;
}

double FigureArray::totalArea() const
{
    double total = 0.0;
    for (size_t i = 0; i < size_; ++i) {
        total += static_cast<double>(*figures_[i]);
    }
    return total;
}

void FigureArray::printAll() const
{
    for (size_t i = 0; i < size_; ++i) {
        figures_[i]->getInfo();
    }
}
