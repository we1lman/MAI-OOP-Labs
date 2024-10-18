#include <iostream>
#include "Point.hpp"
#include "Trapezoid.hpp"
#include "Pentagon.hpp"
#include "Rhombus.hpp"
#include "FigureArray.hpp"

int main()
{
    Point points_trapezoid[4] = { Point(0, 0), Point(4, 0), Point(3, 2), Point(1, 2) };
    Point points_pentagon[5] = { Point(0, 0), Point(2, 0), Point(3, 1), Point(1.5, 3), Point(0, 1) };
    Point points_rhombus[4] = { Point(0, 0), Point(2, 1), Point(0, 2), Point(-2, 1) };

    Trapezoid trapezoid(points_trapezoid);
    Pentagon pentagon(points_pentagon);
    Rhombus rhombus(points_rhombus);

    std::cout << "Trapezoid Information: " << std::endl;
    trapezoid.getInfo();
    std::cout << "Area: " << static_cast<double>(trapezoid) << std::endl;
    std::cout << "Geometric Center: " << trapezoid.geometricCenter() << std::endl;
    
    std::cout << "\nPentagon Information: " << std::endl;
    pentagon.getInfo();
    std::cout << "Area: " << static_cast<double>(pentagon) << std::endl;
    std::cout << "Geometric Center: " << pentagon.geometricCenter() << std::endl;
    
    std::cout << "\nRhombus Information: " << std::endl;
    rhombus.getInfo();
    std::cout << "Area: " << static_cast<double>(rhombus) << std::endl;
    std::cout << "Geometric Center: " << rhombus.geometricCenter() << std::endl;

    Trapezoid trapezoid2(points_trapezoid);
    if (trapezoid == trapezoid2) {
        std::cout << "\nThe trapezoids are equal!" << std::endl;
    } else {
        std::cout << "\nThe trapezoids are not equal!" << std::endl;
    }

    std::cout << "\nInput a new point (format: x y): ";
    Point p;
    std::cin >> p;
    std::cout << "You entered point: " << p << std::endl;

    FigureArray figures(3);
    figures.addFigure(new Trapezoid(points_trapezoid));
    figures.addFigure(new Pentagon(points_pentagon));
    figures.addFigure(new Rhombus(points_rhombus));

    std::cout << "\nAll figures in array: " << std::endl;
    figures.printAll();
    
    std::cout << "\nTotal area of all figures: " << figures.totalArea() << std::endl;

    figures.removeFigure(1);
    std::cout << "\nFigures after removing the second one: " << std::endl;
    figures.printAll();

    return 0;
}
